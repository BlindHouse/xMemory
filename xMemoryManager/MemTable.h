#pragma once
#ifndef XMEMORY_MEMTABLE_H
#define XMEMORY_MEMTABLE_H
#include "../json.hpp"
#include "xMemoryManager.h"
#include <sstream>

using json = nlohmann::json;

class MemTable{

    /*Function for a singlton*/
public:
    static MemTable& getInstance(){
        static MemTable instance;
        return instance;
    }

public:
    MemTable(){};
    MemTable(MemTable const&){};
    void operator=(MemTable const&){};


    static json Table;
    xMemoryManager Manager;

public:
    /* This function returns a json with the table order for the stored memory*/
    static const json &getTable() {
        return Table;
    }

    /* This function receives the ID of an object to be inserted into the memory space
     * available and the object itself, it allocates the object properly and returns a
     * pointer to that object.*/
    template <class type>
    type * allocateToTable(long ID, type obj){



        size_t MSize = sizeof(obj);

        type * ptr = Manager.addItem(obj, MSize);

        intptr_t pointer = (intptr_t) ptr;

        std::string number;
        std::stringstream strstream;
        strstream << ID;
        strstream >> number;

        Table[number] = {pointer, MSize};
        std::cout << "ID: [pointer address, memory size]" << std::endl;
        std::cout << Table <<"\n"<< std::endl;

        return ptr;
    };

    /* This function receives the ID of the object that wants to be eliminated
     * and a pointer of the object type, it then removes the object from the available memory
     * and performs the necessary burping to organize the available items*/
    template <class type>
    void deleteFromTable(long ID, type* obj) {

        void * voidPointer= getPosition(ID);
        type * ptr = (type*)voidPointer;
        Manager.FreeMem(ptr);
        std::string number;
        std::stringstream strstream;
        strstream << ID;
        strstream >> number;
        Table.erase(number);

        void * iterPointer = voidPointer;

        for (json::iterator it = Table.begin(); it != Table.end(); ++it) {
            std::string key = it.key();

            size_t tempObjSize = (size_t) it.value().at(1);

            intptr_t tempPointer = it.value().at(0);
            void * burpPointer = reinterpret_cast<void*>(tempPointer);

            if (voidPointer < burpPointer == 1){
                burp(iterPointer, burpPointer, tempObjSize, key);
                iterPointer = burpPointer;
            }

        }
        Manager.setCurrentMem(iterPointer);

        std::cout << "ID: [pointer address, memory size]" << std::endl;
        std::cout << Table <<"\n"<< std::endl;
    };

    /*This function does the necessary burping and table organization when and object is deleted,
     * it moves the object at the received source of the specified size and ID to the entered destination*/
    void * burp(void * destination, void * source, size_t objectSize, std::string ID);

    /*Receives the ID for an object and returns its pointer position as a void*/
    void* getPosition(long ID);

    /*Receives the ID for an object and returns its byte size in memory as an int*/
    int getSize(long ID);

};

#endif //XMEMORY_MEMTABLE_H