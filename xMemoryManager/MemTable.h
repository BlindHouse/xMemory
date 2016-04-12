#pragma once
#ifndef XMEMORY_MEMTABLE_H
#define XMEMORY_MEMTABLE_H
#include "../json.hpp"
#include "xMemoryManager.h"
#include <sstream>

using json = nlohmann::json;

class MemTable{

public:
    static MemTable& getInstance(){
        static MemTable instance;
        return instance;
    }

public:
    MemTable(){};
    MemTable(MemTable const& copy){};
    void operator=(MemTable const& copy){};


    static json Table;
    xMemoryManager Manager;

public:
    static const json &getTable() {
        return Table;
    }

    template <class type>
    type * allocateToTable(long ID, type obj){

        int MSize = sizeof(obj);
        void * ptr = Manager.RequestMem(MSize);
        type * finalptr= (type*)ptr;

        intptr_t pointer = (intptr_t) ptr;

        std::string number;
        std::stringstream strstream;
        strstream << ID;
        strstream >> number;

        Table[number] = {pointer, MSize};
        std::cout << "ID: pointer address" << std::endl;
        std::cout << Table << std::endl;
        * finalptr = obj;

        return finalptr;
    };

    template <class type>
    void deleteFromTable(long ID, type* obj) {

        type * ptr = (type*)getPosition(ID);
        Manager.FreeMem(ptr);

        std::string number;
        std::stringstream strstream;
        strstream << ID;
        strstream >> number;

        Table.erase(number);
    };
    void* getPosition(long ID);
    void* getCurrent(long ID);
    int getSize(long ID);

};

#endif //XMEMORY_MEMTABLE_H