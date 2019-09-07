/* 
 * File:   Nodo_Cubo.h
 * Author: Samuel
 *
 * Created on 6 de septiembre de 2019, 11:09 PM
 */

#ifndef NODO_CUBO_H
#define	NODO_CUBO_H

#include "Capa.h"


class Nodo_Cubo {
public:
    Capa* capa;
    Nodo_Cubo* sig;
    int pos_z;
    Nodo_Cubo();
    Nodo_Cubo(Capa* capa_);
private:

};

#endif	/* NODO_CUBO_H */

