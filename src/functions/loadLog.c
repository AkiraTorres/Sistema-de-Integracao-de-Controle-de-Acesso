//
// Created by akira on 04/09/22.
//

#include <stdio.h>

#include "../headers/dataLoad.h"
#include "../headers/eventData.h"

struct Event;

int loadLog(struct Event **headerPointer) {
    FILE *filePointer = fopen("../data/output/log.csv", "r");
    if (filePointer != NULL) {
        dataLoad(headerPointer, "../data/output/log.csv");
        return 0;
    } else {
        return 1;
    }
}