//
// Created by jeanc on 06/09/2022.
//

#ifndef BST_CLIENTE_H
#define BST_CLIENTE_H

#include "Libreria.h"

class Cliente {

private:
    string nombre;
    string id;
    bool ingresaNino;
    bool embarazo;
    bool adultoMayor;
    string categoria;
    int prioridad;

public:
    Cliente(const string &nombre, const string &id, bool ingresaNino, bool embarazo, bool adultoMayor, string categoria);

    virtual ~Cliente();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getId() const;

    void setId(const string &id);

    bool isIngresaNino() const;

    void setIngresaNino(bool ingresaNino);

    bool isEmbarazo() const;

    void setEmbarazo(bool embarazo);

    bool isAdultoMayor() const;

    void setAdultoMayor(bool adultoMayor);

    const string &getCategoria() const;

    void setCategoria(const string &categoria);

    int getPrioridad() const;

    void setPrioridad();

    int calculaPrioridad();

    friend ostream &operator<<(ostream &os, const Cliente &cliente);

    bool operator<(const Cliente&);

    bool operator>(const Cliente&);
};

#endif //BST_CLIENTE_H