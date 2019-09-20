/* 
 * File:   Nodo_Filtro.cpp
 * Author: Samuel
 * 
 * Created on 11 de septiembre de 2019, 11:48 PM
 */

#include "Nodo_Filtro.h"

Nodo_Filtro::Nodo_Filtro() {
}
Nodo_Filtro::Nodo_Filtro(string filtro_, string capa_, Cubo* cub_){
    this->filtro = filtro_;
    this->capa = capa_;
    this->cub = cub_;
}

