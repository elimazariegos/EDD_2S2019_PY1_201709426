/* 
 * File:   Nodo_Capa.h
 * Author: Samuel
 *
 * Created on 6 de septiembre de 2019, 09:14 PM
 */

#ifndef NODO_CAPA_H
#define	NODO_CAPA_H

#include<string>
#include<stdlib.h>
using namespace std;

class Nodo_Capa {
public:
    Nodo_Capa* sig = 0;
    Nodo_Capa* ant = 0;
    Nodo_Capa* arriba = 0;
    Nodo_Capa* abajo = 0;
    int fila, columna = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    string color = "";
    string filtro = "";
    Nodo_Capa();
    Nodo_Capa(int fila_, int columna_, string color_);

private:

};

#endif	/* NODO_CAPA_H */

