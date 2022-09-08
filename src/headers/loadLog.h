#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_LOADLOG_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_LOADLOG_H

#include "eventData.h"

struct Event;

int loadLog(struct Event **headerPointer);

#endif