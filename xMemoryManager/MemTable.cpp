#include "MemTable.h"

using namespace std;


json MemTable::Table;

template <class type>
LinkedList<type> ListAdapter<type>::SmartList;



int MemTable::getSize(long ID) {
    int size = 0;

    std::string number;
    std::stringstream strstream;
    strstream << ID;
    strstream >> number;

    for (json::iterator it = Table.begin(); it != Table.end(); ++it){
        std::string Key = it.key();
        if(number == Key){
            size = it.value().at(1);
            break;
        }
    }

    return size;
}

void *MemTable::getPosition(long ID) {
    void* ptr = nullptr;

    std::string number;
    std::stringstream strstream;
    strstream << ID;
    strstream >> number;

    for (json::iterator it = Table.begin(); it != Table.end(); ++it){
        std::string Key = it.key();
        if(number == Key){
            intptr_t pointer = it.value().at(0);
            ptr = reinterpret_cast<void*>(pointer);
            break;
        }
    }

    return ptr;
}

void *MemTable::burp(void * destination, void * source, size_t objectSize, std::string ID) {

    memcpy(destination, source, objectSize);
    memset(source, 0, objectSize);

    BurpingTable.erase(ID);
    intptr_t newPointer = (intptr_t) destination;
    BurpingTable[ID] = {newPointer, objectSize};
    void * finalPointer = destination + objectSize;
    return finalPointer;
}

void MemTable::deleteFromTable(long ID) {

    void * voidPointer= getPosition(ID);
    size_t pointerSize = (size_t) getSize(ID);

    Manager.FreeMem(voidPointer, pointerSize);

    std::string number;
    std::stringstream strstream;
    strstream << ID;
    strstream >> number;
    Table.erase(number);

    void * iterPointer = voidPointer;

    BurpingTable = Table;

    for (json::iterator it = Table.begin(); it != Table.end(); ++it) {
        std::string key = it.key();

        size_t tempObjSize = (size_t) it.value().at(1);

        intptr_t tempPointer = it.value().at(0);
        void * burpPointer = reinterpret_cast<void*>(tempPointer);

        if (voidPointer < burpPointer == 1){
            void * newObjectPointer = burp(iterPointer, burpPointer, tempObjSize, key);
            iterPointer = newObjectPointer;
        }

    }
    Manager.setCurrentMem(iterPointer);

    Table = BurpingTable;
    BurpingTable.clear();

    std::cout << "ID: [pointer address, memory size]" << std::endl;
    std::cout << Table <<"\n"<< std::endl;
}


