/*
Author: Nikola Tunguz & <REDACTED>
Purpose: A templated circular array based queue.
*/
#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE 

#include "QueueInterface.h"
#define DEFAULT_MAX 100

template<class ItemType> 
class ArrayQueue : public QueueInterface<ItemType> { 
    ItemType* queue;
    int front, back, size;

    public: 
        //constructor and destructor
        ArrayQueue();
        ~ArrayQueue();

        //queue behavior functions
        bool isEmpty() const; 
        bool enqueue(const ItemType& newEntry); 
        bool dequeue(); 
        ItemType peekFront() const; 
};

#include "ArrayQueue.cpp"
#endif