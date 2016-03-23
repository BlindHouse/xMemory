//
// Created by disoji on 21/03/16.
//

#include "xMemoryManager.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void * xMemoryManager::RequestMem(size_t n) {

    void * ptr = malloc(n);
    if (ptr == NULL)
    {
        std::cout <<"Could not allocate memory\n"<< std::endl;
        exit(-1);
    }
    else
        std::cout <<"Memory allocated successfully.\n"<< std::endl;
    setUsedLocalMem(getUsedLocalMem()+ n);
    std::cout <<getUsedLocalMem()<< std::endl;
    return ptr;
}

void xMemoryManager::FreeMem(void* ptr) {

    int temp = sizeof(ptr);
    setUsedLocalMem(getUsedLocalMem()- temp);
    std::cout <<getUsedLocalMem()<< std::endl;
    free(ptr);
    std::cout <<"Free successful"<< std::endl;
}