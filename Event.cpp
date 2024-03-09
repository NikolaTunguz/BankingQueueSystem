#include "Event.h"

Event::Event(){
    eventType = 'z';
    eventTime = -1;
}

Event::Event(const char type, const int time){
    eventType = type;
    eventTime = time;
}

Event::Event(const Event& rhs){
    eventType = rhs.eventType;
    eventTime = rhs.eventTime;
}

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

bool Event::operator<(const Event& rhs) const{
    return (eventTime < rhs.eventTime);
}