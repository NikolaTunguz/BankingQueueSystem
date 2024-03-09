/**
 * @ Author: Austin Finch & Nikola Tunguz
 * @ Due Date: March 12, 2023
 * @ Description: Event class that stores various types of events and what time they occur.
 */

class Event{
    private:
        char eventType;
        int eventTime;  

    public:
        Event();
        Event(const char type, const int time);
        Event(const Event& rhs);

        int getEventTime();
        char getEventType();

        void setEventTime( int newTime );
        void setEventType( char newType );
          
        bool operator<(const Event& rhs) const;

};