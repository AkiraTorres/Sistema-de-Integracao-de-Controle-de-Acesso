// Imports of free libs
#include <stdio.h>

// Imports modules
#include "../headers/eventData.h"

struct Event; // Extends the struct for the module

/*
    @authors: Akira, AsTunO
    @param headerPointer: A pointer to the head of the dynamic list (log.csv)
    @param headerReportByCard: A pointer to the head of the dynamic list (cardID.csv)
    @param cardID: A card code
    @return: state of the function
*/
int dataByCard(struct Event **headerPointer, struct Event **headerReportByCard, int cardID)
{
    struct Event *currentEvent = *headerPointer;

    while (currentEvent->next != NULL) // Verify if there's a next currentEvent
    {
        if (currentEvent->cardCode == cardID)
        {
            struct Event *currentReport = *headerReportByCard;                                                                             // Creat a new pointer for the header
            struct Event *newCard = newEvent(currentEvent->date, currentEvent->cardCode, currentEvent->gateCode, currentEvent->eventType); // Creat a new pointer with the data

            if (*headerReportByCard == NULL)
            {
                *headerReportByCard = newCard; // Get the new value of the header of the new dynamic list
            }
            else // Get the next values
            {
                while (currentReport->next != NULL)
                {
                    currentReport = currentReport->next;
                }
                currentReport->next = newCard;
            }
        }
        currentEvent = currentEvent->next;
    }
    return 0;
}