#pragma once

#define DEBUG false

template <class T>
class Node
{
public:
    Node();
    Node(T value);
    ~Node();

    T data;
    Node* next;
    Node* previous;
};

//#include "Node.h"

template <class T>
Node<T>::Node()
{
    this->next = nullptr;
    this->previous = nullptr;
}

template <class T>
Node<T>::Node(T value)
{
    this->data = value;
    this->next = nullptr;
    this->previous = nullptr;
}

template <class T>
Node<T>::~Node()
{
    //delete this->data; //not required?
}