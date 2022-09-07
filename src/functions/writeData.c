// Imports of free libs
#include <stdio.h>

// Imports modules
#include "../headers/eventData.h"

struct Event; // Extends the struct for the module

/*
    @authors: Akira, AsTunO
    @param headerPointer: A pointer to the head of the dynamic list (log.csv)
    @param fileName: Name to the archive with the data
    @return: state of the function
*/
int writeData(struct Event **headPointer, char *fileName)
{
    if (*headPointer != NULL) // Verify if there's a next line
    {
        FILE *filePointer = fopen(fileName, "w+"); // Open the archive

        struct Event *currentEvent = *headPointer; // Creat a new pointer for the header

        while (currentEvent->next != NULL) // Verify if there's a next event
        {
            int date = currentEvent->date, cardCode = currentEvent->cardCode, gateCode = currentEvent->gateCode; // Get the data of the load
            char eventType = currentEvent->eventType;                                                            // Get the data of the load
            fprintf(filePointer, "%i;%i;%i;%c\n", date, cardCode, gateCode, eventType);                          // Write the data formate
            currentEvent = currentEvent->next;
        }
        //(EndLine)
        int date = currentEvent->date, cardCode = currentEvent->cardCode, gateCode = currentEvent->gateCode; // Get the data of the load
        char eventType = currentEvent->eventType;                                                            // Get the data of the load
        fprintf(filePointer, "%i;%i;%i;%c\n", date, cardCode, gateCode, eventType);                          // Write the data formate

        fclose(filePointer); // Close file
        return 0;
    }
    else // Especial case (current == headerPointer)
    {
        FILE *filePointer = fopen(fileName, "w+");

        fprintf(filePointer, "");

        fclose(filePointer);
        return 0;
    }
}