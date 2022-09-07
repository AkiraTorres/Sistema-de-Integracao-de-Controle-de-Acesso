
//
// Created by akira on 01/09/22.
//

#ifndef SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_EVENTDATA_H
#define SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_EVENTDATA_H

struct Event {
    int date;
    int cardCode;
    int gateCode;
    char eventType;
    struct Event* next;
};

struct Event* newEvent(int date, int cardCode, int gateCode, char eventType);

#endif  // SISTEMA_DE_INTEGRACAO_DE_CONTROLE_DE_ACESSO_EVENTDATA_H
