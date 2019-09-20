/* 
 * File:   Lista_Filtro.h
 * Author: Samuel
 *
 * Created on 11 de septiembre de 2019, 11:34 PM
 */

#ifndef LISTA_FILTRO_H
#define	LISTA_FILTRO_H

#include "Nodo_Filtro.h"
#include "Cubo.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
#include<string>

using namespace std;

class Lista_Filtro {
public:
    Nodo_Filtro* cabeza = 0;
    Nodo_Filtro* cola = 0;
    Cubo* cubo = 0;
    int size = 0;
    bool esta_vacia();
    void insertar_al_frente(string filtro_, string capa_, Cubo* cubo_);

    Nodo_Filtro* buscar(int index_);
    Capa* filtro_bn(Capa* capa);
    Capa* filtro_neg(Capa* capa);
    Capa* filtro_esp_x(Capa* capa);
    Capa* filtro_esp_y(Capa* capa);
    Capa* filtro_esp_xy(Capa* capa);

    template <typename T>
    string to_string(T n) {
        ostringstream os;
        os << n;
        return os.str();
    }
    

    Lista_Filtro(Cubo* cubo_);
private:

};

#endif	/* LISTA_FILTRO_H */

