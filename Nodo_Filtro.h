/* 
 * File:   Nodo_Filtro.h
 * Author: Samuel
 *
 * Created on 11 de septiembre de 2019, 11:48 PM
 */

#ifndef NODO_FILTRO_H
#define	NODO_FILTRO_H
#include<iostream>
#include<stdlib.h>

using namespace std;
class Nodo_Filtro {
public:
    string filtro = "";
    string capa = "";
    int index  = 0;
    Nodo_Filtro*sig;
    Nodo_Filtro*ant;
    Nodo_Filtro(string filtro_, string capa_);
    Nodo_Filtro();
private:

};

#endif	/* NODO_FILTRO_H */

