//
// Created by disoji on 21/03/16.
//

#ifndef XMEMORY_XMEMORYMANAGER_H
#define XMEMORY_XMEMORYMANAGER_H

class xMemoryManager {
public:
    xMemoryManager();
    ~xMemoryManager();

    void* AviableMem;

    void* xCalloc(int Msize);
    void* xMalloc(int Msize);


    
};


#endif //XMEMORY_XMEMORYMANAGER_H
