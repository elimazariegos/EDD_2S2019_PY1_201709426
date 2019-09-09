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

void Generador_Imagen::generar_imagen(Cubo* cubo, int ph, int pw, int iw, int ih) {
    ofstream file_html;
    ofstream file_css;

    iw = pw *  cubo->columna_mayor;
    
    file_html.open(cubo->nombre + ".html");
    file_css.open(cubo->nombre + ".css");

    file_html << "<!DOCTYPE html>\n<html>\n<head>" << endl;
    file_html << "<link rel=\"stylesheet\" href=\"" << cubo->nombre << ".css\">" << endl;
    file_html << "</head>\n<body>\n<div class=\"canvas\">" << endl;

    file_css << "body{\nbackground: #333333;\nheight: 100vh;\ndisplay:flex;" << endl;
    file_css << "justify-content: center;\nalign-items: center;\n}" << endl;

    file_css << ".canvas{" << endl;
    file_css << "width:" << iw << "px;" << endl;
    file_css << "height:" << ih << "px;\n}" << endl;

    file_css << ".pixel{\nfloat: left;" << endl;
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
                    file_css << ".pixel:nth-child(" << index << "){\nbackground: rgb(" << aux_capa_sg->color << ");\n}" << endl;
                }
                aux_capa_sg = aux_capa_sg->sig;
                index++;
            }
            aux_capa_dw = aux_capa_dw->abajo;
        }       
        aux_cube = aux_cube->sig;
        index = 0;
    }
    file_html << "</div>\n</body>\n</html>" << endl;
}



