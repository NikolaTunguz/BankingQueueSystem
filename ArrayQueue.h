/**
 * @ Author: Austin Finch & Nikola Tunguz
 * @ Due Date: March 12, 2023
 * @ Description: A circular array based queue.
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
        ArrayQueue();

        bool isEmpty() const; 
        bool enqueue(const ItemType& newEntry); 
        bool dequeue(); 
        ItemType peekFront() const; 
        ~ArrayQueue();
};

#include "ArrayQueue.cpp"
#endif