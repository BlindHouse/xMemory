//
// Created by disoji on 21/03/16.
//
#include "xMemoryManager.h"


using namespace std;

size_t xMemoryManager::UsedLocalMem = 0;
size_t xMemoryManager::AvailableMemSize = 0;
void * xMemoryManager::StartingPointer;
void * xMemoryManager::CurrentMem;

xMemoryManager::xMemoryManager() {
    StartingPointer = malloc(100);
    CurrentMem = StartingPointer;
    memset(StartingPointer, 0, 100);
    setAvailableMemSize(90);
    int memorySize = (int)getAvailableMemSize();
    std::cout << "Memory has been set at location "<<StartingPointer<< " for " << memorySize<< " bytes"<< "\n"<< std::endl;

}

void * xMemoryManager::RequestMem(size_t MSize) {

    void *ptr = CurrentMem;
    CurrentMem = CurrentMem + (MSize);
    setUsedLocalMem(getUsedLocalMem() + MSize);
    int intMemorySize = (int)getUsedLocalMem();
    std::cout << "Current memory pointer location: "<<CurrentMem << std::endl;
    std::cout << "Total used memory is :" << intMemorySize << "\n" << std::endl;
    return ptr;
}

void xMemoryManager::FreeMem(void *ptr, size_t MSize) {

    int printMSize = (int)MSize;

    memset(ptr, 0, MSize);

    setUsedLocalMem(getUsedLocalMem() - MSize);
    std::cout << "There are now " << getUsedLocalMem()<<" bytes of used memory" << std::endl;
    std::cout << "Item at memory address "<< ptr << " of " << printMSize << " bytes of size was erased"<< "\n" << std::endl;

}