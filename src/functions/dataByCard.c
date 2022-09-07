#include <stdio.h>

#include "../headers/eventData.h"

struct Event;

int dataByCard(struct Event **headerPointer, struct Event **headerReportByCard, int cardID) {
    struct Event *currentEvent = *headerPointer;

    while (currentEvent->next != NULL) {
        if (currentEvent->cardCode == cardID) {
            struct Event *currentReport = *headerReportByCard;
            struct Event *newCard = newEvent(currentEvent->date, currentEvent->cardCode, currentEvent->gateCode, currentEvent->eventType);

            if (*headerReportByCard == NULL) {
                *headerReportByCard = newCard;
            } else {
                while (currentReport->next != NULL) {
                    currentReport = currentReport->next;
                }
                currentReport->next = newCard;
            }
        }
        currentEvent = currentEvent->next;
    }
    return 0;
}