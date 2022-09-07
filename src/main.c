#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/dataByCard.h"
#include "headers/dataLoad.h"
#include "headers/eventData.h"
#include "headers/genericFunctions.h"
#include "headers/loadLog.h"
#include "headers/searchContradictions.h"
#include "headers/undoLoad.h"
#include "headers/writeData.h"

int main() {
    struct Event *headerPointer = NULL;
    loadLog(&headerPointer);

    int opt = -1;

    while (opt != 0) {
        printf("1- Para fazer uma carga de dados.\n2- Para desfazer a última carga realizada.\n");
        printf("3- Para buscar inconsistências nos logs.\n4- Para emitir o relatório de acesso por cartão.\n");
        printf("Digite para o menu: ");
        scanf(" %i", &opt);

        switch (opt) {
            case 1: {
                clearShell();
                char filename[30];
                printf("Digite o caminho relativo do arquivo que será lido [../data/example-file.csv]: ");
                scanf(" %s", filename);
                dataLoad(&headerPointer, filename);
                writeData(&headerPointer, "../data/output/log.csv");
                saveLastLoad(filename);
                break;
            }
            case 2: {
                clearShell();
                undoLoad(&headerPointer);
                break;
            }
            case 3: {
                clearShell();
                (&headerPointer);
                break;
            }
            case 4: {
                clearShell();
                int cardID;
                struct Event *headerReportByCard = NULL;
                printf("Digite o id do cartão do usuário que deseja o log: ");
                scanf(" %i", &cardID);

                dataByCard(&headerPointer, &headerReportByCard, cardID);

                char str[5];
                char path[] = "../data/output/";
                sprintf(str, "%d", cardID);
                char prefix[20];
                sprintf(prefix, "%s%s%s", path, str, ".csv");
                writeData(&headerReportByCard, prefix);
                free(headerReportByCard);
                break;
            }
            case 0: {
                clearShell();
                break;
            }
        }
    }

    return 0;
}