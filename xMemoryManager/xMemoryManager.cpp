//
// Created by disoji on 21/03/16.
//
#include "xMemoryManager.h"


using namespace std;

int xMemoryManager::UsedLocalMem = 0;
void * xMemoryManager::AvailableMem;
void * xMemoryManager::CurrentMem;

xMemoryManager::xMemoryManager() {
    AvailableMem = malloc(100);
    CurrentMem = AvailableMem;
    memset(AvailableMem, 0, 100);
    std::cout << "Memory has been set at location "<<AvailableMem<<"\n"<< std::endl;

}

void * xMemoryManager::RequestMem(size_t MSize) {

    void *ptr = CurrentMem;
    CurrentMem = CurrentMem + (MSize);
    setUsedLocalMem(getUsedLocalMem() + MSize);
    std::cout << "Current memory pointer location: "<<CurrentMem << std::endl;
    std::cout << "Total used memory is :" << getUsedLocalMem() << "\n" << std::endl;
    return ptr;
}