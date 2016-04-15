#pragma once
#ifndef XMEMORY_MEMTABLE_H
#define XMEMORY_MEMTABLE_H
#include "../json.hpp"
#include "xMemoryManager.h"
#include <sstream>
#include "MemLinkedList.h"

using namespace std;

using json = nlohmann::json;

template <class type>
class ListAdapter{

    static LinkedList<type> SmartList;

public:

    ListAdapter(type smartPointer, long ID){

        int result = (int)ID;
        SmartList.insert(smartPointer, result);
    };
};



class MemTable{

    /*Function for a singleton*/
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
    json BurpingTable;
    xMemoryManager Manager;

public:
    virtual ~MemTable() {};
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

        if (ptr == nullptr){

            return nullptr;
        }

        else {
            intptr_t pointer = (intptr_t) ptr;

            std::string number;
            std::stringstream strstream;
            strstream << ID;
            strstream >> number;

            Table[number] = {pointer, MSize};
            std::cout << "ID: [pointer address, memory size]" << std::endl;
            std::cout << Table << "\n" << std::endl;

            return ptr;
        }
    };

    /* This function receives the ID of the object that wants to be eliminated
     * and a pointer of the object type, it then removes the object from the available memory
     * and performs the necessary burping to organize the available items*/

    void deleteFromTable(long ID);

    /*This function does the necessary burping and table organization when and object is deleted,
     * it moves the object at the received source of the specified size and ID to the entered destination*/
    void * burp(void * destination, void * source, size_t objectSize, std::string ID);

    /*Receives the ID for an object and returns its pointer position as a void*/
    void* getPosition(long ID);

    /*Receives the ID for an object and returns its byte size in memory as an int*/
    int getSize(long ID);

    template<class type>
    void xGarTracking(type * obj, long ID){
        std::shared_ptr<type> smartPointer;
        smartPointer = std::make_shared<type>(*obj);
        ListAdapter<shared_ptr<type>> pointerList(smartPointer, ID);
    };

};

#endif //XMEMORY_MEMTABLE_H