/* 
 * File:   Nodo_ABB.h
 * Author: Samuel
 *
 * Created on 7 de septiembre de 2019, 12:53 AM
 */

#ifndef NODO_ABB_H
#define	NODO_ABB_H

#include "Capa.h"
#include "Cubo.h"


class Nodo_ABB {
public:
    Nodo_ABB* derecho;
    Nodo_ABB* izquierdo;
    Cubo* cubo;
    Nodo_ABB();
    Nodo_ABB(Cubo* cubo_);
private:

};

#endif	/* NODO_ABB_H */

