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



int Generador_Imagen::es_entero(string ent) {
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

void Generador_Imagen::generar_imagen(Cubo* cubo, string filtro) {
    string matriz [cubo->fila_mayor][cubo->columna_mayor];
    string mosaico = "";

    iw = cubo->pixel_w * cubo->columna_mayor;
    ih = cubo->pixel_h * cubo->fila_mayor;
    pw = cubo->pixel_w;
    ph = cubo->pixel_h;

    int x = 0;
    int y = 0;
    Nodo_Cubo* aux_cube = cubo->cabeza;
    int i = 0;
    int j = 0;

    while (aux_cube != 0) {
        Nodo_Capa* aux_capa_dw = aux_cube->capa->cabecera->abajo;
        while (aux_capa_dw != 0) {
            Nodo_Capa* aux_capa_sg = aux_capa_dw->sig;
            while (aux_capa_sg != 0) {

                if (matriz[i][j] == "") {
                    matriz[i][j] = aux_capa_sg->color;
                } else {
                    if (matriz[i][j] == "x" and aux_capa_sg->color != "x") {
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
    if (filtro == "mosaico") {
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
        for (int i = 0; i < cubo->fila_mayor; i++) {
            for (int j = 0; j < cubo->columna_mayor; j++) {
                mosaico = mosaico + "<div class=\"pixelM\"></div>\n";
                if (matriz[i][j] != "x") {
                    file_css << ".pixelM:nth-child(" << index << "){\nbackground: rgb(" << matriz[i][j] << ");\n}" << endl;
                }
                index++;
            }
        }
        mosaico = mosaico + "</div>";
    } else if (filtro == "collage") {
        cout << "ingrese la cantidad en x: ";
        string ent;
        cin>>ent;
        x = es_entero(ent);
        cout << "ingrese la cantidad en y: ";
        cin>>ent;
        y = es_entero(ent);
        if (x > 0 and y > 0) {
            float pw_f = iw / x;
            float ph_f = ih / y;
            float mcm = cubo->columna_mayor;
            float mfm = cubo->fila_mayor;

            float pw_mosaico = (float) pw_f / cubo->columna_mayor;
            float ph_mosaico = (float) ph_f / cubo->fila_mayor;
            file_css << "}.canvasM{" << endl;
            file_css << "width:" << pw_f << "px;" << endl;
            file_css << "height:" << ph_f << "px;\n}" << endl;


            file_css << ".pixelM{" << endl;
            file_css << "float: left;" << endl;
            file_css << "width:" << pw_mosaico << "px;" << endl;
            file_css << "height:" << ph_mosaico << "px;\n}" << endl;

            mosaico = "<div class=\"canvasM\">\n";
            aux_cube = cubo->cabeza;
            int index = 0;
            for (int i = 0; i < cubo->fila_mayor; i++) {
                for (int j = 0; j < cubo->columna_mayor; j++) {
                    mosaico = mosaico + "<div class=\"pixelM\"></div>\n";
                    if (matriz[i][j] != "x") {
                        file_css << ".pixelM:nth-child(" << index << "){\nbackground: rgb(" << matriz[i][j] << ");\n}" << endl;
                    }
                    index++;
                }
            }
            mosaico = mosaico + "</div>";
        }
    } else {
        file_css << "}" << endl;
    }

    if (filtro == "collage") {
        file_html << "<table>" << endl;
        for(int i = 0; i < y; i++){
            file_html << "<tr>" << endl;
            for(int j = 0; j < x; j++){
                file_html << "<td>" << mosaico << "</td>" << endl;    
            }
            file_html << "</tr>" << endl;
        }
        file_html << "</table>" << endl;
        
    } else {
        file_css << ".pixel{\nfloat: left;" << endl;
        file_css << "width:" << pw << "px;" << endl;
        file_css << "height:" << ph << "px;\n}" << endl;

        aux_cube = cubo->cabeza;
        int index = 1;

        for (int i = 0; i < cubo->fila_mayor; i++) {
            for (int j = 0; j < cubo->columna_mayor; j++) {
                file_html << "<div class=\"pixel\">" << endl;
                if (matriz[i][j] != "x") {
                    file_css << ".pixel:nth-child(" << index << "){\nbackground: rgb(" << matriz[i][j] << ");\n}" << endl;
                    if (filtro == "mosaico") {
                        file_html << mosaico;
                    }
                }
                file_html << "</div>" << endl;
                index++;
            }
        }

    }
    file_html << "</div>\n</body>\n</html>" << endl;
    string title = cubo->nombre + filtro + ".html";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
    index_mosacio = 0;
}




