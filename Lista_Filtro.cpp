/* 
 * File:   Lista_Filtro.cpp
 * Author: Samuel
 * 
 * Created on 11 de septiembre de 2019, 11:34 PM
 */

#include "Lista_Filtro.h"

Lista_Filtro::Lista_Filtro(Cubo* cubo_) {
    this->cubo = cubo_;
}
bool Lista_Filtro::esta_vacia(){return cabeza == 0;}

void Lista_Filtro::insertar_al_frente(string filtro_, string capa_){
    Nodo_Filtro* nuevo = new Nodo_Filtro(filtro_, capa_);
    nuevo->index = size+1;
    if(esta_vacia()){
        cabeza = cola = nuevo;
        cabeza->ant = cabeza;
        cola->ant = cabeza;
    }else{
        Nodo_Filtro* aux  = cabeza;
        cola  = nuevo;
        cola->ant = aux;
        aux->sig = cola;
        cola->sig = cabeza;
        cabeza->ant = cola;
    }
    size++;
}

