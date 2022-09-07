// Imports of free libs
#include <stdio.h>
#include <stdlib.h>

// Imports modules
#include "../headers/dataByCard.h"
#include "../headers/eventData.h"
#include "../headers/writeData.h"

struct Event;  // Extends the struct for the module

/*
    @authors: Akira, AsTunO
    @param headerPointer: A pointer to the head of the dynamic list (log.csv)
    @return: state of the function
*/
int searchContradictions(struct Event **headerPointer) {
    if (*headerPointer != NULL) {                     // Verify if there's a next struct
        struct Event *checkingCode = *headerPointer;  // Creat a new pointer for the header
        struct Event *contradictions = NULL;

        while (checkingCode->next != NULL) {  // Verify if there's a next struct
            struct Event *nextCode = checkingCode->next;
            while ((checkingCode->cardCode != nextCode->cardCode) && (nextCode->next != NULL)) {
                nextCode = nextCode->next;
            }
            if ((checkingCode->eventType == nextCode->eventType) && (checkingCode->cardCode == nextCode->cardCode)) {  // Check the type and card code
                char type = checkingCode->eventType == 'E' ? 'A' : 'B';
                struct Event *newContradiction = newEvent(nextCode->date, nextCode->cardCode, nextCode->gateCode, type);
                if (contradictions == NULL) {
                    contradictions = newContradiction;                    // Get the new value of the header of the new dynamic list
                } else {                                                  // Get the next values
                    struct Event *currentContradiction = contradictions;  // Creat a new pointer for the actual occurrence
                    while (currentContradiction->next != NULL) {
                        currentContradiction = currentContradiction->next;
                    }
                    currentContradiction->next = newContradiction;
                }
                // free(newContradiction);  // Free pointer
            }

            checkingCode = checkingCode->next;
        }

        writeData(&contradictions, "../data/output/inconsistencias.csv");  // Calls the functions to write the contradictions
        free(contradictions);                                              // Free pointer
    } else {
        printf("O log está vazio!\n");
    }
}