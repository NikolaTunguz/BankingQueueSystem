/*
Author: Nikola Tunguz & <REDACTED>
Purpose: Templated circular array based queue implementations.
*/

//constructor
template<class ItemType> 
ArrayQueue<ItemType>::ArrayQueue()
{
    queue = new ItemType[100];
    front = 0;
    back = 0;
    size = 0;
}


//checks if queue is empty
template<class ItemType> 
bool ArrayQueue<ItemType>::isEmpty() const
{
	return (size == 0);
}

//adds items to the queue
template<class ItemType> 
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    if (size == DEFAULT_MAX)
    {
        return false;
    }

    queue[back] = newEntry;
    size++;

    if (back == DEFAULT_MAX)
    {
        back = 0;
    }
    else
    {
        back++;
    }
    return true;
}

//removes items from the queue
template<class ItemType> 
bool ArrayQueue<ItemType>::dequeue()
{
    if (size == 0)
    {
        return false;
    }

    if (front == DEFAULT_MAX)
    {
        front = 0;
    }
    else
    {
        front++;
    }

	size--;
    return true;
}

//looks at an item from the front of the queue
template<class ItemType> 
ItemType ArrayQueue<ItemType>::peekFront() const
{
	return queue[front];
}

//destructor
template<class ItemType> 
ArrayQueue<ItemType>::~ArrayQueue()
{
	while(!isEmpty())
    {
        dequeue();
    }
}

