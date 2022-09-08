#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_WRITEDATA_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_WRITEDATA_H

#include "../headers/eventData.h"

struct Event;

int writeData(struct Event **headPointer, char *fileName);

#endif