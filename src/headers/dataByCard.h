#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_DATABYCARD_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_DATABYCARD_H

#include "eventData.h"

struct Event;

int dataByCard(struct Event **headerPointer, struct Event **headerReportByCard, int cardID);

#endif
