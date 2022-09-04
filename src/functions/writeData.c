//
// Created by akira on 25/08/22.
//

#include <stdio.h>

#include "../headers/eventData.h"

struct Event;

int writeData(struct Event **headPointer, char *fileName) {
    if (*headPointer != NULL) {
        FILE *filePointer = fopen("../data/log.csv", "w+");

        struct Event *currentEvent = *headPointer;

        while (currentEvent->next != NULL) {
            int date = currentEvent->date, cardCode = currentEvent->cardCode, gateCode = currentEvent->gateCode;
            char eventType = currentEvent->eventType;
            fprintf(filePointer, "%i;%i;%i;%c\n", date, cardCode, gateCode, eventType);
            currentEvent = currentEvent->next;
        }
    } else {
        printf("Nenhum log foi adicionado.\n");
    }
}