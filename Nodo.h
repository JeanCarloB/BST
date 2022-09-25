//
// Created by jeanc on 06/09/2022.
//

#ifndef BST_NODO_H
#define BST_NODO_H

template<class T>

class Nodo {

private:

    T elemento;
    int indice;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;

public:

    Nodo(T elemento, int indice,  Nodo<T>* anterior, Nodo<T>* siguiente);

    void setElemento(T elemento);

    T getElemento() const;

    void setIndice(int indice);

    int getIndice() const;

    void setAnterior(Nodo<T>* anterior);

    Nodo<T>* getAnterior() const;

    void setSiguiente(Nodo<T>* siguiente);

    Nodo<T>* getSiguiente() const;

    ~Nodo();
};



#endif