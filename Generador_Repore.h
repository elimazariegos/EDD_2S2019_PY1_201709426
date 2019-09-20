/* 
 * File:   Generador_Repore.h
 * Author: Samuel
 *
 * Created on 17 de septiembre de 2019, 02:19 PM
 */

#ifndef GENERADOR_REPORE_H
#define	GENERADOR_REPORE_H

#include "Nodo_ABB.h"

class Generador_Repore {
public:
    string texto = "";
    Generador_Repore();
    void imported_image_report(Nodo_ABB* tmp);
    void recorrer_arbol_imagen(Nodo_ABB* tmp);

    template <typename T>
    string to_string(T n) {
        ostringstream os;
        os << n;
        return os.str();
    }
private:

};

#endif	/* GENERADOR_REPORE_H */

