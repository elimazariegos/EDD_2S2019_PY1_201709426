/* 
 * File:   Capa.h
 * Author: Samuel
 *
 * Created on 6 de septiembre de 2019, 09:40 PM
 */

#ifndef CAPA_H
#define	CAPA_H

#include "Nodo_Capa.h"
#include<string>
#include<stdlib.h>
using namespace std;


class Capa {
public:
    Nodo_Capa* cabecera;
    int max_fila;
    int max_columna;
    string nombre;
    
    Capa();
    Capa(string nombre_);
    bool esta_vacia();
    Nodo_Capa* exist_fila(int y);
    Nodo_Capa* exist_columna(int x);
    Nodo_Capa* crear_fila(int y);
    Nodo_Capa* crear_columna(int x); 
    void insertar_nodo(int y, int x, string color);
    void imprimir();
private:

};

#endif	/* CAPA_H */

