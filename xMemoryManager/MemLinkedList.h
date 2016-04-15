/*
 * LinkedList.h
 *
 *  Created on: March 26, 2016
 *      Author: Efren Carvajal
 */
#pragma once
#ifndef XMEMORY_LINKEDLIST_H
#define XMEMORY_LINKEDLIST_H
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <memory>


/*Struct ListNode
 * Autor:Efrén Carvajal
 * Members: ListNode* Next, ListNode* Prev,  int socket, int ID,
 */

template <class type>
struct ListNode
{
    ListNode *Next;
    ListNode *Prev;
    type cSocket;
    int ID;

};

template <class type>
class LinkedList
{
public:

    LinkedList(){
        FirstNode->Next = LastNode;
        FirstNode->Prev = LastNode;
        LastNode->Prev = FirstNode;
        LastNode->Next = FirstNode;
    };
    ~LinkedList(){};
    /*insert
     * Autor:Efrén Carvajal
     * args: int tSocket, int tID
     * out: void
     */

    void insert(type tSocket,int tID){
        length++;
        ListNode<type>* newNode = new ListNode<type>;
        newNode->cSocket = tSocket;
        newNode->ID = tID;
        newNode->Prev = (LastNode->Prev);
        newNode->Next = LastNode;
        (LastNode->Prev)->Next = newNode;
        LastNode->Prev=newNode;

    };

    /*remove
     * Autor: Efren Carvajal
     * args: char ID
     * out: void
     */
    void remove(int ID);

    /*killList
     * Autor:Efrén Carvajal
     * args: none
     * out: void
     */
    void KillList();

    /*Search
     * Autor: Efrén Carvajal
     * args: int ID
     * out: int socket
     */

    type Search(int ID){
        ListNode<type> *temp = FirstNode->Next;
        while(temp->Next != FirstNode) {
            if(temp->ID == ID){
                return temp->cSocket;
            }
            temp = temp->Next;
        }
        std::cout << "No Node " << ID << " in list.\n";
    };

    /*PrintList
     * Autor: Efrén Carvajal
     * args:
     * out: void
     */
    void PrintList();

    /*GetLength
    * Autor: Efrén Carvajal
    * args:
    * out: int length
    */
    int getLength();

private:
    int length;
    ListNode<type>* FirstNode = new ListNode<type>;
    ListNode<type>* LastNode = new ListNode<type>;
};


#endif //XMEMORY_LINKEDLIST_H
