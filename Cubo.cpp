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
    nuevo->index = size + 1;
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
    if(esta_vacia()){return 0;}
    else{
        Nodo_Cubo* aux = cabeza;
        while(aux != 0){
            if(aux->capa->nombre == nombre){
                return aux->capa;
            }
            aux = aux->sig;
        }
    }
}
Capa* Cubo::buscar_index(int index_){
    if(esta_vacia()){return 0;}
    else{
        Nodo_Cubo* aux = cabeza;
        while(aux != 0){
            if(aux->index == index_){
                return aux->capa;
            }
            aux = aux->sig;
        }
    }
}

void Cubo::modificar(int x, int y, string capa, int r, int g, int b){
    if(esta_vacia()){}
    else{
        Nodo_Cubo* aux = cabeza;
        while(aux != 0){
            Nodo_Capa* aux_dw = aux->capa->cabecera->abajo;  
            while(aux_dw != 0){
                Nodo_Capa* aux_sg  = aux_dw->sig;
                while(aux_sg != 0){
                    if(aux->capa->nombre == capa){
                        if(aux_sg->fila == y and aux_sg->columna == x){
                            aux_sg->r = r;
                            aux_sg->g = g;
                            aux_sg->b = b;
                            aux_sg->color = to_string(r) + "," + to_string(g) + "," + to_string(b);
                        }
                    }
                    aux_sg = aux_sg->sig;
                }
                aux_dw = aux_dw->abajo;
            }
            aux = aux->sig;
        }
    }
}