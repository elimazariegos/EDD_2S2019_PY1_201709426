/* 
 * File:   Generador_Repore.h
 * Author: Samuel
 *
 * Created on 17 de septiembre de 2019, 02:19 PM
 */

#ifndef GENERADOR_REPORE_H
#define	GENERADOR_REPORE_H

#include "Nodo_ABB.h"
#include "Arbol_ABB.h"
#include "Nodo_Filtro.h"
#include "Lista_Filtro.h"

class Generador_Repore {
public:
    string texto = "";
    int index = 0;
    Generador_Repore();
    Capa* clone(Nodo_Capa* tmp);
    void linealizacion_filas(Nodo_Capa* tmp, Capa* capa_aux);
    void linealizacion_columnas(Nodo_Capa* tmp,Capa* capa_aux);
    void imported_image_report(Nodo_ABB* tmp);
    void recorrer_arbol_imagen(Nodo_ABB* tmp);
    void recorrer_in_order(Nodo_ABB* tmp);
    void recorrer_pre_order(Nodo_ABB* tmp);
    void recorrer_post_order(Nodo_ABB* tmp);
    void transversal_report(Arbol_ABB* abb, int recorrido);
    void all_filter_report(Lista_Filtro* list);
    void generar_capa(Nodo_Capa* tmp,Capa* capa_aux);
    template <typename T>
    string to_string(T n) {
        ostringstream os;
        os << n;
        return os.str();
    }
private:

};

#endif	/* GENERADOR_REPORE_H */

