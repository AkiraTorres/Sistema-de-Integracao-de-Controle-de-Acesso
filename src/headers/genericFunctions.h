#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_GENERICFUNCTIONS_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_GENERICFUNCTIONS_H

int clearShell();
int saveLastLoad(char *fileName);
int isEqualEvents(struct Event *eventOne, struct Event *eventTwo);
int alreadyExists(struct Event **headPointer, struct Event *newEvent);

#endif