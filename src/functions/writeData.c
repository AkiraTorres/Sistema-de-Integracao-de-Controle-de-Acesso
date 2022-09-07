//
// Created by akira on 25/08/22.
//

#include <stdio.h>

#include "../headers/eventData.h"

struct Event;

int writeData(struct Event **headPointer, char *fileName) {
    if (*headPointer != NULL) {
        FILE *filePointer = fopen(fileName, "w+");

        struct Event *currentEvent = *headPointer;

        while (currentEvent->next != NULL) {
            int date = currentEvent->date, cardCode = currentEvent->cardCode, gateCode = currentEvent->gateCode;
            char eventType = currentEvent->eventType;
            fprintf(filePointer, "%i;%i;%i;%c\n", date, cardCode, gateCode, eventType);
            currentEvent = currentEvent->next;
        }
        int date = currentEvent->date, cardCode = currentEvent->cardCode, gateCode = currentEvent->gateCode;
        char eventType = currentEvent->eventType;
        fprintf(filePointer, "%i;%i;%i;%c\n", date, cardCode, gateCode, eventType);

        fclose(filePointer);
        return 0;
    } else {
        FILE *filePointer = fopen(fileName, "w+");

        fprintf(filePointer, "");

        fclose(filePointer);
        return 0;
    }
}