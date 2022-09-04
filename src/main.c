#include <stdio.h>
#include <stdlib.h>
#include "headers/dataLoad.h"
#include "headers/eventData.h"
#include "headers/writeData.h"

int main() {
    struct Event *headerPointer = NULL;

    int opt = -1;

    while(opt != 0) {
        printf("Digite para o menu: ");
        scanf(" %i", &opt);
        switch(opt) {
            case 1: {
                char filename[30];
                scanf(" %s", filename);
                dataLoad(&headerPointer, filename);
                writeData(&headerPointer, "../data/log.txt");
                break;
            }
            case 2: {
                struct Event* currentEvent = headerPointer;
                if (currentEvent == NULL) {
                    printf("A lista está vazia!\n");
                }
                while (currentEvent != NULL) {
                    printf("%d - %d - %d - %c\n", currentEvent->date, currentEvent->cardCode, currentEvent->gateCode, currentEvent->eventType);
                    currentEvent = currentEvent->next;
                }
                break;
            }
            case 0: {
                system("clear");
                break;
            }
        }
    }

    return 0;
}