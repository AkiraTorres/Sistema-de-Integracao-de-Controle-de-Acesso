#include <stdio.h>

#include "../headers/eventData.h"

struct Event;

int dataLoad(struct Event **headerPointer, char *fileName) {
    FILE *filePointer = fopen(fileName, "r");

    if (filePointer != NULL) {
        while (!feof(filePointer)) {
            struct Event *currentEvent = *headerPointer;

            int date, cardCode, gateCode;
            char eventType;

            fscanf(filePointer, "%d;%d;%d;%c\n", &date, &cardCode, &gateCode, &eventType);
            struct Event *event = newEvent(date, cardCode, gateCode, eventType);

            if (*headerPointer == NULL) {
                *headerPointer = event;
            } else {
                struct Event *nextEvent = currentEvent->next;
                while ((currentEvent->next != NULL) && (nextEvent->date < event->date)) {
                    currentEvent = currentEvent->next;
                    nextEvent = currentEvent->next;
                }
                event->next = currentEvent->next;
                currentEvent->next = event;
            }
        }

        fclose(filePointer);
    } else {
        printf("Impossível abrir o arquivo.\n");
        return 0;
    }
}