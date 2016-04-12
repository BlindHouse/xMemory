//
// Created by disoji on 21/03/16.
//

#include "xMemoryManager.h"

using namespace std;

int xMemoryManager::UsedLocalMem = 0;
void * xMemoryManager::AvailableMem;
void * xMemoryManager::CurrentMem;

xMemoryManager::xMemoryManager() {
    AvailableMem = malloc(512);
    CurrentMem = AvailableMem;

}

void * xMemoryManager::RequestMem(size_t MSize) {

    void *ptr = CurrentMem;
    CurrentMem = CurrentMem + MSize;
    setUsedLocalMem(getUsedLocalMem() + MSize);
    std::cout << "Total used memory is :" << getUsedLocalMem() << "\n" << std::endl;
    return ptr;
}




