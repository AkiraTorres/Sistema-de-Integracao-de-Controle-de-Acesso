// Imports of free libs
#include <stdio.h>
#include <stdlib.h>

struct Event // Dynamic list
{
    int date;
    int cardCode;
    int gateCode;
    char eventType;
    struct Event *next;
};

/*
    @authors: Akira, AsTunO
    @param date: The epoch date
    @param cardCode: Card ID
    @param gateCode: Code of the gate
    @param eventType: The state of the event (E/S)
    @return: the new struct event
*/
struct Event *newEvent(int date, int cardCode, int gateCode, char eventType)
{
    struct Event *event = malloc(sizeof(struct Event)); // Creat a event with the correct quantitative of bits

    event->date = date;
    event->cardCode = cardCode;
    event->gateCode = gateCode;
    event->eventType = eventType;
    event->next = NULL;

    return event;
}
