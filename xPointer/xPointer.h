#pragma once

#include "MemTable.h"

template <class t>
class xPointer{

    long ObjectID;
    void * InitialPosition;
    void * CurrentPosition;
    int Size;

public:
    xPointer(long ID);
    int add(t item);

};