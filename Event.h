/*
Author: Nikola Tunguz & <REDACTED>
Purpose: Event class that stores various types of banking events and what time they occur.
*/

class Event{
    private:
        char eventType;
        int eventTime;  

    public:
        //constructors
        Event();
        Event(const char type, const int time);
        Event(const Event& rhs);

        //basic getters and setters
        int getEventTime();
        char getEventType();
        void setEventTime( int newTime );
        void setEventType( char newType );
          
        //comparison operator overload
        bool operator<(const Event& rhs) const;

};