/* 
 * File:   Arbol_ABB.cpp
 * Author: Samuel
 * 
 * Created on 7 de septiembre de 2019, 12:55 AM
 */

#include "Arbol_ABB.h"

Arbol_ABB::Arbol_ABB() {
}
void Arbol_ABB::insertar_nodo(Cubo* cubo_){
    if(esta_vacio()){
        raiz = new Nodo_ABB(cubo_);
        raiz->derecho = raiz->izquierdo = 0;                
    }else{
        insertar_nodo(cubo_, raiz);
    }
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

