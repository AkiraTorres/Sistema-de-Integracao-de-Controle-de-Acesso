// Imports of free libs
#include <stdio.h>

// Imports modules
#include "../headers/dataLoad.h"
#include "../headers/eventData.h"

struct Event; // Extends the struct for the module

/*
    @authors: Akira, AsTunO
    @param headerPointer: A pointer to the head of the dynamic list (log.csv)
    @return: state of the function
*/
int loadLog(struct Event **headerPointer)
{
    FILE *filePointer = fopen("../data/output/log.csv", "r");
    if (filePointer != NULL)
    {
        dataLoad(headerPointer, "../data/output/log.csv"); // Call the functions to do a load 
        return 0;
    }
    else
    {
        return 1;
    }
}