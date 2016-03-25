//
// Created by disoji on 21/03/16.
//
#pragma once
#ifndef XMEMORY_XMEMORYMANAGER_H
#define XMEMORY_XMEMORYMANAGER_H

#include <cstddef>
#include <iostream>
#include <typeinfo>
#include "../xObject.h"

class xMemoryManager: public xObject  {

    int UsedLocalMem = 0;
    void * AvailableMem;
    void * CurrentMem;

public:
    xMemoryManager();
    int getUsedLocalMem() const {
        return UsedLocalMem;
    }

    void setUsedLocalMem(int UsedLocalMem) {
        xMemoryManager::UsedLocalMem = UsedLocalMem;
    }

    void * RequestMem(size_t MSize);

    char * getClassName(){
        string classname = typeid(this).name();
        if (classname.size()>11){
            classname= classname.substr (3,classname.size()-1);
            return (char*)classname.c_str();
        }else{
            classname = classname.substr(2,classname.size()-1);
            return (char*)classname.c_str();
        }


    }

    void FreeMem(void* ptr);

};



#endif //XMEMORY_XMEMORYMANAGER_H
