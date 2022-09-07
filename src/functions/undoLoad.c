#include <stdio.h>
#include <stdlib.h>

#include "../headers/eventData.h"
#include "../headers/genericFunctions.h"
#include "../headers/writeData.h"

struct Event;

int undoLoad(struct Event **headerPointer) {
    FILE *pontLastLoad = fopen("../data/lastLoad.csv", "r");

    if ((pontLastLoad != NULL)) {
        char *pontLineLastLoad = NULL;
        size_t len = 0;
        while (!feof(pontLastLoad)) {
            struct Event *current = *headerPointer;
            struct Event *previous = NULL;

            int date, cardCode, gateCode;
            char eventType;

            fscanf(pontLastLoad, "%i;%i;%i;%c\n", &date, &cardCode, &gateCode, &eventType);

            struct Event *currentLine = newEvent(date, cardCode, gateCode, eventType);

            while (current->next != NULL) {
                if (isEqualEvents(current, currentLine)) {
                    if (previous == NULL) {
                        *headerPointer = current->next;
                    } else {
                        previous->next = current->next;
                    }
                } else {
                    previous = current;
                }
                current = current->next;
            }

            if (isEqualEvents(current, currentLine)) {
                if (isEqualEvents(*headerPointer, current)) {
                    *headerPointer = NULL;
                    break;
                } else {
                    previous->next = NULL;
                }
            }
        }

        struct Event *nullable = NULL;
        writeData(headerPointer, "../data/output/log.csv");
        writeData(&nullable, "../data/output/lastLoad.csv");
        free(nullable);
        fclose(pontLastLoad);
    } else {
        printf("Impossível abrir o arquivo!");
    }
}