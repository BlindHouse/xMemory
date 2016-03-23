//
// Created by disoji on 21/03/16.
//

#ifndef XMEMORY_XMEMORYMANAGER_H
#define XMEMORY_XMEMORYMANAGER_H
#include <iostream>
#include <typeinfo>
#include "../xObject.h"

using namespace std;

class xMemoryManager: public xObject {
    public:
        xMemoryManager();
        ~xMemoryManager();
        void* AviableMem;
        void* xCalloc(int Msize);
        void* xMalloc(int Msize);

    /*char* getClassName(){
        string classname = typeid(this).name();
        if (classname.size()>11){
            classname= classname.substr (3,classname.size()-1);
            return (char*)classname.c_str();
        }else{
            classname = classname.substr(2,classname.size()-1);
            return (char*)classname.c_str();
        }


    }*/
    
};



#endif //XMEMORY_XMEMORYMANAGER_H
