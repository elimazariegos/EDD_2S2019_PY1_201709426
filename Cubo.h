/* 
 * File:   Cubo.h
 * Author: Samuel
 *
 * Created on 6 de septiembre de 2019, 11:10 PM
 */

#ifndef CUBO_H
#define	CUBO_H

#include "Nodo_Cubo.h"


class Cubo {
public:
    Cubo();
    Cubo(string nombre_);
    Nodo_Cubo* cabeza = 0;
    string nombre;
    int fila_mayor = 0;
    int columna_mayor = 0;
    int size = 0;
    bool esta_vacia();
    void insertar_capa(Capa* capa_);
    
    
   
    
private:

};

#endif	/* CUBO_H */

