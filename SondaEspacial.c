#include <stdio.h>
#include <stdlib.h>
#include "SondaEspacial.h"
#include <time.h>
#define parteNulaSonda 0

void ligaSonda(SondaMarte* sonda){
    set_status(sonda, 1);
}
void desligaSonda(SondaMarte* sonda){
    set_status(sonda, 0);
}

int gerarNumeroAleatorio(){
    return (rand() % 300) + 99;  // Gerar ID aleatorio para Sonda
}

void setIdentificadorSonda(SondaMarte* sonda, int identificador){
    sonda->identificadorSonda = identificador;
}
void set_lat(SondaMarte* sonda, float lat){
    sonda->latSonda = lat;
}
void set_long(SondaMarte* sonda, float longS){
    sonda->longSonda = longS;
}
void set_status(SondaMarte* sonda, StatusSonda status){
    sonda->status = status;
}
void set_CapacidadeSonda(SondaMarte* sonda, float capacidadeSonda){
    sonda->capacidadeSonda = capacidadeSonda;
}
void set_VelSonda(SondaMarte* sonda, float vel){
    sonda->velSonda = vel;
}
void set_CombustivelSonda(SondaMarte* sonda, float combustivel){
    sonda->combustivelSonda = combustivel;
}

void moveSonda(SondaMarte* sonda){
    float lat;
    float longS;

    printf("Digite a nova Latitude:  \n");
    scanf("%f", &lat);
    printf("Digite a nova Longitude:  \n");
    scanf("%f", &longS);
    set_lat(sonda, lat);
    set_long(sonda, longS);
}

void imprimeCompartimentoSonda2(TListaRocha *compartimento) {
    ApontadorRocha pAux = compartimento->pPrimeiro->pProx;
    
    if (pAux == NULL) {
        printf("(compartimento vazio!)\n");
    }

    while (pAux != NULL) {
        printf("%s %1.f\n", pAux->Item.Chave->categoria, pAux->Item.Chave->peso);
        pAux = pAux->pProx; 

    } 
}

void imprimeSonda(SondaMarte sonda) {
    printf("Identificador: %d\n", sonda.identificadorSonda);
    printf("Latitude da Sonda: %f\n", sonda.latSonda);
    printf("Longitude da Sonda: %f\n", sonda.longSonda);
    // imprimirCompartimentoSonda(&sonda);
    imprimeCompartimentoSonda2(&sonda.CompartimentoSonda);
    printf("Status da Sonda: ");
    switch (sonda.status) {
        case 0: printf("Desligada\n"); break;
        case 1: printf("Ligada\n"); break;
    }

    printf("Capacidade da Sonda: %f\n", sonda.capacidadeSonda);
    printf("Velocidade da Sonda: %f\n", sonda.velSonda);
    printf("Combustível da Sonda: %f\n", sonda.combustivelSonda);
    printf("Peso atual: %f\n", sonda.pesoAtual);
    printf("\n");
}

SondaMarte inicializaSondaTexto(SondaMarte* sonda,float lat_i,float lon_i,float c_i,float v_i, float nc_i){
    FLVaziaC(&sonda->CompartimentoSonda);
    int numeroAleatorio;
    numeroAleatorio = gerarNumeroAleatorio();
    setIdentificadorSonda(sonda, numeroAleatorio);
    set_status(sonda, 1); //Apartir da struct Status já inicio a sonda como ligada 
    set_lat(sonda,lat_i);
    set_long(sonda,lon_i);
    set_CapacidadeSonda(sonda,c_i);
    set_VelSonda(sonda,v_i);
    set_CombustivelSonda(sonda,nc_i);


    return *sonda;
}

void InsereRochaSonda(SondaMarte *sonda, TListaRocha *compartimento) {
     sonda->CompartimentoSonda = *compartimento;
}

void imprimirCompartimentoSonda(SondaMarte *sonda) {
    if (sonda == NULL) {
        printf("Erro: a sonda é nula.\n");
        return;
    }
    TListaRocha *listaRochaSondas = &sonda->CompartimentoSonda;
    ApontadorRocha atual = listaRochaSondas->pPrimeiro;
    while (atual != NULL)
    {
        TRocha *rocha = atual->Item.Chave;
        if(rocha != NULL){
            printf("%s %f\n", rocha->categoria, rocha->peso);
        }
        atual = atual->pProx;
    }
}