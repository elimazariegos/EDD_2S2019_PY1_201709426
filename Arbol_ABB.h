/* 
 * File:   Arbol_ABB.h
 * Author: Samuel
 *
 * Created on 7 de septiembre de 2019, 12:55 AM
 */

#ifndef ARBOL_ABB_H
#define	ARBOL_ABB_H

#include "Nodo_ABB.h"


class Arbol_ABB {
public:
    Arbol_ABB();
    Nodo_ABB* raiz = 0;
    void insertar_nodo(Cubo* cubo_);
    void insertar_nodo(Cubo* cubo_, Nodo_ABB* tmp);
    bool esta_vacio();
private:

};

#endif	/* ARBOL_ABB_H */

