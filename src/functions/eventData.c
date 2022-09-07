//
// Created by akira on 01/09/22.
//
#include <stdio.h>
#include <stdlib.h>

struct Event {
    int date;
    int cardCode;
    int gateCode;
    char eventType;
    struct Event* next;
};

struct Event* newEvent(int date, int cardCode, int gateCode, char eventType) {
    struct Event* event = malloc(sizeof(struct Event));

    event->date = date;
    event->cardCode = cardCode;
    event->gateCode = gateCode;
    event->eventType = eventType;
    event->next = NULL;

    return event;
}
