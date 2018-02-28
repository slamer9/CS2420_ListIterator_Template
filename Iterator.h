#pragma once
#include <cassert>
#include "Node.h"

template <class T>
class Iterator
{
public:
    Iterator(Node<T>* start);  //initially points to start
    ~Iterator();
    T operator*();          //dereference iteratorr
    void operator++();      //Advance iterator
    bool operator!=(Iterator& other)    //returns true only if other iterator != this iterator;
    {
        if(this->at != other.at)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_item();         //Returns true if iterator points to valid node (nullptr == false)
private:
    Node<T>* at;
};

//#include "Iterator.h"

template <class T>
Iterator<T>::Iterator(Node<T>* start)
{
    this->at = start;
}

template <class T>
Iterator<T>::~Iterator()   //FIXME
{
}

template <class T>
T Iterator<T>::operator*()
{
    return this->at->data;
}

template <class T>
void Iterator<T>::operator++()
{
    this->at = this->at->next;
}

// bool Iterator::operator!=(Iterator& other);//Why does this not work here
// {
    
// }

template <class T>
bool Iterator<T>::is_item()
{
    if(this->at == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}