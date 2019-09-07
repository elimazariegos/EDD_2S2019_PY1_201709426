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
        while(aux != 0){
            if(aux->fila == y){
                return aux;
            }
            aux = aux->abajo;
        }
    }
}
Nodo_Capa* Capa::exist_columna(int x){
    if(esta_vacia()){return 0;}
    else{
        Nodo_Capa* aux = cabecera;
        while(aux != 0){
            if(aux->columna == x){
                return aux;
            }
            aux = aux->sig;
        }
    }
}