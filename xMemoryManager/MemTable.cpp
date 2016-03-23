#include "MemTable.h"

using namespace std;

using json = nlohmann::json;


void * MemTable::AddToTable(int MSize) {
    void * ptr = Manager.RequestMem(MSize);
    Table.push_back(MSize);
    std::cout << Table << std::endl;
    return ptr;


}

