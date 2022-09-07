// Imports of free libs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Import modules
#include "headers/dataByCard.h"
#include "headers/dataLoad.h"
#include "headers/eventData.h"
#include "headers/genericFunctions.h"
#include "headers/loadLog.h"
#include "headers/searchContradictions.h"
#include "headers/undoLoad.h"
#include "headers/writeData.h"

struct Event; // Extends the struct for the module

/*
    @authors: Akira, AsTunO
    @return: state of the function
*/
int main()
{
    struct Event *headerPointer = NULL;
    loadLog(&headerPointer); // Check if there's a log.csv and load this and save at a dynamic list

    int opt = -1;

    while (opt != 0)
    {
        printf("1- Para fazer uma carga de dados.\n2- Para desfazer a última carga realizada.\n");
        printf("3- Para buscar inconsistências nos logs.\n4- Para emitir o relatório de acesso por cartão.\n");
        printf("Digite para o menu: ");
        scanf(" %i", &opt); // Get the menu option from the user

        switch (opt)
        {
            case 1:
            {
                clearShell(); // Clear the terminal based on the SO
                char filename[30];
                printf("Digite o caminho relativo do arquivo que será lido [../data/example-file.csv]: ");
                scanf(" %s", filename);
                dataLoad(&headerPointer, filename);                  // Calls the function to do a new load
                writeData(&headerPointer, "../data/output/log.csv"); // Calls the function to write the loads at the same archive
                saveLastLoad(filename);                              // Calls the function to save the last load done at another archive
                break;
            }
            case 2:
            {
                clearShell();             // Clear the terminal based on the SO
                undoLoad(&headerPointer); // Calls the function that are going to undo de last load done
                break;
            }
            case 3:
            {
                clearShell();                         // Clear the terminal based on the SO
                searchContradictions(&headerPointer); // Calls the function that are going to find all the contradictions from the log.csv
                break;
            }
            case 4:
            {
                clearShell(); // Clear the terminal based on the SO
                int cardID;
                struct Event *headerReportByCard = NULL;
                printf("Digite o id do cartão do usuário que deseja o log: ");
                scanf(" %i", &cardID);

                dataByCard(&headerPointer, &headerReportByCard, cardID); // Find all the occurrences of a specif card

                // Format the string to get the correct name of the archive with the card code in the name
                char str[5];
                char path[] = "../data/output/";
                sprintf(str, "%d", cardID);
                char prefix[24];
                sprintf(prefix, "%s%s%s", path, str, ".csv");
                writeData(&headerReportByCard, prefix); // Calls the function to write the data of a card at the same archive
                free(headerReportByCard);               // Free the pointer
                break;
            }
            case 0:
            {
                clearShell(); // Clear the terminal based on the SO
                break;
            }
        }
    }

    return 0;
}