//
// Created by disoji on 23/03/16.
//

#ifndef XMEMORY_TOOLS_H
#define XMEMORY_TOOLS_H

#include "string.h"
#include <cstring>
#include <sstream>
#include <iostream>
#include "stdlib.h"
/*Recordar: Hay que hacer que se pueda copiar la memoria y poder manipularla ya que nos estaba dando error de segmentation fault
 * Probar poniendo tódo como const char** a ver si así se puede manipular la memoria copiada, si no es mejor modular cada funcion del
 * preprocesador y ejecutarla por linea.*/
using namespace std;

class xLnode{
public:
    xLnode(string stringNode);
    xLnode* next;
    xLnode* prev;
    string NodeString;

};

class xLinkedList{
public:
    int size;
    string xclassname;
    xLinkedList();
    xLnode* firstnode;
    xLnode* lastnode;
    void addNode(string stringToAdd);
    int getSize();

};


#endif //XMEMORY_TOOLS_H
