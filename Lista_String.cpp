/* 
 * File:   Lista_String.cpp
 * Author: Samuel
 * 
 * Created on 9 de septiembre de 2019, 12:35 AM
 */

#include "Lista_String.h"


Lista_String::Lista_String() {
}
bool Lista_String::esta_vacia(){
    return cabeza == 0;
}
void Lista_String::insertar(string dato){
    Nodo_String* nuevo = new Nodo_String();
    nuevo->dato = dato;
    nuevo->index = size +1;
    if(esta_vacia()){
        cabeza = nuevo;
        cabeza->sig = 0;
    }else{
        Nodo_String* aux = cabeza;
        while(aux->sig != 0){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        aux->sig->sig=0;
    }    
    size++;
}
string Lista_String::buscar(int index){
    if(esta_vacia()){
        return "";
    }else{
        Nodo_String* aux = cabeza;
        while(aux != 0){
            if(aux->index = index){
                return aux->dato;
            }
            aux = aux->sig;
        } 
    }
    
}