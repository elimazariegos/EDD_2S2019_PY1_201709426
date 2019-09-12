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
#include<stdlib.h>

using namespace std;




class Lista_Filtro {
public:
    Nodo_Filtro* cabeza = 0;
    Nodo_Filtro* cola = 0;
    Cubo* cubo = 0;
    int size = 0;
    bool esta_vacia();
    void insertar_al_frente(string filtro_, string capa_);
    Lista_Filtro(Cubo* cubo_);
private:

};

#endif	/* LISTA_FILTRO_H */

