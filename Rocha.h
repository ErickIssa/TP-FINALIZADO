#ifndef ROCHA_H
#define ROCHA_H

#include "ListaMineral.h"

typedef struct
{
    int identificador;
    TListaMineral *lista_mineral;
    char categoria[50];
    float peso;
    float lat_rocha, long_rocha;
    int data;
} TRocha;

TRocha preenche_rocha(TRocha* rocha, float lat_rocha, float long_rocha, float peso, TListaMineral* lista_mineral);
double get_peso(TRocha *rocha);
int get_data(TRocha *rocha);
char *get_localizacao(TRocha *rocha);

void set_identificador(TRocha *rocha, int identificador);
void set_listaminerais(TRocha *rocha, TListaMineral *lista_mineral);
void set_categoria(TRocha *rocha, char *categoria);
void set_peso(TRocha *rocha, float peso);
void set_latRocha(TRocha *rocha, float lat_rocha);
void set_longRocha(TRocha *rocha, float long_rocha);
void set_data(TRocha *rocha, int data);

char* classificar(TListaMineral *pListaC);

#endif // ROCHA_H
