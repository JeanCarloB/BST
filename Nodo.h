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

    Nodo(T elemento, int indice,  Nodo<T>* anterior, Nodo<T>* siguiente)
    {
        this->elemento = elemento;
        this->indice = indice;
        this->anterior = anterior;
        this->siguiente = siguiente;
    }

    void setElemento(T elemento)
    {
        this->elemento = elemento;
    }

    T getElemento() const
    {
        return this->elemento;
    }

    void setIndice(int indice)
    {
        this->indice = indice;
    }

    int getIndice() const
    {
        return this->indice;
    }

    void setAnterior(Nodo<T>* anterior)
    {
        this->anterior = anterior;
    }

    Nodo<T>* getAnterior() const
    {
        return this->anterior;
    }

    void setSiguiente(Nodo<T>* siguiente)
    {
        this->siguiente = siguiente;
    }

    Nodo<T>* getSiguiente() const
    {
        return this->siguiente;
    }

    ~Nodo()
    {

    }
};



#endif