#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include "Rocha.h"

typedef struct 
{
    TRocha *Chave;
} TItemRocha;

typedef struct CelulaRocha* ApontadorRocha;
typedef struct CelulaRocha
{
    TItemRocha Item;
    struct CelulaRocha* pProx;
} TCelulaRocha;

typedef struct 
{
    ApontadorRocha pPrimeiro;
    ApontadorRocha pUltimo;
} TListaRocha;

int LTamanhoC(TListaRocha* pListaR);
void FLVaziaC(TListaRocha* pListaR);
int LEhVaziaC(TListaRocha* pListaR);
int LInsereC(TListaRocha* pListaR, TRocha* pItem);
int LRetiraC(TListaRocha* pListaR, TRocha* rocha);
void LImprimeC(TListaRocha pListaR);
double PesoCompartimento(TListaRocha* pListaR);
void TrocarRocha(TListaRocha* pListaR, TRocha* Item);

void RetiraRochas2(TListaRocha *plista);
void RemoveUltimaRocha(TListaRocha* pLista, TRocha *pX);

int lista_rocha_vazia(TListaRocha *pLista);

#endif