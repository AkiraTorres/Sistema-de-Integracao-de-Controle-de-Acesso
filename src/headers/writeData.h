//
// Created by akira on 02/09/22.
//

#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_WRITEDATA_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_WRITEDATA_H

#include "../headers/eventData.h"

struct Event;

int writeData(struct Event **headPointer, char *fileName);

#endif // SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_WRITEDATA_H
