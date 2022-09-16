#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <memory>
#include "snake.h"



class Event
{
public:
    explicit Event(unsigned int id): id(id)
    {

    }

    virtual void handle_event() = 0;

    virtual ~Event()
    {

    }

protected:
    unsigned int id;
};


class MoveLeftEvent: public Event
{
public:
    MoveLeftEvent(unsigned int id): Event(id)
    {

    }

    void handle_event() final
    {

    }

private:
    std::shared_ptr<Snake*>* snake;

};


class MoveRightEvent: public Event
{
public:
    MoveRightEvent(unsigned int id): Event(id)
    {

    }

    void handle_event() final
    {

    }


};



class MoveUpEvent: public Event
{
public:
    MoveUpEvent(unsigned int id): Event(id)
    {

    }

    void handle_event() final
    {

    }


};



class MoveDownEvent: public Event
{
public:
    MoveDownEvent(unsigned int id): Event(id)
    {

    }

    void handle_event() final
    {

    }


};


class GameStopEvent: public Event
{
public:
    GameStopEvent(unsigned int id): Event(id)
    {

    }

    void handle_event() final
    {

    }


};


class MoveEvent: public Event
{
public:
    MoveEvent(unsigned int id): Event(id)
    {

    }

    void handle_event() final
    {
        std::cout<<"Move event is handled."<<std::endl;
    }


};



#endif //EVENT_HANDLER_H
