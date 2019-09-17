/* 
 * File:   Generador_Imagen.cpp
 * Author: Samuel
 * 
 * Created on 8 de septiembre de 2019, 01:13 AM
 */

#include "Generador_Imagen.h"
#include "Cubo.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
#include<string>

Generador_Imagen::Generador_Imagen() {
}


void Generador_Imagen::generar_imagen(Cubo* cubo, string filtro) {
    ofstream file_html;
    ofstream file_css;
    int ph  = 0, pw = 0, iw = 0, ih = 0;
    
    iw = cubo->pixel_w *  cubo->columna_mayor;
    ih = iw;
    pw = cubo->pixel_w;
    ph = cubo->pixel_h;    
    file_html.open(cubo->nombre + filtro + ".html");
    file_css.open(cubo->nombre + filtro + ".css");

    file_html << "<!DOCTYPE html>\n<html>\n<head>" << endl;
    file_html << "<link rel=\"stylesheet\" href=\"" << cubo->nombre << filtro << ".css\">" << endl;
    file_html << "</head>\n<body>\n<div class=\"canvas\">" << endl;

    file_css << "body{\nbackground: #333333;\nheight: 100vh;\ndisplay:flex;" << endl;
    file_css << "justify-content: center;\nalign-items: center;\n}" << endl;

    file_css << ".canvas{" << endl;
    file_css << "width:" << iw << "px;" << endl;
    file_css << "height:" << ih << "px;\n" << endl;
    if(filtro == "negativo"){
        file_css << "filter: invert(1);" << endl;
    }else if(filtro == "grises"){
        file_css << "filter: grayscale(100%);" << endl;
    }else if(filtro == "espejo-x"){
        file_css << "transform: scaleX(-1);" << endl;
    }else if(filtro == "espejo-y"){
        file_css << "transform: scaleY(-1);" << endl;
    }else if(filtro == "espejo-xy"){
        file_css << "transform: scaleX(-1);" << endl;
        file_css << "transform: rotate(180deg);" << endl;
    }
    file_css << "}\n.pixel{\nfloat: left;" << endl;
    file_css << "width:" << pw << "px;" << endl;
    file_css << "height:" << ph << "px;\n}" << endl;

    Nodo_Cubo* aux_cube = cubo->cabeza;
    int index = 1;
    while (aux_cube != 0) {
        Nodo_Capa* aux_capa_dw = aux_cube->capa->cabecera->abajo;
        while (aux_capa_dw != 0) {
            Nodo_Capa* aux_capa_sg = aux_capa_dw->sig;
            while (aux_capa_sg != 0) {
                
                file_html << "<div class=\"pixel\"></div>" << endl;
                if (aux_capa_sg->color != "x") {
                    file_css << ".pixel:nth-child(" << index << "){\nbackground: rgb("<< aux_capa_sg->color << ");\n}" << endl;
                }
                aux_capa_sg = aux_capa_sg->sig;
                index++;
            }
            aux_capa_dw = aux_capa_dw->abajo;
        }       
        aux_cube = aux_cube->sig;
        index = 1;
    }
    file_html << "</div>\n</body>\n</html>" << endl;
    string title = cubo->nombre + filtro+ ".html";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}



