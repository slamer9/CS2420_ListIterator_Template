#pragma once
#include <iostream>
#include <cassert>
#include "Iterator.h"

#include <iomanip>

using namespace std;


template <class T>
class List
{
public:
    List();
    ~List();
    void push_front(const T& value);
    void push_back(const T& value);
    void remove(const T& value);    //Removes all nodes in list with this value
    Iterator<T> begin();//Iterator to beginnig of list
    Iterator<T> end(); //Iterator to end of list
    unsigned int size();     //Num elements in list
    void PrintList();   //Debugging

private:
    unsigned int listSize;
    Node<T>* head;
    Node<T>* tail;
};

//#include "List.h"

template <class T>
List<T>::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
}

template <class T>
List<T>::~List()    //Free memory
{
    Node<T>* temp;
    while(this->head != nullptr)
    {
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

template <class T>
void List<T>::push_front(const T& value)
{
    Node<T>* temp = new Node<T>(value);
    temp->next = this->head;
    if(this->head != nullptr)
    {
        this->head->previous = temp;
        this->head = temp;
    }
    else
    {
        this->head = temp;
        this->tail = this->head;
    }
    this->listSize++;
}

template <class T>
void List<T>::push_back(const T& value)
{
    if(this->head == nullptr)
    {
        this->head = new Node<T>(value);
        this->tail = this->head;
        this->listSize++;
        return;
    }
    //Node<T>* temp = this->head;
    // while(temp->next != nullptr) //I have a tail member, this is not very efficient
    // {
    //     if(DEBUG)
    //     {
    //         if(temp == nullptr)
    //         {
    //             cout << "You messed up" << endl;    //do something more usefull if we use this again
    //         }
    //         //cout << temp->next->data << endl;
    //     }
    //     temp = temp->next;
    // }

    this->tail->next = new Node<T>(value);
    this->tail->next->previous = this->tail;

    this->tail = this->tail->next;  //Move tail ptr

    this->listSize++;
    return;
}

template <class T>
void List<T>::remove(const T& value)     //FIXME
{
    Node<T>* check = this->head;
    while(check != nullptr)
    {
        if(check->data == value)
        {
            if(this->head == check)                     //change links
            {                                           //
                this->head = check->next;               //
            }                                           //
            if(this->tail == check)                     //
            {                                           //
                this->tail = check->previous;           //
            }                                           //
            if(check->next != nullptr)                  //
            {                                           //
                check->next->previous = check->previous;//
            }                                           //
            if(check->previous != nullptr)              //
            {                                           //
                check->previous->next = check->next;    //
            } 

            Node<T>* temp = check;                      //Take care of node
            check = check->next;                        //
            delete temp;                                //

            this->listSize--;                           //decrement size
        }
        else
        {
            check = check->next;
        }
    }
}

template <class T>
Iterator<T> List<T>::begin()
{
    return Iterator<T>(this->head);
}

template <class T>
Iterator<T> List<T>::end()
{
    return Iterator<T>(nullptr);    //Because apparently this is how they do it!? Seems useless to me
}

template <class T>
unsigned int List<T>::size()
{
    return this->listSize;
}

template <class T>
void List<T>::PrintList()   //Not how I would have displayed it, but this is what the example had, just btw
{
    Node<T>* temp = this->head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}