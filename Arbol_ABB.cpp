/* 
 * File:   Arbol_ABB.cpp
 * Author: Samuel
 * 
 * Created on 7 de septiembre de 2019, 12:55 AM
 */

#include "Arbol_ABB.h"

Arbol_ABB::Arbol_ABB() {
    size = 0;
}
void Arbol_ABB::insertar_nodo(Cubo* cubo_){
    if(esta_vacio()){
        raiz = new Nodo_ABB(cubo_);
        raiz->derecho = raiz->izquierdo = 0;                
    }else{
        insertar_nodo(cubo_, raiz);
    }
    size++;
}
void Arbol_ABB::insertar_nodo(Cubo* cubo_, Nodo_ABB* tmp) {
    if(cubo_->nombre < tmp->cubo->nombre){
        if(tmp->izquierdo != 0){
            insertar_nodo(cubo_, tmp->izquierdo);
        }else{
            tmp->izquierdo = new Nodo_ABB(cubo_);
            tmp->derecho = tmp->izquierdo->izquierdo = 0;            
        }
    }else{
        if(tmp->derecho != 0){
            insertar_nodo(cubo_, tmp->derecho);
        }else{
            tmp->derecho = new Nodo_ABB(cubo_);
            tmp->derecho->derecho = tmp->derecho->izquierdo = 0;
        }
    }
}
bool Arbol_ABB::esta_vacio(){return raiz == 0;}

Nodo_ABB* Arbol_ABB::buscar(string nombre, Nodo_ABB* tmp) {
    Nodo_ABB* arbol = 0;
    if (!esta_vacio()) {
        if (nombre == tmp->cubo->nombre) {
            return tmp;
        } else {
            if (tmp->derecho != 0 and tmp->izquierdo != 0) {
                if (nombre < tmp->cubo->nombre) {
                    arbol = buscar(nombre, tmp->izquierdo);
                } else {
                    arbol = buscar(nombre, tmp->derecho);
                }
            }
        }
    }
    return arbol;
}