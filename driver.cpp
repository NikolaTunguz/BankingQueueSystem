/**
 * @ Author: Austin Finch & Nikola Tunguz
 * @ Due Date: March 12, 2023
 * @ Description: A bank line simulation that takes input from a text file and is ordered in a priority queue.
 */
#include <iostream>
#include <fstream>

#include "PriorityArrayQueue.h"
#include "Event.h"
using namespace std;


void outputStatistics(float totalWaitTime, float numCustomers); 
bool readEvent(PriorityArrayQueue<Event>& queue);
bool addEvent(int arrivalTime, int departureTime, PriorityArrayQueue<Event>& queue); 


int main(int argc, char const *argv[])
{
    ifstream file;
    PriorityArrayQueue<Event> bankLine = PriorityArrayQueue<Event>();


    if (!argv[1])
    {
        cout << "Please provide a input file as a command line argument" << endl;
        return 0;
    }
    else
    {
        try
        {
            file.open(argv[1]);
        }
        catch(const exception& e)
        {
            cout << "Please provide a valid input file" << endl;
            return 0;
        }
        
    }

    //reads from file and adds to priority queue
    float totalWaitTime, numCustomers;
    int arrivalTime, procedureTime, waitTime, departureTime, previousDepartureTime;
    if(file.is_open()){
        while(file.good()){
            previousDepartureTime = departureTime;

            file >> arrivalTime >> procedureTime;

            if(previousDepartureTime - arrivalTime > 0){
                waitTime = previousDepartureTime - arrivalTime;           
            }
            else{
                waitTime = 0;
            }

            departureTime = arrivalTime + procedureTime + waitTime;

            addEvent(arrivalTime,departureTime,bankLine);
            totalWaitTime += waitTime;
            numCustomers ++;
        }
    }

    //outputs everything in the queue
    cout << "Simulation Begins" << endl;
    while (!bankLine.isEmpty())
    {
        readEvent(bankLine);   
    }
    cout << "Simulation Ends\n" << endl;

    outputStatistics(totalWaitTime,numCustomers);
}


bool readEvent(PriorityArrayQueue<Event>& queue){
    if( queue.isEmpty() ) return false;

    Event currentEvent = queue.peekFront();
    if( currentEvent.getEventType() == 'A'){
        cout << "Processing an arrival event at time: " << currentEvent.getEventTime();
    }
    else{
        cout << "Processing a departure event at time: " << currentEvent.getEventTime();
    }
    cout << endl;
    queue.dequeue();

    return true;
}

void outputStatistics(float totalWaitTime, float numCustomers){
    cout << "Final Statistics:" << endl
         << "Total number of people processed: " << (int) (numCustomers) << endl
         << "Average amount of time spent waiting: " << totalWaitTime/numCustomers << endl;
}

bool addEvent(int arrivalTime, int departureTime, PriorityArrayQueue<Event>& queue){
    Event arrive('A', arrivalTime);
    Event depart('D', departureTime);

    try
    {
        queue.enqueue(arrive);
        queue.enqueue(depart);
    }
    catch(const exception& e)
    {
        return false;
    }
    return true;
}
