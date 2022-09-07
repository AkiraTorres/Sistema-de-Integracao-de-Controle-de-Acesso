#include <stdio.h>
#include <stdlib.h>

#include "../headers/eventData.h"
#include "../headers/writeData.h"

struct Event;

int clearShell() {
#ifdef linux
    system("clear");
#elif _WIN32
    system("cls");
#elif __APPLE__
    system("clear");
#endif
    return 0;
}

int saveLastLoad(char *fileName) {
    FILE *filePointer = fopen(fileName, "r");

    if (filePointer != NULL) {
        struct Event *header = NULL;

        while (!feof(filePointer)) {
            struct Event *currentEvent = header;

            int date, cardCode, gateCode;
            char eventType;

            fscanf(filePointer, "%d;%d;%d;%c\n", &date, &cardCode, &gateCode, &eventType);
            struct Event *event = newEvent(date, cardCode, gateCode, eventType);

            if (header == NULL) {
                header = event;
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
        writeData(&header, "../data/output/lastLoad.csv");
        free(header);

        return 0;
    } else {
        printf("Impossível abrir o arquivo.\n");
        return 1;
    }
}

int isEqualEvents(struct Event *eventOne, struct Event *eventTwo) {
    if (eventOne->date == eventTwo->date) {
        if (eventOne->cardCode == eventTwo->cardCode) {
            if (eventOne->gateCode == eventTwo->gateCode) {
                if (eventOne->eventType == eventTwo->eventType) {
                    return 1;
                }
            }
        }
    }

    return 0;
}