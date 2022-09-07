#include <stdio.h>
#include <stdlib.h>

#include "../headers/dataByCard.h"
#include "../headers/eventData.h"
#include "../headers/writeData.h"

struct Event;

int searchContradictions(struct Event **headerPointer) {
    if (*headerPointer != NULL) {
        struct Event *checkingCode = *headerPointer;
        struct Event *contradictions = NULL;

        while (checkingCode->next != NULL) {
            struct Event *nextCode = checkingCode->next;
            while ((checkingCode->cardCode != nextCode->cardCode) && (nextCode->next != NULL)) {
                nextCode = nextCode->next;
            }
            if ((checkingCode->eventType == nextCode->eventType) && (checkingCode->cardCode == nextCode->cardCode)) {
                // printf("%i - %i\n", checkingCode->cardCode, nextCode->cardCode);
                char type = checkingCode->eventType == 'E' ? 'A' : 'B';
                struct Event *newContradiction = newEvent(nextCode->date, nextCode->cardCode, nextCode->gateCode, type);
                if (contradictions == NULL) {
                    contradictions = newContradiction;
                } else {
                    struct Event *currentContradiction = contradictions;
                    while (currentContradiction->next != NULL) {
                        currentContradiction = currentContradiction->next;
                    }
                    currentContradiction->next = newContradiction;
                    free(newContradiction);
                }
            }

            checkingCode = checkingCode->next;
        }

        writeData(&contradictions, "../data/output/inconsistencias.csv");
        free(contradictions);
    } else {
        printf("O log está vazio!\n");
    }
}