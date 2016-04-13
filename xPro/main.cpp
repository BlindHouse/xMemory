//
// Created by disoji on 24/03/16.
//
#include <iostream>
#include <unistd.h>
#include "stdlib.h"
#include "xPro.h"

using namespace std;

int main(){
    cout<<"Proyecto xPro"<<"\n";
    /*
    xLinkedList* list = new xLinkedList();
    list->addNode("gato");
    list->addNode("Perro");
    list->addNode("tortuga");
    list->addNode("pajaro");

    cout<<xPro::writeSerialize(list);
    */

    xPro::parser("/home/disoji/ClionProjects/xMemory/xMemoryManager/xMemoryManager.h"); //Llama al preprocesador.

    //xPro::generatexPointer("Perro");
    //xPro::generatexPointer("Gato");
    //xPro::generatexPointer("Efren_Perra");
    /*
    xLinkedList* list = new xLinkedList();
    cout<<"Before calling and assign of xPro::makeFileList"<<"\n";
    list = xPro::makeFileList("/home/disoji/ClionProjects/xMemory/xMemoryManager/xMemoryManager.h");
    //cout<<"This is ist->firstnode->getTokenList()[2]: "<<*list->firstnode->next->getTokenList()[0]<<"\n";
    int i=0;
    const char * tokenlist = list->firstnode->next->getTokenList();
    for (i; i<sizeof(tokenlist);i++){
        cout<<"This is the token test: "<<tokenlist[0]<<"\n";
    }
    //cout<<"This is the token test: "<<list->firstnode->getTokenList()[0]<<"\n";

    if (list->firstnode->next->getTokenList() == NULL){
        cout<<"shit"<<"\n";
    }else{
        cout<<"WTF!!"<<"\n";
    }*/

}