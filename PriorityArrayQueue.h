/*
Author: Nikola Tunguz & <REDACTED>
Purpose: Templated priority array based queue.
*/
#ifndef PRIORTIY_ARRAY_QUEUE
#define PRIORITY_ARRAY_QUEUE 

#include "ArrayQueue.h"

template<class ItemType> 
class PriorityArrayQueue : public ArrayQueue<ItemType> { 
    ItemType* queue;
    int front, back, size;

    public: 
        //constructor and destructor
        PriorityArrayQueue();
        ~PriorityArrayQueue();

        //basic queue functionality
        bool isEmpty() const; 
        bool enqueue(const ItemType& newEntry); 
        bool dequeue();                        
        ItemType peekFront() const; 
};

#include "PriorityArrayQueue.cpp"
#endif