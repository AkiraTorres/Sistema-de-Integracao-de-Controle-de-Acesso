#include <stdio.h>

#include "../headers/eventData.h"

struct Event;

int dataByCard(struct Event **headerPointer, int cardID) {
    struct Event *currentEvent = *headerPointer;
    while (!feof(currentEvent)) {
        // feof é usando quando lendo um arquivo, aqui a gente tá tratando
        // diretamente com a lista, não precisa disso, só de um if pra conferir
        // se o *headerPointer é diferente de NULL

        if (currentEvent->cardCode == cardID) {
            printf(currentEvent);
            // a gente não quer imprimir os dados do cartão, mas sim salvar eles
            // num arquivo csv, o ideal acho que seria salvar todos eles em uma
            // nova lista, e depois mandar essa lista na função writeData e por
            // último dar o free nessa lista
        } else {
            // esse else ficaria pro if que confere o headerPointer, tudo o que
            // ele precisaria fazer seria imprimir no terminal que o arquivo de
            // log está vazio
            struct Event *nextEvent = currentEvent->next;
            while ((currentEvent->next != NULL)) {
                currentEvent = currentEvent->next;
                nextEvent = currentEvent->next;
            }
        }
    }
}