// Imports of free libs
#include <stdio.h>
#include <stdlib.h>

// Imports modules
#include "../headers/eventData.h"
#include "../headers/writeData.h"

struct Event;  // Extends the struct for the module

// Identify the SO to use the correct command in the terminal
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

/*
    @authors: Akira, AsTunO
    @param fileName: The name of the last archive used to do a load
    @return: state of the function
*/
int saveLastLoad(char *fileName) {
    FILE *filePointer = fopen(fileName, "r");  // Open the archive

    if (filePointer != NULL) {  // Verify if there's a next line
        struct Event *header = NULL;

        while (!feof(filePointer)) {  // Verify if the archive is in the end
            struct Event *currentEvent = header;

            long int date;
            int cardCode, gateCode;
            char eventType;

            fscanf(filePointer, "%li;%d;%d;%c\n", &date, &cardCode, &gateCode, &eventType);  // Get the data of the load
            struct Event *event = newEvent(date, cardCode, gateCode, eventType);             // Creat a new pointer with the data

            if (header == NULL) {
                header = event;  // Get the new value of the header of the new dynamic list
            } else {             // Get the next values
                struct Event *nextEvent = currentEvent->next;
                while ((currentEvent->next != NULL) && (nextEvent->date < event->date)) {
                    currentEvent = currentEvent->next;
                    nextEvent = currentEvent->next;
                }
                event->next = currentEvent->next;
                currentEvent->next = event;
            }
        }
        fclose(filePointer);                                // Close the file
        writeData(&header, "../data/output/lastLoad.csv");  // Calls the functions to write the data
        free(header);                                       // Free the pointer

        return 0;
    } else {
        printf("Impossível abrir o arquivo.\n");
        return 1;
    }
}

/*
    @authors: Akira, AsTunO
    @param eventOne: A pointer with the first term to compare
    @param eventTwo: A pointer with the second term to compare
    @return: state of the function
*/
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

int alreadyExists(struct Event **headPointer, struct Event *newEvent) {
    if (*headPointer != NULL) {
        struct Event *currentEvent = *headPointer;

        while (currentEvent->next != NULL) {
            if (isEqualEvents(currentEvent, newEvent)) {
                return 1;
            }
            currentEvent = currentEvent->next;
        }
        if (isEqualEvents(currentEvent, newEvent)) {
            return 1;
        }
        return 0;
    }
}