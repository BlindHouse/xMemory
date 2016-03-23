//
// Created by disoji on 21/03/16.
//

#ifndef XMEMORY_XMEMORYMANAGER_H
#define XMEMORY_XMEMORYMANAGER_H


#include <cstddef>

class xMemoryManager  {

    int UsedLocalMem = 0;

public:
    int getUsedLocalMem() const {
        return UsedLocalMem;
    }

    void setUsedLocalMem(int UsedLocalMem) {
        xMemoryManager::UsedLocalMem = UsedLocalMem;
    }

public:
    void * RequestMem(size_t n);

public:
    void FreeMem(void* ptr);

};


#endif //XMEMORY_XMEMORYMANAGER_H
