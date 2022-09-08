#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_EVENTDATA_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_EVENTDATA_H

struct Event {
    long int date;
    int cardCode;
    int gateCode;
    char eventType;
    struct Event *next;
};

struct Event *newEvent(long int date, int cardCode, int gateCode, char eventType);

#endif
