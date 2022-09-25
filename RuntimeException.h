//
// Created by jeanc on 08/09/2022.
//

#ifndef BST_RUNTIMEEXCEPTION_H
#define BST_RUNTIMEEXCEPTION_H

#include "Libreria.h"
class RuntimeException {
    string mensaje;
public:
    explicit RuntimeException(const string &mensaje) : mensaje(mensaje) {}

    const string &getMensaje() const {
        return mensaje;
    }

    void setMensaje(const string &mensaje) {
        RuntimeException::mensaje = mensaje;
    }
};


#endif //BST_RUNTIMEEXCEPTION_H
