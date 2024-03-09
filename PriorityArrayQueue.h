/**
 * @ Author: Austin Finch & Nikola Tunguz
 * @ Due Date: March 12, 2023
 * @ Description: A circular array based priority queue that stores items in a queue by order of priority.
 */
#ifndef PRIORTIY_ARRAY_QUEUE
#define PRIORITY_ARRAY_QUEUE 

#include "ArrayQueue.h"

template<class ItemType> 
class PriorityArrayQueue : public ArrayQueue<ItemType> { 
    ItemType* queue;
    int front, back, size;

    public: 
        PriorityArrayQueue();

        bool isEmpty() const; 
        bool enqueue(const ItemType& newEntry); 
        bool dequeue();                        
        ItemType peekFront() const; 
        ~PriorityArrayQueue();
};

#include "PriorityArrayQueue.cpp"
#endif