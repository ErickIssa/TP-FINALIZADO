#include "Mineral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TMineral preenche_mineral(TMineral* mineral, char *nomeM, float dureza, float reatividade, char *cor) {
    set_nomeM(mineral, nomeM);
    set_dureza(mineral, dureza);
    set_reatividade(mineral, reatividade);
    set_cor(mineral, cor);

    return *mineral; 
}
TMineral preenche_mineral2(TMineral*mineral, char *nomeM) {
    set_nomeM(mineral, nomeM);

    return *mineral;
}

char* get_nomeM(TMineral* mineral) {
    return mineral->nomeM;
}

float get_dureza(TMineral* mineral) {
    return mineral->dureza;
}

float get_reatividade(TMineral* mineral) {
    return mineral->reatividade;
}

char* get_cor(TMineral* mineral) {
    return mineral->cor;
}

void set_nomeM(TMineral* mineral, char *nomeM) {
    strcpy(mineral->nomeM, nomeM);
}

void set_dureza(TMineral* mineral, float dureza) {
    mineral->dureza = dureza;
}

void set_reatividade(TMineral* mineral, float reatividade) {
    mineral->reatividade = reatividade;
}

void set_cor(TMineral* mineral, char *cor) {
    strcpy(mineral->cor, cor);
}