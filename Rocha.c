#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Rocha.h"

TRocha preenche_rocha(TRocha* rocha, float lat_rocha, float long_rocha, float peso, TListaMineral* lista_mineral) {
     //inicia lista mineral na rocha
    set_listaminerais(rocha, lista_mineral);
    set_latRocha(rocha, lat_rocha);
    set_longRocha(rocha, long_rocha);
    set_peso(rocha, peso);
    char* classificacao = classificar(lista_mineral);
    set_categoria(rocha, classificacao);

    return *rocha;
}

double get_peso(TRocha *rocha) {
    return rocha->peso;
}

int get_data(TRocha *rocha) {
    return rocha->data;
}

void set_listaminerais(TRocha* rocha, TListaMineral *lista_mineral) {
    rocha->lista_mineral = lista_mineral;
}

void set_categoria(TRocha *rocha, char *categoria) {
    strcpy(rocha->categoria, categoria);
}

void set_identificador(TRocha *rocha, int identificador) {
    rocha->identificador = identificador;
}

void set_latRocha(TRocha *rocha, float lat_rocha) {
    rocha->lat_rocha = lat_rocha;
}

void set_longRocha(TRocha *rocha, float long_rocha) {
    rocha->long_rocha = long_rocha;
}

void set_peso(TRocha *rocha, float peso) {
    rocha->peso = peso;
}

void set_data(TRocha *rocha, int data) {
    rocha->data = data;
}

char* classificar(TListaMineral *pListaC)
{
    int aux = TMListaM(pListaC);
    if (aux == 0) {
        printf("Nao tem mineral\n");
        return "0";
    }
    
    if (aux == 1)
    {
        {
            if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Ferrolita") == 0)
            {
                return "Ferrom";
            }
            else if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Solarium") == 0)
            {
                return "Solaris";
            }
        }
    }
    if (aux == 2)
    {
        if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Terranita") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Terranita")) == 0)
        {
            if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Calaris") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Calaris")) == 0){
                return "Terrolis";
            }
            else if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Solarium") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Solarium")) == 0){
                return "Terrasol";
            }
            else if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Aquavitae") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Aquavitae")) == 0){
                return "Aquaterra";
            }
            else if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Ferrolita") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Ferrolita")) == 0){
                return "Terralis";
            }
        }
        if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Aquavitae") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Aquavitae") == 0)){
            if(strcmp(pListaC->ItemM[0].Chave.nomeM, "Calaris") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Calaris")) == 0){
                return "Calquer";
            }
        }
        if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Ferrolita") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Ferrolita")) == 0){
            if (strcmp(pListaC->ItemM[0].Chave.nomeM, "Solarium") == 0 || (strcmp(pListaC->ItemM[1].Chave.nomeM, "Solarium")) == 0){
                return "Solarisfer";
            }
        }   
    }
    if (aux == 3) {
        return "Aquacalis";
    }
    return NULL;
}