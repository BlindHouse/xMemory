#pragma once

#ifndef MEMTABLE_H
#define MEMTABLE_H

#include "json.hpp"
#include "xMemoryManager.h"

using json = nlohmann::json;


class MemTable {

    json Table;
    xMemoryManager Manager;

public:
    void * AddToTable(int MSize);

};

#endif /* MEMTABLE_H */