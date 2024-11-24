#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaSondas.h"

void iniciaListaSonda(listaSonda* pLista){ // com cabeça inicia com celula chave.
    pLista->primaSonda = (apontador) malloc(sizeof(celulaSonda));
    pLista->ultSonda = pLista->primaSonda;
    pLista->primaSonda->pProxSonda = NULL;
}
void insereSonda(listaSonda* pLista, SondaMarte xSonda){
    pLista->ultSonda->pProxSonda = (apontador) malloc(sizeof(celulaSonda));
    pLista->ultSonda = pLista->ultSonda->pProxSonda;
    pLista->ultSonda->chaveSonda = xSonda;
    pLista->ultSonda->pProxSonda = NULL;

}
void retiraSonda(listaSonda* plista){
    int idRetira;
    celulaSonda* atual = plista->primaSonda;
    celulaSonda* anterior = NULL;

    printf("Digite o ID da sonda para ser retirada: ");
    scanf("%d", &idRetira);

    while (atual != NULL && atual->chaveSonda.identificadorSonda != idRetira)
    {
        anterior = atual;
        atual = atual->pProxSonda;
    }
     if (atual == NULL) { //Olha se a sonda existe mesmo, se não, retorna uma mensagem
        printf("Sonda não existe com esse ID: %d\n", idRetira);
        return;// encerra codigo
    } 
    if(anterior == NULL){
        plista->primaSonda = atual->pProxSonda; //remove primeira
    } else {
        anterior->pProxSonda = atual->pProxSonda; // remove meio ou fim
    }
    free(atual);
    printf("Sonda Removida :)\n");
}

void ImprimeListaSondas(listaSonda* plista){

    celulaSonda* atual = plista->primaSonda->pProxSonda;

    while(atual != NULL){

        imprimeSonda(atual->chaveSonda);
        atual = atual->pProxSonda;
    }
}

void Imprime_I_Lista(listaSonda* plista){

    celulaSonda* atual = plista->primaSonda->pProxSonda;

    while(atual != NULL) {
        printf("Identificador: %d\n",atual->chaveSonda.identificadorSonda);
        imprimeCompartimentoSonda2(&atual->chaveSonda.CompartimentoSonda);
        atual = atual->pProxSonda;
    }
}

SondaMarte* dist_euclidiana(listaSonda* plista, float lat_R, float long_R){ //colocar na .h
    celulaSonda* atual = plista->primaSonda->pProxSonda;
    float menorDist = 1000000;
    float lat_S;
    float lon_S;
    float distAtual = 0;
    SondaMarte* sondaproxima;
    while(atual != NULL){
        lat_S = atual->chaveSonda.latSonda;
        lon_S = atual->chaveSonda.longSonda;
        distAtual = sqrt(pow(lat_R - lat_S, 2) + pow(long_R - lon_S, 2));
        if (menorDist >= distAtual){
            menorDist = distAtual;
            sondaproxima = &atual->chaveSonda;
        }
        atual = atual->pProxSonda;
    }
    return sondaproxima;
}

void operacaoR(listaSonda *ListaSonda, TRocha *rocha) {
    SondaMarte *sondaAmz = NULL; // armazena uma possível sonda que irá coletar
    float lat_i = rocha->lat_rocha;
    float long_i = rocha->long_rocha;

    apontador pAux = ListaSonda->primaSonda->pProxSonda;
    SondaMarte *sonda = NULL;
    

    while (pAux != NULL) {
        sonda = &pAux->chaveSonda;
        float verificarcap = sonda->capacidadeSonda - rocha->peso;
        
        if (verificarcap >= rocha->peso) {
            sondaAmz = dist_euclidiana(ListaSonda, lat_i, long_i);
        }
        pAux = pAux->pProxSonda;
    }
    if (sondaAmz == NULL) {
        printf("ERRO! Nao tem sonda perto\n");
    }
    sondaAmz->latSonda = rocha->lat_rocha;
    sondaAmz->longSonda = rocha->long_rocha; // a sonda vai até o local onde está a rocha
    
    if (sondaAmz->CompartimentoSonda.pPrimeiro == NULL) {
        sondaAmz->CompartimentoSonda.pPrimeiro = (TCelulaRocha*)malloc(sizeof(TCelulaRocha));
        sondaAmz->CompartimentoSonda.pPrimeiro->pProx = NULL;
        sondaAmz->CompartimentoSonda.pUltimo = sondaAmz->CompartimentoSonda.pPrimeiro;
    }
    TCelulaRocha *novarocha = (TCelulaRocha*) malloc(sizeof(TCelulaRocha));

    TRocha *novaRocha = (TRocha*) malloc(sizeof(TRocha));
    *novaRocha = *rocha; // Copia os valores de 'rocha' para a nova estrutura
    novarocha->Item.Chave = novaRocha;

    if (sondaAmz->CompartimentoSonda.pPrimeiro == NULL) {
        sondaAmz->CompartimentoSonda.pUltimo = novarocha;
    } 
    else {
        sondaAmz->pesoAtual = sondaAmz->pesoAtual + novarocha->Item.Chave->peso;
        sondaAmz->CompartimentoSonda.pUltimo->pProx = novarocha;
        sondaAmz->CompartimentoSonda.pUltimo = novarocha;
    }
    // sonda->capacidadeSonda -= rocha->peso;
    
    printf("--------------------------------\n");
    printf("Rocha coletada!\nSonda: %d\n", sondaAmz->identificadorSonda);
}

void pontoComumSondas(listaSonda* sondasLista){ // colocar no .h
    celulaSonda* atual = sondasLista->primaSonda->pProxSonda;
    while(atual != NULL){
        atual->chaveSonda.latSonda = 0;
        atual->chaveSonda.longSonda = 0;
        atual = atual->pProxSonda;
    }
}

int categoria_repete(SondaMarte *sonda, char *categoria, float peso) {
    TCelulaRocha *pAux = sonda->CompartimentoSonda.pPrimeiro->pProx;
    while (pAux != NULL) {
        if (strcmp(pAux->Item.Chave->categoria, categoria) == 0 && pAux->Item.Chave->peso < peso) {
            return 1;
        }
        pAux = pAux->pProx;
    }
    return 0;
}
float mediaPesos(listaSonda* sondaLista){
    
    celulaSonda* atual = sondaLista->primaSonda->pProxSonda;
    float pesototal;

    while(atual != NULL) {
        pesototal = atual->chaveSonda.pesoAtual + pesototal;
        atual = atual->pProxSonda;
    }
    return pesototal;
}

void removeRochasDeTodasSondas(TListaRocha *compartimento, TListaRocha *listaRochasRemovidas){
    while (!LEhVaziaC(compartimento))
    {
        TRocha *novaRocha = (TRocha*) malloc(sizeof(TRocha));
        RemoveUltimaRocha(compartimento, novaRocha);
        LInsereC(listaRochasRemovidas, novaRocha);
    }
}

void operacao_E(listaSonda* sondaLista, int qtdSondas){
    float PesoTsondas = 0;
    TListaRocha listatempo;
    FLVaziaC(&listatempo);

    celulaSonda *atual = sondaLista->primaSonda->pProxSonda;
    

    while(atual != NULL) {
        atual->chaveSonda.pesoAtual = 0;
        removeRochasDeTodasSondas(&atual->chaveSonda.CompartimentoSonda, &listatempo);
        atual = atual->pProxSonda;
    }
    
    ApontadorRocha pAux = listatempo.pPrimeiro->pProx;
    
    LImprimeC(listatempo);
    while (pAux != NULL) {
        PesoTsondas += pAux->Item.Chave->peso;
        pAux = pAux->pProx;
    }
    PesoTsondas = PesoTsondas/qtdSondas;
    ApontadorRocha RochaAtual = listatempo.pPrimeiro->pProx;
    while(RochaAtual != NULL){
        retornar_rochas(sondaLista, RochaAtual->Item.Chave, PesoTsondas);
        RochaAtual = RochaAtual->pProx;
    }

}

// void retornar_rochas(listaSonda* sondaLista, TRocha *rocha, float media) {
//     apontador pAux = sondaLista->primaSonda;

//     while (pAux != sondaLista->ultSonda) {
//         while (pAux->chaveSonda.pesoAtual <= media) {
//             printf("inseriu\n");
//             pAux->chaveSonda.pesoAtual  += rocha->peso;
//         }
//         pAux = pAux->pProxSonda;
//     } 

// }
void retornar_rochas(listaSonda* ListaSonda, TRocha *rocha, float media) {
    SondaMarte *sondaAmz = NULL; // armazena uma possível sonda que irá coletar
    

    apontador pAux = ListaSonda->primaSonda->pProxSonda;
    

    while (pAux != NULL) {

        if (pAux->chaveSonda.pesoAtual <= media) {
            sondaAmz = &pAux->chaveSonda;
        }
        pAux = pAux->pProxSonda;
    }
    if (sondaAmz == NULL) {
        printf("ERRO! peso estorou\n");
    }
    
    if (sondaAmz->CompartimentoSonda.pPrimeiro == NULL) {
        sondaAmz->CompartimentoSonda.pPrimeiro = (TCelulaRocha*)malloc(sizeof(TCelulaRocha));
        sondaAmz->CompartimentoSonda.pPrimeiro->pProx = NULL;
        sondaAmz->CompartimentoSonda.pUltimo = sondaAmz->CompartimentoSonda.pPrimeiro;
    }
    TCelulaRocha *novarocha = (TCelulaRocha*) malloc(sizeof(TCelulaRocha));

    TRocha *novaRocha = (TRocha*) malloc(sizeof(TRocha));
    *novaRocha = *rocha; // Copia os valores de 'rocha' para a nova estrutura
    novarocha->Item.Chave = novaRocha;

    if (sondaAmz->CompartimentoSonda.pPrimeiro == NULL) {
        sondaAmz->CompartimentoSonda.pUltimo = novarocha;
    } 
    else {
        sondaAmz->pesoAtual = sondaAmz->pesoAtual + novarocha->Item.Chave->peso;
        sondaAmz->CompartimentoSonda.pUltimo->pProx = novarocha;
        sondaAmz->CompartimentoSonda.pUltimo = novarocha;
    }
    // sonda->capacidadeSonda -= rocha->peso;
    
    printf("--------------------------------\n");
    printf("Rocha coletada!\nSonda: %d\n", sondaAmz->identificadorSonda);

}
