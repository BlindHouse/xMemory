//
// Created by disoji on 21/03/16.
//

#include "xMemoryManager.h"

using namespace std;

xMemoryManager::xMemoryManager() {
    this->AvailableMem = malloc(64);
    CurrentMem = AvailableMem;
    classname = typeid(*this).name();
    std::cout << "Temp dentro del contructor:--" << classname << "\n";

}

void * xMemoryManager::RequestMem(size_t MSize) {

    void * ptr = CurrentMem;
    CurrentMem = CurrentMem + MSize;
    setUsedLocalMem(getUsedLocalMem() + MSize);
    std::cout << "Total used memory is :" << getUsedLocalMem()<< "\n" << std::endl;
    return ptr;
}

void xMemoryManager::FreeMem(void* ptr) {

    int temp = sizeof(ptr);
    setUsedLocalMem(getUsedLocalMem() - temp);
    std::cout << getUsedLocalMem() << std::endl;
    free(ptr);
    std::cout << "Free successful" << std::endl;
}



