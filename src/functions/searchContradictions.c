#include <stdio.h>
#include <stdlib.h>

#include "../headers/eventData.h"
#include "../headers/writeData.h"

struct Event;

int searchContradictions(struct Event **headerPointer) {
    if (*headerPointer != NULL) {
        struct Event *currentEvent = *headerPointer;
        struct Event *nextCardEvent = currentEvent->next;
        struct Event *contradictions = NULL;

        while (currentEvent->next != NULL) {
            while (nextCardEvent->cardCode != currentEvent->cardCode && nextCardEvent->next != NULL) {
                nextCardEvent = nextCardEvent->next;
            }
            if (nextCardEvent->eventType == currentEvent->eventType) {
                int date = nextCardEvent->date, cardCode = nextCardEvent->cardCode, gateCode = nextCardEvent->gateCode;
                char eventType;
                if (nextCardEvent->eventType == 'E') {
                    eventType = 'A';
                } else {
                    eventType = 'B';
                }
                struct Event *newContradiction = newEvent(date, cardCode, gateCode, eventType);
                if (contradictions == NULL) {
                    contradictions = newContradiction;
                } else {
                    while (contradictions->next != NULL) {
                        contradictions = contradictions->next;
                    }
                    contradictions->next = newContradiction;
                }
                free(newContradiction);
            }
            currentEvent = currentEvent->next;
        }

        writeData(&contradictions, "../data/inconsistencias.csv");
        free(contradictions);
    } else {
        printf("O log está vazio!\n");
    }
}