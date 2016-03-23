//
// Created by disoji on 21/03/16.
//

#include <stdlib.h>
#include "xMemoryManager.h"


xMemoryManager::xMemoryManager(){
    this->AviableMem = calloc(8,0);
};

void* xMemoryManager::xMalloc(int MSize){
    void* newptr;
    newptr = AviableMem;
    AviableMem = AviableMem + MSize;
    return newptr;
};

xMemoryManager::~xMemoryManager(){ };