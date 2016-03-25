#pragma once

#ifndef MEMTABLE_H
#define MEMTABLE_H

#include "../json.hpp"
#include "xMemoryManager.h"
#include <sstream>

using json = nlohmann::json;


class MemTable {

    json Table;
    xMemoryManager Manager;

public:
    void AddToTable(long ID, int MSize);
};

#endif /* MEMTABLE_H */