/* 
 * File:   main.cpp
 * Author: Samuel
 *
 * Created on 2 de septiembre de 2019, 10:20 PM
 */
#include <cstdlib>
#include<sstream>
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>

#include "Cubo.h"
#include "Generador_Imagen.h"
#include "Arbol_ABB.h"
#include "Lista_String.h"
#include "Lista_Filtro.h"

using namespace std;

/*
 * 
 */
Cubo* cubo_disperso = new Cubo();
Arbol_ABB* abb = new Arbol_ABB();
Cubo* imagen_seleccionada = 0;
Lista_String* lista_img = new Lista_String();
Generador_Imagen* gn = new Generador_Imagen();
Lista_Filtro* lista_fitros = 0;

int es_entero(string ent) {
    int i = 0;
    string aux = "";
    while (i < ent.size()) {
        if (ent[i] > 47 and ent[i] < 58) {
            aux = aux + ent[i];
        } else {
            return -1;
        }
        i++;
    }
    i = atoi(aux.c_str());
    return i;
}

    string abrir_archivo(string direccion) {
        string cadena = "";
        ifstream fe(direccion);
        if (fe.good()) {
            while (!fe.eof()) {
                string linea = "";
                getline(fe, linea);
                cadena = cadena + linea;
            }
            fe.close();
        }
        return cadena;
    }

Capa* crear_capa(string cadena, string nombre) {

    int x = 1;
    int y = 1;
    string color = "";
    cadena = cadena + "\r";
    Capa* capa = new Capa(nombre);
    for (int i = 0; i < cadena.size(); i++) {
        while (cadena[i] != '\r') {
            while (cadena[i] != ',') {
                if (cadena[i] == '-') {
                    cadena[i] = ',';
                }
                color = color + cadena[i];
                i++;
                if (cadena[i] == '\r') {
                    break;
                }
            }
            if (cadena[i] == ',') {
                i++;
            }
            capa->insertar_nodo(y, x, color);
            x++;
            color = "";
        }
        x = 1;
        y++;
    }
    return capa;
}

Capa* modificacion(Cubo* &cubo){
    string capa;
    string op;
    Capa* capa_buscada = 0;
    int x = 0;
    int y = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    
    cout << "ingrese el nombre de la capa" << endl;
    cout << "-->";
    cin>>capa;
    capa_buscada = cubo->buscar(capa);
    if(capa_buscada != 0){
        cout << "ingrese la coordenada en x" << endl;
        cin>>op;
        x = es_entero(op);
        if(x>0 and x<cubo->columna_mayor){
            cout << "ingrese la coordenada en y" << endl;
            cin>>op;
            y = es_entero(op);
            if(y > 0  and y < cubo->fila_mayor){
                cout << "ingrese el valor de r" << endl;
                cin>>op;
                r = es_entero(op);
                if(r >= 0){
                    cout << "ingrese el valor de g" << endl;
                    cin>>op;
                    g = es_entero(op);
                    if(g >= 0){
                        cout << "ingrese el valor de b" << endl;
                        cin>>op;
                        r = es_entero(op);
                        if(r >= 0){
                            cubo->modificar(x,y,capa,r,g,b);
                            
                        }else{cout << "el numero b no esta en el rango 0 <= r < 255" <<endl;}
                    }else{cout << "el numero g no esta en el rango 0 <= r < 255" <<endl;}
                }else{cout << "el numero r no esta en el rango 0 <= r < 255" <<endl;}
            }else{cout << "no existe la posicion en y" <<endl;}
        }else{cout << "no existe la posicion en x" <<endl;}

    }else{cout << "No existe la capa" <<endl;}

}

void menu_edicion_manual(){
    cout << "\n[************************************************]" << endl;
    cout << "BIENVENIDO AL MENU EDICION MANUAL" << endl;
    cout << "[************************************************]" << endl;
    cout << "[1] Imagen Original" << endl;
    cout << "[2] Imagen con Filtro" << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "-->";
    string op;
    cin>>op;
    int opcion = es_entero(op);
    if(opcion == 1){
        modificacion(imagen_seleccionada);
    }else if(opcion == 2){
        Nodo_Filtro* aux = lista_fitros->cabeza;
        int i = 1;
        do{

            if(aux->filtro != "mosaico" and aux->filtro != "collage"){
                if(aux->capa == ""){
                    cout << "["<< i<<"]" << " Imagen Completa" <<"-"<< aux->filtro << endl;

                }else{
                    cout << "["<< i<<"] " << aux->capa <<"-"<< aux->filtro << endl;

                }

            }
            
            aux = aux->sig;
            if(i  == lista_fitros->size){
                break;
            }
            i++;

        }while(aux != lista_fitros->cabeza);

        cout << "[************************************************]" << endl;
        cout << "Seleccione una opcion" << endl;
        cout << "-->";
        cin>>op;
        int entrada = es_entero(op);
        if(entrada > 0){
            Nodo_Filtro* tmp_fl =  lista_fitros->buscar(entrada - 1);
            if(tmp_fl != 0){
                modificacion(tmp_fl->cub);
            }else{
                cout << "opcion incorrecta" <<endl;
            }
        }


    }
}

void menu_reportes(){
    cout << "[************************************************]" << endl;
    cout << "BIENVENIDO AL MENU INSERTAR IMAGEN" << endl;
    cout << "[************************************************]" << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "-->";
}



void llenar_lista_img(Nodo_ABB * tmp) {
    if (tmp != 0) {
        llenar_lista_img(tmp->izquierdo);
        lista_img->insertar(tmp->cubo->nombre);
        llenar_lista_img(tmp->derecho);
    }
}



void menu_seleccionar_imagen() {
    lista_img = new Lista_String();
    llenar_lista_img(abb->raiz);
    cout << "[************************************************]" << endl;
    cout << "BIENVENIDO AL MENU SELECCIONAR IMAGEN" << endl;
    cout << "[************************************************]" << endl;
    for (int i = 1; i <= lista_img->size; i++) {
        cout << "[" << i << "] " << lista_img->buscar(i) << endl;
    }
    cout << "[************************************************]" << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "-->";
    string op;
    cin>>op;
    int opcion = es_entero(op);
    if (opcion != -1) {
        imagen_seleccionada = abb->buscar(lista_img->buscar(opcion), abb->raiz)->cubo;
        cout << "[************************************************]" << endl;
        cout << "se ha seleccionado correctamente la imagen con nombre: " << lista_img->buscar(opcion) << endl;
    }
}

Cubo* crear_cubo(string config) {
    int i = 0;
    int index = 0;
    int iw, ih, pw, ph;
    iw = ih = pw = ph = 0;
    string cantidad = "";
    config = config + "\r";
    while (i < config.size()) {
        if (config[i] == '\r') {
            i++;
            break;
        }
        while (config[i] != ',') {
            i++;
        }
        if (config[i] == ',') {
            i++;
        }

        while (config[i] != '\r') {
            cantidad = cantidad + config[i];
            i++;
        }
        if (config[i] == '\r') {
            i++;
        }
        if (index == 1) {
            iw = es_entero(cantidad);
        }
        if (index == 2) {
            ih = es_entero(cantidad);
        }
        if (index == 3) {
            pw = es_entero(cantidad);
        }
        if (index == 4) {
            ph = es_entero(cantidad);
        }
        index++;
        cantidad = "";
    }
    Cubo* cubo = new Cubo("", pw, ph, iw, ih);
    return cubo;
}

void menu_insertar_imagen() {
    Cubo* cubo = new Cubo();
    cout << "[************************************************]" << endl;
    cout << "BIENVENIDO AL MENU INSERTAR IMAGEN" << endl;
    cout << "[************************************************]" << endl;
    cout << "Ingrese el nombre del archivo [Sin extencion (sin el .csv)]" << endl;
    cout << "-->";
    string nombre;
    cin>>nombre;
    string direccion = "";
    direccion = nombre + ".csv";
    string init = abrir_archivo(direccion);
    if(init != ""){
        init = init + "\r";
        int i = 0;
        int index = -1;
        string n_capa = "";
        while (i < init.size()) {

            if (init[i] == '\r') {
                i++;
                break;
            }
            while (init[i] != ',') {
                i++;
            }
            if (init[i] == ',') {
                i++;
            }
            while (init[i] != '\r') {
                n_capa = n_capa + init[i];
                i++;
            }
            if (init[i] == '\r') {
                i++;
            }

            if (index == 0) {
                cubo = crear_cubo(abrir_archivo(n_capa));
                cubo->nombre = nombre;
            }

            if (index > 0) {
                Capa* tmp;
                tmp = crear_capa(abrir_archivo(n_capa),n_capa);
                cubo->insertar_capa(tmp);
            }
            index++;
            n_capa = "";
        }
        abb->insertar_nodo(cubo);
        }else{
        cout << "No se pudo abrir el archivo" << endl;
    }
    
}

void menu_aplicar_filtros(string capa){
   if(lista_fitros == 0){
       lista_fitros = new Lista_Filtro(imagen_seleccionada);
   }     
    cout << "[1] Negativo" << endl;
    cout << "[2] Escala de Grises" << endl;
    cout << "[3] Espejo en X" << endl;
    cout << "[4] Espejo en Y" << endl;
    cout << "[5] Espejo en Ambos ejes" << endl;
    cout << "[6] Collage" << endl;
    cout << "[7] Mosaico" << endl;
    cout << "[************************************************]" << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "-->";

    string op;
    cin>>op;
    int opcion = es_entero(op);
    switch (opcion) {
        case 1:
            lista_fitros->insertar_al_frente("negativo", capa, imagen_seleccionada);
            break;
        case 2:
            lista_fitros->insertar_al_frente("grises", capa,imagen_seleccionada);
            break;
        case 3:
            lista_fitros->insertar_al_frente("espejo-x", capa, imagen_seleccionada);
            break;
        case 4:
            lista_fitros->insertar_al_frente("espejo-y", capa, imagen_seleccionada);
            break;
        case 5:
            lista_fitros->insertar_al_frente("espejo-xy", capa, imagen_seleccionada);
            break;
        case 6:
            lista_fitros->insertar_al_frente("collage", capa, imagen_seleccionada);
            break;
        case 7:
            lista_fitros->insertar_al_frente("mosaico", capa, imagen_seleccionada);
            break;
        default:
            cout << "opcion incorrecta" <<endl;
            break;
    }

}

void menu_exportar_imagen(){
    cout << "[************************************************]" << endl;
    cout << "BIENVENIDO AL SISTEMA PHOTOGEN++" << endl;
    cout << "[************************************************]" << endl;
    cout << "[1] Exportar Imagen original" << endl;
    Nodo_Filtro* aux = lista_fitros->cabeza;
    int i = 2;
    do{
        
        if(aux->capa == ""){
            cout << "["<< i<<"]" << " Imagen Completa" <<"-"<< aux->filtro << endl;
        
        }else{
            cout << "["<< i<<"] " << aux->capa <<"-"<< aux->filtro << endl;
        
        }
                
        aux = aux->sig;
        if((i - 1) == lista_fitros->size){
            break;
        }
        i++;
        
    }while(aux != lista_fitros->cabeza);
    
    cout << "[************************************************]" << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "-->";
    string ent;
    cin>>ent;
    int entrada = es_entero(ent);
    if(entrada <= i and entrada > 0){
         if(entrada == 1){
             gn->generar_imagen(imagen_seleccionada, "");
         }else{
            Nodo_Filtro* tmp_fl =  lista_fitros->buscar(entrada - 1);
                gn->generar_imagen(tmp_fl->cub, tmp_fl->filtro);
            
         }   
    }else{
        cout << "opcion incorrecta" << endl;
    }
}
void principal() {
    int opcion = -1;
    while (opcion != 0) {
        cout << "[************************************************]" << endl;
        cout << "BIENVENIDO AL SISTEMA PHOTOGEN++" << endl;
        cout << "[************************************************]" << endl;
        cout << "[1] Insertar Imagen" << endl;
        cout << "[2] Seleccionar Imagen" << endl;
        cout << "[3] Aplicar Filtros" << endl;
        cout << "[4] Edicion Manual" << endl;
        cout << "[5] Exportar Imagen" << endl;
        cout << "[6] Reportes" << endl;
        cout << "[************************************************]" << endl;
        cout << "Seleccione una opcion" << endl;
        cout << "-->";

        string op;
        cin>>op;
        opcion = es_entero(op);
        switch (opcion) {
            case 1:
                menu_insertar_imagen();
                break;
            case 2:
                if (abb->esta_vacio()) {
                    cout << "No hay imagenes cargadas en el sistema" << endl;
                } else {
                    menu_seleccionar_imagen();
                }
                break;
            case 3:
                if(imagen_seleccionada != 0){
                    cout << "[************************************************]" << endl;
                    cout << "Bienvenido a la exportacion de imagenes..." << endl;
                    cout << "[************************************************]" << endl;
                    cout << "[1] Filtro a Imagen completa" << endl;
                    cout << "[2] Filtro a una capa en espeficio" << endl;
                    cout << "[************************************************]" << endl;
                    cout << "Seleccione una opcion" << endl;
                    cout << "-->";

                    string op;
                    cin>>op;
                    int filt = es_entero(op);
                    string nombre_capa = "";
                    if(filt == 1){
                        menu_aplicar_filtros(nombre_capa);
                    }else if(filt == 2){
                        cout << "[************************************************]" << endl;
                        cout << "Ingrese el nombre de la capa" << endl;
                        cout << "-->";
                        cin>>nombre_capa;
                        if(imagen_seleccionada->buscar(nombre_capa) != 0){
                            menu_aplicar_filtros(nombre_capa);
                        }else{
                            cout << "No existe la capa con el nombre: " << nombre_capa << endl;
                        }
                    }else{
                        cout << "opcion incorrecta" << endl;
                    }
                }else {
                    cout << "No se ha seleccionado una imagen" <<endl;
                }
                break;
            case 4:
                if(imagen_seleccionada != 0){
                    menu_edicion_manual();
                }else {
                    cout << "No se ha seleccionado una imagen" <<endl;

                }
                break;
            case 5:
                if(imagen_seleccionada != 0){
                    if(lista_fitros != 0){
                        menu_exportar_imagen();
                    }else{
                        cout << "No se han aplicado filtros a la imagen " << imagen_seleccionada->nombre << endl;
                    }
                }else{
                    cout << "No se ha seleccionado una imagen" <<endl;
                }
                break;
            case 6:
                break;
            case 0:
                opcion = 0;
                break;
            default:
                cout << "opcion incorrecta" << endl;
                break;
        }

    }

}

int main(int argc, char** argv) {
    principal();
    return 0;
}

