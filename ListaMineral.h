#ifndef LISTAMINERAL_H
#define LISTAMINERAL_H

#define InicioArranjo 0
#define MaxTam 5

#include "Mineral.h"

typedef int ApontadorMineral;

typedef struct 
{
    TMineral Chave;
} TItemMineral;

typedef struct 
{
    TItemMineral ItemM[MaxTam];
    ApontadorMineral Primeiro, Ultimo;
} TListaMineral;

void FLVaziaM(TListaMineral* pLista);
int LEhVaziaM(TListaMineral* pLista);
void LInsereM(TListaMineral* pLista, TMineral x);
int LRetiraMnome(TListaMineral* pLista, char *nomeM, TMineral *pX);
void LimprimeM(TListaMineral* pLista);
void PListaMinerais(TListaMineral* pLista, TMineral* mineral);
int TMListaM(TListaMineral *pLista);

#endif