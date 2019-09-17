/* 
 * File:   Lista_Filtro.cpp
 * Author: Samuel
 * 
 * Created on 11 de septiembre de 2019, 11:34 PM
 */

#include "Lista_Filtro.h"

Lista_Filtro::Lista_Filtro(Cubo* cubo_) {
    this->cubo = cubo_;
    cabeza = 0;
    cola = 0;
}
bool Lista_Filtro::esta_vacia(){return cabeza == 0;}

void Lista_Filtro::insertar_al_frente(string filtro_, string capa_){
    Nodo_Filtro* nuevo = new Nodo_Filtro(filtro_, capa_);
    nuevo->index = size+1;
    if(esta_vacia()){
        cabeza = nuevo;
        cabeza->ant = cabeza;
        cabeza->sig = cabeza;
        cola = cabeza;
    }else{
        Nodo_Filtro* aux  = cola;
        cola = nuevo;
        cola->ant = aux;
        aux->sig = cola;
        cola->sig = cabeza;
        cabeza->ant = cola;
    }
    size = size + 1;
    cout << "se inserto correctamente el filtro" << endl;
}

Nodo_Filtro* Lista_Filtro::buscar(int index_){
    if(esta_vacia()){
        return 0;
    }else{
        Nodo_Filtro* aux = cabeza;
        do{
            if(aux->index == index_){
                return aux;
            }
            aux = aux->sig;
        }while(aux != cabeza);
    }
}

