#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_DATALOAD_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_DATALOAD_H

#include "../headers/eventData.h"

struct Event;

int dataLoad(struct Event **headerPointer, char *fileName);

#endif
