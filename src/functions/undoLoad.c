#include <stdio.h>
#include <stdlib.h>

// a ideia para a undoLoad acho que seria já pegar automaticamente a lista do
// headerPointer, que é a lista do log geral, e ele pegar o último arquivo adicionado,
// aí ele sair passando e deletando tudo isso da lista, no final seria apenas chamar
// a função writeData de novo, passando o caminho do log.csv e o headerPointer, e
// então a função vai escrever a lista nova, que acabou de ter a última carga removida
int undoLoad(char *fileNameLog, char *fileNameLastLoad) {
    FILE *filePointerLog = fopen(fileNameLog, "w");
    FILE *filePointerLastLoad = fopen(fileNameLastLoad, "r");

    if (filePointerLog != NULL && filePointerLastLoad != NULL) {
        char *pontLineLastLoad = NULL;
        size_t len = 0;

        // usando o método que eu disse acima, não precisaria ficar lendo e editando
        // os dois arquivos de texto ao mesmo tempo, seria apenas editar a lista e
        // no final escrever ela no log.csv
        while (!feof(filePointerLastLoad)) {
            char *pontLineLog = NULL;
            size_t len = 0;

            while (!feof(filePointerLog)) {
                if (getline(&pontLineLastLoad, &len, filePointerLastLoad) == getline(&pontLineLog, &len, filePointerLog)) {
                    *pontLineLog = "";
                }
            }

            if (pontLineLog) {
                free(pontLineLog);
            }
            fclose(filePointerLog);
        }

        if (pontLineLastLoad) {
            free(pontLineLastLoad);
        }
        fclose(filePointerLastLoad);
    } else {
        printf("Impossível abrir o arquivo");
    }
}