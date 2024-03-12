/*
Author: Nikola Tunguz & <REDACTED>
Purpose: Event class function implementations.
*/

#include "Event.h"

//default constructor, nonsense values
Event::Event(){
    eventType = 'z';
    eventTime = -1;
}

//parameterized constructor 
Event::Event(const char type, const int time){
    eventType = type;
    eventTime = time;
}

//copy constructor
Event::Event(const Event& rhs){
    eventType = rhs.eventType;
    eventTime = rhs.eventTime;
}

//basic getters and setters
char Event::getEventType(){
    return eventType;
}

int Event::getEventTime(){
    return eventTime;
}

void Event::setEventType( char newType){
    eventType = newType;
}   

void Event::setEventTime( int newTime ){
    eventTime = newTime;
}

//comparison operator overload
bool Event::operator<(const Event& rhs) const{
    return (eventTime < rhs.eventTime);
}