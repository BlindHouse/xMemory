//
// Created by disoji on 24/03/16.
//
#include <iostream>
#include "stdlib.h"
#include "xPro.h"

using namespace std;

int main(){
    cout<<"Proyecto xPro"<<"\n";
    xPro::parser("/home/disoji/ClionProjects/xMemory/xMemoryManager/xMemoryManager.h");//Llama al preprocesador.
}