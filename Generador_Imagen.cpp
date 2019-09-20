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
#include <iomanip>

Generador_Imagen::Generador_Imagen() {
}
void Generador_Imagen::generar_imagen(Cubo* cubo, string filtro) {
    string matriz [cubo->fila_mayor][cubo->columna_mayor];
    string mosaico = "";

    iw = cubo->pixel_w *  cubo->columna_mayor;
    ih = cubo->pixel_h *  cubo->fila_mayor;
    pw = cubo->pixel_w;
    ph = cubo->pixel_h;    

    
    Nodo_Cubo* aux_cube = cubo->cabeza;
    int i = 0;
    int j = 0;
    
    while (aux_cube != 0) {
        Nodo_Capa* aux_capa_dw = aux_cube->capa->cabecera->abajo;
        while (aux_capa_dw != 0) {
            Nodo_Capa* aux_capa_sg = aux_capa_dw->sig;
            while (aux_capa_sg != 0) {
                if(matriz[i][j] == ""){
                    matriz[i][j] = aux_capa_sg->color;
                
                }else{
                    if(matriz[i][j] == "x" and aux_capa_sg->color != "x"){
                        matriz[i][j] = aux_capa_sg->color;
                    }
                }
                aux_capa_sg = aux_capa_sg->sig;
                j++;
            }
            i++;
            j = 0;
            aux_capa_dw = aux_capa_dw->abajo;
        }
        i = 0;
        j = 0;
        aux_cube = aux_cube->sig;
    }

    file_html.close();
    file_css.close();
    
    file_css.clear();
    file_html.clear();
    
    file_html.open(cubo->nombre + filtro + ".html");
    file_css.open(cubo->nombre + filtro + ".css");

    file_html << "<!DOCTYPE html>\n<html>\n<head>" << endl;
    file_html << "<link rel=\"stylesheet\" href=\"" << cubo->nombre << filtro << ".css\">" << endl;
    file_html << "</head>\n<body>\n<div class=\"canvas\">" << endl;

    file_css << "body{\nbackground: #333333;\nheight: 100vh;\ndisplay:flex;" << endl;
    file_css << "justify-content: center;\nalign-items: center;\n}" << endl;

    file_css << ".canvas{" << endl;
    file_css << "width:" << iw << "px;" << endl;
    file_css << "height:" << ih << "px;" << endl;
    if(filtro == "negativo"){
        file_css << "filter: invert(1);\n}" << endl;
    }else if(filtro == "grises"){
        file_css << "filter: grayscale(100%);\n}" << endl;
    }else if(filtro == "espejo-x"){
        file_css << "transform: scaleX(-1);\n}" << endl;
    }else if(filtro == "espejo-y"){
        file_css << "transform: scaleY(-1);\n}" << endl;
    }else if(filtro == "espejo-xy"){
        file_css << "transform: scaleX(-1);" << endl;
        file_css << "transform: rotate(180deg);\n}" << endl;
    }else if(filtro == "mosaico"){
        float pw_f = pw;
        float ph_f = ph;
        float mcm = cubo->columna_mayor;
        float mfm = cubo->fila_mayor;

        float pw_mosaico = (float) pw / cubo->columna_mayor;
        float ph_mosaico = (float) ph / cubo->fila_mayor;
        file_css << "}.canvasM{" << endl;
        file_css << "width:" << pw << "px;" << endl;
        file_css << "height:" << ph << "px;\n}" << endl;


        file_css << ".pixelM{" << endl;
        file_css << "float: left;" << endl;
        file_css << "width:" << pw_mosaico << "px;" << endl;
        file_css << "height:" << ph_mosaico << "px;\n}" << endl;
    
        mosaico = "<div class=\"canvasM\">\n";
        aux_cube = cubo->cabeza;
        int index = 0;
        for(int i = 0; i < cubo->fila_mayor; i++){
            for(int j = 0; j < cubo->columna_mayor; j++){
                mosaico = mosaico + "<div class=\"pixelM\"></div>\n";
                if (matriz[i][j] != "x") {
                    file_css << ".pixelM:nth-child(" << index << "){\nbackground: rgb("<< matriz[i][j] << ");\n}" << endl;
                }
                index++;
            }
        }
        mosaico = mosaico + "</div>";
    }else{
        file_css << "}" << endl;
    }
    
    file_css << ".pixel{\nfloat: left;" << endl;
    file_css << "width:" << pw << "px;" << endl;
    file_css << "height:" << ph << "px;\n}" << endl;
    
    aux_cube = cubo->cabeza;
    int index = 1;
    
    for(int i = 0; i < cubo->fila_mayor; i++){
        for(int j = 0; j < cubo->columna_mayor; j++){
            file_html << "<div class=\"pixel\">" << endl;
            if(matriz[i][j] != "x"){
                file_css << ".pixel:nth-child(" << index << "){\nbackground: rgb("<< matriz[i][j] << ");\n}" << endl;
                if(filtro == "mosaico"){
                    file_html << mosaico;
                }
            }
            file_html << "</div>" << endl;
            index++;
        }
    }
    file_html << "</div>\n</body>\n</html>" << endl;
    string title = cubo->nombre + filtro+ ".html";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
    index_mosacio = 0;
}




