/* 
 * File:   Cubo.cpp
 * Author: Samuel
 * 
 * Created on 6 de septiembre de 2019, 11:10 PM
 */

#include "Cubo.h"

Cubo::Cubo() {
}

Cubo::Cubo(string nombre_, int pixel_w_, int pixel_h_, int imagen_w_, int imagen_h_) {
    this->nombre = nombre_;
    this->pixel_w = pixel_w_;
    this->pixel_h = pixel_h_;
    this->imagen_w = imagen_w_;
    this->imagen_h = imagen_h_; 
}

bool Cubo::esta_vacia(){return cabeza == 0;}

void Cubo::insertar_capa(Capa* capa_){
    Nodo_Cubo* nuevo = new Nodo_Cubo(capa_);
    if(esta_vacia()){
        cabeza = nuevo;
        cabeza->sig = 0;
        fila_mayor = capa_->max_fila;
        columna_mayor = capa_->max_columna;
    }else{
        Nodo_Cubo* aux = cabeza;
        while(aux->sig != 0){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        aux->sig->sig=0;
        
        if (capa_->max_fila > fila_mayor) {
            fila_mayor = capa_->max_fila;
        }
        if (capa_->max_columna > columna_mayor) {
            columna_mayor = capa_->max_columna;
        }
    }
    size = size + 1;
}

Capa* Cubo::buscar(string nombre){
    
}