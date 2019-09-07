/* 
 * File:   Capa.cpp
 * Author: Samuel
 * 
 * Created on 6 de septiembre de 2019, 09:40 PM
 */

#include "Capa.h"

Capa::Capa() {
}
bool Capa::esta_vacia(){return cabecera ==0;}

Nodo_Capa* Capa::exist_fila(int y){
    if(esta_vacia()){return 0;}
    else{
        Nodo_Capa* aux = cabecera;
        while(aux != 0){if(aux->fila == y){return aux;}
            aux = aux->abajo;
        }
    }
}
Nodo_Capa* Capa::exist_columna(int x){
    if(esta_vacia()){return 0;}
    else{
        Nodo_Capa* aux = cabecera;
        while(aux != 0){if(aux->columna == x){return aux;}
            aux = aux->sig;
        }
    }
}

Nodo_Capa* Capa::crear_fila(int y){
    Nodo_Capa* tmp = cabecera;
    while(tmp->abajo !=0){tmp = tmp->abajo;}
    for(int i = max_fila; i < y; i++){
        Nodo_Capa* nuevo = new Nodo_Capa(i + 1, 0, "");
        nuevo->abajo = nuevo->sig = nuevo->ant = 0;
        tmp->abajo = nuevo;
        nuevo->arriba = tmp;
        tmp = nuevo;
    }
    max_fila = y;
    return tmp;
}
Nodo_Capa* Capa::crear_columna(int x) {
    Nodo_Capa* tmp = cabecera;
    while (tmp->sig != 0) {tmp = tmp->sig;}
    for (int i = max_columna; i < x; i++) {
        Nodo_Capa* nuevo = new Nodo_Capa(0, i + 1, "");
        nuevo->sig = nuevo->abajo = nuevo->arriba = 0;
        tmp->sig = nuevo;
        nuevo->ant = tmp;
        tmp = nuevo;
    }
    max_columna = x;
    return tmp;
}