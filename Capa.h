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
    bool esta_vacia();
    Nodo_Capa* exist_fila(int y);
    Nodo_Capa* exist_columna(int x);
private:

};

#endif	/* CAPA_H */

