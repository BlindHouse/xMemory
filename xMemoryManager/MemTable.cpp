#include "MemTable.h"

using namespace std;



void MemTable::AddToTable(long ID, int MSize) {
    void * ptr = Manager.RequestMem(MSize);

    std::stringstream ss;
    ss << ptr;
    std::string pointer = ss.str();

    std::string number;
    std::stringstream strstream;
    strstream << ID;
    strstream >> number;

    Table[number] = pointer;
    std::cout << "ID: pointer address" << std::endl;
    std::cout << std::setw(4) << Table << std::endl;
}

