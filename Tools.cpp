//
// Created by disoji on 23/03/16.
//

#include "Tools.h"

xLinkedList::xLinkedList() {
    this->firstnode = NULL;
    this->lastnode = NULL;
    this->size = 0;
    this->xclassname = "";
}

xLnode::xLnode(string NodeString) {
    this->NodeString = NodeString;
    this->next = NULL;
    this->prev = NULL;
}

void xLinkedList::addNode(string StringToAdd) {
    //cout<<"Before first node comprobation";
    if (this->firstnode == NULL){
        xLnode* tempNode = new xLnode(StringToAdd);
        this->firstnode = tempNode;
        this->lastnode = this->firstnode;
        this->size ++;
        //cout<<"After the asignation"<<"\n";
    }else{
        xLnode* tempNode = new xLnode(StringToAdd);
        this->lastnode->next = tempNode;
        this->lastnode = tempNode;
        this->size ++;
        }
    }


int xLinkedList::getSize() {
    xLnode* temp = this->firstnode;
    int cont = 0;
    for (temp; temp!=NULL; temp = temp->next){
        cont++;
    }
    return cont;
}