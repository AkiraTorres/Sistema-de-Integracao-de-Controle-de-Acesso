// Imports of free libs
#include <stdio.h>

// Imports modules
#include "../headers/eventData.h"

struct Event;  // Extends the struct for the module

/*
    @authors: Akira, AsTunO
    @param headerPointer: A pointer to the head of the dynamic list (log.csv)
    @param fileName: Name to the archive with the data
    @return: state of the function
*/
int dataLoad(struct Event **headerPointer, char *fileName) {
    FILE *filePointer = fopen(fileName, "r");  // Open the archive

    if (filePointer != NULL) {                            // Verify if there's a next line
        while (!feof(filePointer)) {                      // Verify if the archive is in the end
            struct Event *currentEvent = *headerPointer;  // Creat a new pointer for the header

            int date, cardCode, gateCode;
            char eventType;

            fscanf(filePointer, "%d;%d;%d;%c\n", &date, &cardCode, &gateCode, &eventType);  // Get the data of the load
            struct Event *event = newEvent(date, cardCode, gateCode, eventType);            // Creat a new pointer with the data

            if (*headerPointer == NULL) {
                *headerPointer = event;  // Get the new value of the header of the new dynamic list
            } else {                     // Get the next values
                struct Event *nextEvent = currentEvent->next;
                while ((currentEvent->next != NULL) && (nextEvent->date < event->date)) {  // Verify if there's a next event and the position of the data
                    currentEvent = currentEvent->next;
                    nextEvent = currentEvent->next;
                }
                event->next = currentEvent->next;
                currentEvent->next = event;
            }
        }

        fclose(filePointer);  // Close the file
        return 0;
    } else {
        printf("Impossível abrir o arquivo.\n");
        return 1;
    }
}