#ifndef MINERAL_H
#define MINERAL_H

typedef struct 
{
    char nomeM[50], cor[50];
    float dureza, reatividade;
} TMineral;

TMineral preenche_mineral(TMineral* mineral, char *nomeM, float dureza, float reatividade, char *cor);
TMineral preenche_mineral2(TMineral*mineral, char *nomeM);

char* get_nomeM(TMineral* mineral);
float get_dureza(TMineral* mineral);
float get_reatividade(TMineral* mineral);
char* get_cor(TMineral* mineral);

void set_nomeM(TMineral* mineral, char *nomeM);
void set_dureza(TMineral* mineral, float dureza);
void set_reatividade(TMineral* mineral, float reatividade);
void set_cor(TMineral* mineral, char *cor);

#endif // MINERAL_H