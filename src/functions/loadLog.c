//
// Created by akira on 04/09/22.
//

#include <stdio.h>

#include "../headers/eventData.h"
#include "../headers/dataLoad.h"

struct Event;

int loadLog(struct Event **headerPointer) {
    FILE *filePointer = fopen("../data/log.csv", "r");
    if (filePointer != NULL) {
        dataLoad(headerPointer, "../data/log.csv");
        return 0;
    } else {
        return 1;
    }
}