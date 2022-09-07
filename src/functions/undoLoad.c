// Imports of free libs
#include <stdio.h>
#include <stdlib.h>

// Imports modules
#include "../headers/eventData.h"
#include "../headers/genericFunctions.h"
#include "../headers/writeData.h"

struct Event; // Extends the struct for the module

/*
    @authors: Akira, AsTunO
    @param headerPointer: A pointer to the head of the dynamic list (log.csv)
    @return: state of the function
*/
int undoLoad(struct Event **headerPointer)
{
    FILE *pontLastLoad = fopen("../data/lastLoad.csv", "r"); // Open the archive

    if ((pontLastLoad != NULL)) // Verify if there's a next line
    {
        char *pontLineLastLoad = NULL; // Create a new pointer to receive the data of the line
        size_t len = 0;
        while (!feof(pontLastLoad)) // Verify if the archive is in the end
        {
            struct Event *current = *headerPointer; // Creat a new pointer for the header
            struct Event *previous = NULL;          // Creat a new pointer for the previous data

            int date, cardCode, gateCode;
            char eventType;

            fscanf(pontLastLoad, "%i;%i;%i;%c\n", &date, &cardCode, &gateCode, &eventType); // Get the data of the load

            struct Event *currentLine = newEvent(date, cardCode, gateCode, eventType); // Creat a new pointer with the data

            while (current->next != NULL)
            {
                if (isEqualEvents(current, currentLine)) // Verify if's equals
                {
                    if (previous == NULL)
                    {
                        *headerPointer = current->next; // Get the new value of the header of the new dynamic list
                    }
                    else // Get the next values
                    {
                        previous->next = current->next;
                    }
                }
                else // Get the next struct
                {
                    previous = current;
                }
                current = current->next;
            }

            // Especial case (current == headerPointer)
            if (isEqualEvents(current, currentLine)) 
            {
                if (isEqualEvents(*headerPointer, current))
                {
                    *headerPointer = NULL;
                    break;
                }
                else
                {
                    previous->next = NULL;
                }
            }
        }

        struct Event *nullable = NULL; // Aux pointer
        writeData(headerPointer, "../data/output/log.csv"); // Rewrite the new log
        writeData(&nullable, "../data/output/lastLoad.csv"); // Clear the lastLoad.csv
        free(nullable); // Free pointer
        fclose(pontLastLoad); // Close the archive
    }
    else
    {
        printf("Impossível abrir o arquivo!");
    }
}