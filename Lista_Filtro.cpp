/* 
 * File:   Lista_Filtro.cpp
 * Author: Samuel
 * 
 * Created on 11 de septiembre de 2019, 11:34 PM
 */

#include "Lista_Filtro.h"
#include "Cubo.h"
#include "Capa.h"
#include "Nodo_Capa.h"

Lista_Filtro::Lista_Filtro(Cubo* cubo_) {
    this->cubo = cubo_;
    cabeza = 0;
    cola = 0;
}
bool Lista_Filtro::esta_vacia(){return cabeza == 0;}

Capa* Lista_Filtro::filtro_esp_x(Capa* capa){
    Capa* nueva = new Capa(capa->nombre);
    Nodo_Capa* aux = capa->cabecera->abajo->sig;
    while(aux->sig != 0){
        aux = aux->sig;
    }
    int y = 1;
    int x = 1;
    while(aux != 0){
        Nodo_Capa* aux_c = aux;
        while(aux_c->ant != 0){
            nueva->insertar_nodo(y,x,aux_c->color);
            aux_c = aux_c->ant;
            x++;
        }
        x=1;
        y++;
        aux = aux->abajo;
    }
    return nueva;
}
Capa* Lista_Filtro::filtro_esp_y(Capa* capa){
    Capa* nueva = new Capa(capa->nombre);
    Nodo_Capa* aux = capa->cabecera->abajo->sig;
    while(aux->abajo != 0){
        aux = aux->abajo;
    }
    int y = 1;
    int x = 1;
    while(aux->arriba != 0){
        Nodo_Capa* aux_c = aux;
        while(aux_c->sig != 0){
            nueva->insertar_nodo(y,x,aux_c->color);
            aux_c = aux_c->sig;
            x++;
        }
        x=1;
        y++;
        aux = aux->arriba;
    }
    return nueva;
}

Capa* Lista_Filtro::filtro_bn(Capa* capa) {
    Capa* nueva = new Capa(capa->nombre);
    Nodo_Capa* aux = capa->cabecera->abajo;
    int y = 1;
    int x = 1;
    while(aux != 0){
        Nodo_Capa* aux_c = aux->sig;
        while(aux_c != 0){
            string color = "";
            if(aux_c->color != "x"){
                float r = aux_c->r * 0.299;
                float g = aux_c->g * 0.587;
                float b = aux_c->b * 0.144;
                float rgb = r + g + b;
                color = to_string(rgb) + "," + to_string(rgb) + "," + to_string(rgb);
            }else {
                color = "x";
            }
            nueva->insertar_nodo(y,x,color);
            aux_c = aux_c->sig;
            x++;
        }
        x=1;
        y++;
        aux = aux->abajo;
    }
    return nueva;
}
Capa* Lista_Filtro::filtro_neg(Capa* capa){
    Capa* nueva = new Capa(capa->nombre);
    Nodo_Capa* aux = capa->cabecera->abajo;
    int y = 1;
    int x = 1;
    while(aux != 0){
        Nodo_Capa* aux_c = aux->sig;
        while(aux_c != 0){
            string color = "";
            if(aux_c->color != "x"){
                color = to_string(255 - aux_c->r) + "," + to_string(255 - aux_c->g) + "," + to_string(255 - aux_c->b);
            }else{
                color = "x";
            } 
            nueva->insertar_nodo(y,x,color);
            aux_c = aux_c->sig;
            x++;
        }
        x=1;
        y++;
        aux = aux->abajo;
    }
    return nueva;
}


void Lista_Filtro::insertar_al_frente(string filtro_, string capa_, Cubo* cubo_){
    Cubo* cubo_filter = new Cubo(cubo_->nombre + filtro_, cubo_->pixel_w, cubo->pixel_h, cubo->imagen_w,cubo->imagen_h);
    Nodo_Cubo* aux_cubo = cubo_->cabeza;
    
    while(aux_cubo != 0){
        if(filtro_ == "espejo-x"){
            if(capa_ == ""){
                cubo_filter->insertar_capa(filtro_esp_x(aux_cubo->capa));
            }else{
                if(aux_cubo->capa->nombre == capa_){
                    cubo_filter->insertar_capa(filtro_esp_x(aux_cubo->capa));
                }else{
                    cubo_filter->insertar_capa(aux_cubo->capa);
                }
            }
        }else if(filtro_ == "espejo-y"){
            if(capa_ == ""){
                cubo_filter->insertar_capa(filtro_esp_y(aux_cubo->capa));
            }else{
                if(aux_cubo->capa->nombre == capa_){
                    cubo_filter->insertar_capa(filtro_esp_y(aux_cubo->capa));
                }else{
                    cubo_filter->insertar_capa(aux_cubo->capa);
                }
            }
        }else if(filtro_ == "espejo-xy"){
            if(capa_ == ""){
                cubo_filter->insertar_capa(filtro_esp_x(filtro_esp_y(aux_cubo->capa)));
            }else{
                if(aux_cubo->capa->nombre == capa_){
                    cubo_filter->insertar_capa(filtro_esp_x(filtro_esp_y(aux_cubo->capa)));
                }else{
                    cubo_filter->insertar_capa(aux_cubo->capa);
                }
            }
        }else if(filtro_ == "grises"){
            if(capa_ == ""){
                cubo_filter->insertar_capa(filtro_bn(aux_cubo->capa));
            }else{
                if(aux_cubo->capa->nombre == capa_){
                    cubo_filter->insertar_capa(filtro_bn(aux_cubo->capa));
                }else{
                    cubo_filter->insertar_capa(aux_cubo->capa);
                }
            }
        }else if(filtro_ == "negativo"){
            if(capa_ == ""){
                cubo_filter->insertar_capa(filtro_neg(aux_cubo->capa));
            }else{
                if(aux_cubo->capa->nombre == capa_){
                    cubo_filter->insertar_capa(filtro_neg(aux_cubo->capa));
                }else{
                    cubo_filter->insertar_capa(aux_cubo->capa);
                }
            }
        
        }else if(filtro_ == "mosaico"){
            cubo_filter = cubo_;
        }
        aux_cubo= aux_cubo->sig;
    }
    
    Nodo_Filtro* nuevo = new Nodo_Filtro(filtro_, capa_, cubo_filter);
    
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

