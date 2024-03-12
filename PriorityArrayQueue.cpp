/*
Author: Nikola Tunguz & <REDACTED>
Purpose: Templated priority array based queue.
*/

//constructor
template <class ItemType>
PriorityArrayQueue<ItemType>::PriorityArrayQueue(){
    queue = new ItemType[100];
    front = 0;
    back = 0;
    size = 0;
}

//destructor
template <class ItemType>
PriorityArrayQueue<ItemType>::~PriorityArrayQueue(){
    while( size != 0){
        dequeue();
    }
}

//adding elements to the queue
template<class ItemType> 
bool PriorityArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    bool queueable = (size < DEFAULT_MAX);
    if(queueable){
        //if empty place at front
        if(size == 0){
            queue[front] = newEntry;
            size = size + 1;
            return true;
        }
        else{  
            //places position at the end of queue
            if(queue[back] < newEntry){
                size++;
                back = (back + 1) % DEFAULT_MAX;
                queue[back] = newEntry;
                return true;
            }
            
            //find its insertion position in the middle
            int insertionIndex = back;
            for( int i = 0; i < size; i++){
                int currentIndex = abs((insertionIndex - i)) % DEFAULT_MAX;

                bool currentHigher = newEntry < queue[currentIndex];
                bool previousHigher = queue[currentIndex - 1] < newEntry;
                bool equal = !( newEntry < queue[currentIndex] || queue[currentIndex] < newEntry);

                if( ( currentHigher && previousHigher ) || equal  ){
                    insertionIndex = currentIndex;
                }
            }

            //shift all elements after the position
            ItemType currentPosition = queue[insertionIndex];
            queue[insertionIndex] = newEntry;
            for(int i = 1;  i < size; i++){
                ItemType temp = queue[(insertionIndex + i) % DEFAULT_MAX];
                queue[(insertionIndex + i) % DEFAULT_MAX] = currentPosition;
                currentPosition = temp;
            }

            size++;
            back = (back + 1) % DEFAULT_MAX;
            return true;

        }
    }
    return false;
}

//removing elements
template <class ItemType>
bool PriorityArrayQueue<ItemType>::dequeue(){
    bool dequeueable = size > 0;
    if(dequeueable){
        queue[front] = ItemType();
        front = (front + 1) % DEFAULT_MAX;
        size--;
        return true;
    }
    return false;
}

//checks if empty
template <class ItemType>
bool PriorityArrayQueue<ItemType>::isEmpty() const{
    return (size == 0);
}

//gets item at front of queue
template <class ItemType>
ItemType PriorityArrayQueue<ItemType>::peekFront() const{
    return queue[front];
}