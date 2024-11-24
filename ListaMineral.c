#include "ListaMineral.h"
#include <stdio.h>
#include <string.h>

void FLVaziaM(TListaMineral* pLista) {
    pLista->Primeiro = 0;
    pLista->Ultimo = pLista->Primeiro;
}

int LEhVaziaM(TListaMineral* pLista) {
    return pLista->Ultimo == pLista->Primeiro;
}

void LInsereM(TListaMineral* pLista, TMineral x) {
    if (pLista->Ultimo >= MaxTam) {
        printf("ERRO DE INCERCAO\n");
        return;
    }
    pLista->ItemM[pLista->Ultimo].Chave = x;
    pLista->Ultimo++; 
}

int LRetiraMnome(TListaMineral* pLista, char *nomeM, TMineral *pX) {
    int cont;
    
    if (LEhVaziaM(pLista)) {
        return 0;
    }
    for (cont = pLista->Primeiro; cont <= pLista->Ultimo; cont++) {
        if (strcmp(nomeM, pLista->ItemM[cont].Chave.nomeM) == 0) {
            *pX = pLista->ItemM[cont].Chave;
            for (cont += 1; cont < pLista->Ultimo; cont++) {
                pLista->ItemM[cont - 1] = pLista->ItemM[cont];
            }
            pLista->Ultimo--;
        }
    }
    return 1;
}

void LimprimeM(TListaMineral* pLista) {
    int i;
    for (i = pLista->Primeiro; i < pLista->Ultimo; i++) {
         printf("Nome: %s, Dureza: %.2f, Reatividade: %.2f, Cor: %s\n",
               pLista->ItemM[i].Chave.nomeM,
               pLista->ItemM[i].Chave.dureza,
               pLista->ItemM[i].Chave.reatividade,
               pLista->ItemM[i].Chave.cor);
    }
}

int TMListaM(TListaMineral *pLista)
{
    int count = 0;
    for (int cont = pLista->Primeiro; cont < pLista->Ultimo; cont++){
        count++;
    }
    
    return count;
}

void PListaMinerais(TListaMineral* pLista, TMineral* mineral) {
    FLVaziaM(pLista);

    TMineral Ferrolita = preenche_mineral(mineral, "Ferrolita", 0.5, 0.7, "Cinza");
    TMineral Solarium = preenche_mineral(mineral, "Solarium", 0.9, 0.2, "Amarelo");
    TMineral Aquavitae = preenche_mineral(mineral, "Aquavitae", 0.5, 0.8, "Azul");
    TMineral Terranita = preenche_mineral(mineral, "Terranita", 0.7, 0.6, "Marrom");
    TMineral Calaris = preenche_mineral(mineral, "Calaris", 0.6, 0.5, "Vermelho");

    LInsereM(pLista, Ferrolita);
    LInsereM(pLista, Solarium);
    LInsereM(pLista, Aquavitae);
    LInsereM(pLista, Terranita);
    LInsereM(pLista, Calaris);
}