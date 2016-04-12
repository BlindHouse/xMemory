#include "MemTable.h"

using namespace std;


json MemTable::Table;

int MemTable::getSize(long ID) {
    int size;

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
    void* ptr;

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

void * MemTable::getCurrent(long ID) {
    void* ptr;

    std::string number;
    std::stringstream strstream;
    strstream << ID;
    strstream >> number;

    for (json::iterator it = Table.begin(); it != Table.end(); ++it){
        std::string Key = it.key();
        if(number == Key){
            intptr_t pointer = it.value().at(2);
            ptr = reinterpret_cast<void*>(pointer);
            break;
        }
    }

    return ptr;
}

