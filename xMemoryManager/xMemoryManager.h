//
// Created by disoji on 21/03/16.
//
#pragma once
#ifndef XMEMORY_XMEMORYMANAGER_H
#define XMEMORY_XMEMORYMANAGER_H

#include <cstddef>
#include <iostream>
#include <typeinfo>
#include <cstring>

class xMemoryManager{
public:
    static xMemoryManager& getInstance(){
        static xMemoryManager instance;
        return instance;
    }

public:
    xMemoryManager();
    xMemoryManager(xMemoryManager const&){};
    void operator=(xMemoryManager const&){};


    static int UsedLocalMem;
    static void * AvailableMem;
    static void * CurrentMem;

public:
    int getUsedLocalMem() const {
        return UsedLocalMem;
    }

    void setUsedLocalMem(int UsedLocalMem) {
        xMemoryManager::UsedLocalMem = UsedLocalMem;
    }

    void * RequestMem(size_t MSize);

    template <class type>
    type * addItem(type obj) {

        size_t objectSize = sizeof(obj);
        void * initialPointer = RequestMem(objectSize);
        type * ptr = (type*)malloc(objectSize);
        *ptr = obj;
        memmove(initialPointer, ptr, objectSize);
        type * allocatePointer = (type*)initialPointer;
        return allocatePointer;

        /*       size_t objectSize = sizeof(obj);
               void * initialPointer = RequestMem(objectSize);
               type * allocatePointer = (type*)initialPointer;
               *allocatePointer = obj;
               return allocatePointer;*/
    };

    template <class type>
    void FreeMem(type * ptr){

        size_t MSize = sizeof(*ptr);

        memset(ptr, 0, MSize);

        setUsedLocalMem(getUsedLocalMem() - MSize);
        std::cout << "There are now " << getUsedLocalMem()<<" bytes of used memory" << std::endl;
        std::cout << ptr<< ": "<<*ptr << std::endl;


    };

};



#endif //XMEMORY_XMEMORYMANAGER_H