/*
* LinkedLIst.cpp
*
* Created on:  Mach 26, 2016
* Author: Efren Carvajal
*/

#include "MemLinkedList.h"


using namespace std;


//Set all nodes to null
/*void LinkedList::KillList(){
    int a = 0;
    int b = getLength();
    ListNode *temp = FirstNode;
    for(int i=0; i < b;i++){
        a++;
        temp = temp->Next;
        (temp->Prev)->Next = NULL;
        (temp->Prev)->Prev = NULL;
    }
    a++;
    LastNode->Next = NULL;
    LastNode->Prev = NULL;
    cout<<"delete "<<a<<" nodes"<<endl;
}*/

//Function for print all nodes of the list
template <class type>
void LinkedList<type>::PrintList() {
    ListNode<type>* temp = FirstNode->Next;
    while(temp->Next != FirstNode){
        cout<<"ID #"<<temp->ID<<endl;
        temp = temp->Next;
    }
}
//Return the list length
template <class type>
int LinkedList<type>::getLength() {
    return length;
}