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
    MemTable(MemTable const&){};
    void operator=(MemTable const&){};


    static json Table;
    xMemoryManager Manager;

public:
    static const json &getTable() {
        return Table;
    }

    template <class type>
    type * allocateToTable(long ID, type obj){

        size_t MSize = sizeof(obj);
        type * ptr = Manager.addItem(obj);

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
        std::cout << "ID: [pointer address, memory size]" << std::endl;
        std::cout << Table <<"\n"<< std::endl;
    };
    void* getPosition(long ID);
    int getSize(long ID);

};

#endif //XMEMORY_MEMTABLE_H