//
// Created by disoji on 21/03/16.
//
#pragma once
#ifndef XMEMORY_XMEMORYMANAGER_H
#define XMEMORY_XMEMORYMANAGER_H

#include <cstddef>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cstring>
#include <string>
#include <memory>

class xMemoryManager{

    /*Function for a singleton*/
public:
    static xMemoryManager& getInstance(){
        static xMemoryManager instance;
        return instance;
    }

public:
    xMemoryManager();
    xMemoryManager(xMemoryManager const&){};
    void operator=(xMemoryManager const&){};


    /*UsedLocalMem represents the memory in bytes taken up by items set in the memory manager*/
    static size_t UsedLocalMem;

    /*AvailableMemSize represents the total memory available to be used by items*/
    static size_t AvailableMemSize;

    /*StartingPointer is a void pointer with the position to the start of the memory manager's available space*/
    static void * StartingPointer;

    /*CurrentMem is a void pointer which represents the location at which a new item can be added*/
    static void * CurrentMem;

public:

    static size_t getAvailableMemSize() {
        return AvailableMemSize;
    }

    static void setAvailableMemSize(size_t AvailableMemSize) {
        xMemoryManager::AvailableMemSize = AvailableMemSize;
    }

    static void *getCurrentMem() {
        return CurrentMem;
    }
    static void setCurrentMem(void *CurrentMem) {
        xMemoryManager::CurrentMem = CurrentMem;
    }

    size_t getUsedLocalMem() const {
        return UsedLocalMem;
    }
    void setUsedLocalMem(size_t UsedLocalMem) {
        xMemoryManager::UsedLocalMem = UsedLocalMem;
    }

    /*Receives a byte size and allocates that amount of space for an object to be placed in the memory manager,
     * it returns a pointer to the initial position of the allocated space*/
    void * RequestMem(size_t MSize);

    /*Receives and object and its size and correctly adds it to the memory manager available memory*/
    template <class type>
    type * addItem(type obj, size_t objectSize) {

        void * initialPointer = RequestMem(objectSize);
        void * localPointer = malloc(objectSize);

        type *setterPointer = new(localPointer) type;
        *setterPointer = obj;

        memmove(initialPointer, localPointer, objectSize);
        type * allocatePointer = reinterpret_cast<type*>(initialPointer);

        return allocatePointer;

    };

    /* Receives the pointer for a specific object and sets its memory to 0's */

    void FreeMem(void * ptr, size_t MSize);

};



#endif //XMEMORY_XMEMORYMANAGER_H
