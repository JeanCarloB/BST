//
// Created by jeanc on 19/09/2022.
//

#include "Lista.h"

template<class T>
Lista<T>::Lista()
{
    this->primero = nullptr;
    this->cantidad = 0;
}
template<class T>
Lista<T>::Lista(const Lista& lista)
{
    if (lista.primero == nullptr)
    {
        this->primero = nullptr;
        this->cantidad = 0;
    }
    else
    {
        Nodo<T>* temporal = lista.primero;
        Nodo<T>* auxiliar = nullptr;

        this->primero = new Nodo<T>(temporal->getElemento(), temporal->getIndice(), nullptr, nullptr);
        this->cantidad = lista.cantidad;
        auxiliar = this->primero;
        temporal = temporal->getSiguiente();

        while (temporal != nullptr)
        {
            auxiliar->setSiguiente(new Nodo<T>(temporal->getElemento(), temporal->getIndice(), auxiliar, nullptr));
            auxiliar = auxiliar->getSiguiente();
            temporal = temporal->getSiguiente();
        }
    }
}
template<class T>
bool Lista<T>::esVacia()
{
    if (this->primero == nullptr)
    {
        return true;
    }

    return false;
}
template<class T>
int Lista<T>::getCantidad() const
{
    return this->cantidad;
}
template<class T>
void Lista<T>::insertar(T elemento)
{
    Nodo<T>* auxiliar = nullptr;

    if (esVacia())
    {
        this->primero = new Nodo<T>(elemento, 1, nullptr, nullptr);
        this->cantidad++;
    }
    else
    {
        auxiliar = this->primero;

        while (auxiliar->getSiguiente() != nullptr)
        {
            auxiliar = auxiliar->getSiguiente();
        }

        auxiliar->setSiguiente(new Nodo<T>(elemento, auxiliar->getIndice() + 1, auxiliar, nullptr));
        this->cantidad++;
    }
}
template<class T>
void Lista<T>::eliminar(Nodo<T>* nodoPorEliminar)
{
    if (esVacia() || nodoPorEliminar == nullptr)
    {
        return;
    }

    if (this->primero == nodoPorEliminar)
    {
        if (this->primero->getSiguiente() != nullptr)
        {
            this->primero = this->primero->getSiguiente();
            this->primero->setAnterior(nullptr);
        }
        else
        {
            this->primero = nullptr;
        }

        delete nodoPorEliminar;
        cantidad--;
    }
    else
    {
        Nodo<T>* auxiliar = this->primero;
        Nodo<T>* temporal = nullptr;

        while (auxiliar != nullptr)
        {
            if (auxiliar == nodoPorEliminar)
            {
                temporal = auxiliar->getAnterior();
                temporal->setSiguiente(auxiliar->getSiguiente());

                if (auxiliar->getSiguiente() != nullptr)
                {
                    auxiliar->getSiguiente()->setAnterior(temporal);
                }

                delete nodoPorEliminar;
                cantidad--;
                return;
            }

            auxiliar = auxiliar->getSiguiente();
        }
    }
}
template<class T>
void Lista<T>::eliminarEnPosicion(int posicion)
{
    if(posicion <= 0){
        return;
    }

    Nodo<T>* temp = primero;
    for(int i=1; i<posicion; i++){
        temp = temp->getSiguiente();
        if(temp == nullptr)
            return;
    }
    eliminar(temp);
}
template<class T>
T Lista<T>::getPrimero()
{
    if (!esVacia())
    {
        T elemento = this->primero->getElemento();
        intercambiarPosiciones(1, cantidad);
        eliminarEnPosicion(cantidad);

        return elemento;
    }

    return this->primero->getElemento();
}
template<class T>
int Lista<T>::getUltimo()
{
    Nodo<T>* auxiliar = this->primero;

    if (esVacia())
    {
        return -1;
    }

    while(auxiliar->getSiguiente() != nullptr)
    {
        auxiliar = auxiliar->getSiguiente();
    }

    return auxiliar->getIndice();
}
template<class T>
Nodo<T>* Lista<T>::getPosicion(int posicion)
{
    Nodo<T>* auxiliar = this->primero;
    int contador = 0;

    if (esVacia() || posicion <= 0 || posicion > this->cantidad)
    {
        return nullptr;
    }
    else
    {
        while (auxiliar != nullptr)
        {
            contador++;
            if (posicion == contador)
            {
                return auxiliar;
            }

            auxiliar = auxiliar->getSiguiente();
        }
    }
    return auxiliar;
}
template<class T>
int Lista<T>::comparaElementoMayor(int i, int j)
{
    Nodo<T>* primeraPos = getPosicion(i);
    Nodo<T>* segundaPos = getPosicion(j);

    if (primeraPos != nullptr && segundaPos != nullptr)
    {
        if (primeraPos->getElemento() > segundaPos->getElemento())
        {
            return primeraPos->getIndice();
        }
        else
        {
            return segundaPos->getIndice();
        }
    }

    return -1;
}
template<class T>
int Lista<T>::comparaElementoMenor(int i, int j)
{
    Nodo<T>* primeraPos = getPosicion(i);
    Nodo<T>* segundaPos = getPosicion(j);

    if (primeraPos != nullptr && segundaPos != nullptr)
    {
        if (primeraPos->getElemento() < segundaPos->getElemento())
        {
            return primeraPos->getIndice();
        }
        else
        {
            return segundaPos->getIndice();
        }
    }

    return -1;
}
template<class T>
bool Lista<T>::adyacentes(Nodo<T>* i, Nodo<T>* j)
{
    if (i->getSiguiente() == j || i->getAnterior() == j || j->getSiguiente() == i || j->getAnterior() == i)
    {
        return true;
    }

    return false;
}
template<class T>
void Lista<T>::intercambiarIndices(Nodo<T>* i, Nodo<T>* j)
{
    int auxiliar = i->getIndice();
    i->setIndice(j->getIndice());
    j->setIndice(auxiliar);
}
template<class T>
void Lista<T>::intercambiarPosiciones(int i, int j)
{
    Nodo<T>* primeraPos = getPosicion(i);
    Nodo<T>* segundaPos = getPosicion(j);
    Nodo<T>* auxiliar = nullptr;

    if (primeraPos != nullptr && segundaPos != nullptr)
    {
        intercambiarIndices(primeraPos, segundaPos);
        if (adyacentes(primeraPos, segundaPos))
        {
            if (primeraPos->getAnterior() != nullptr)
            {
                primeraPos->getAnterior()->setSiguiente(segundaPos);
            }

            if (segundaPos->getSiguiente() != nullptr)
            {
                segundaPos->getSiguiente()->setAnterior(primeraPos);
            }

            segundaPos->setAnterior(primeraPos->getAnterior());
            primeraPos->setAnterior(segundaPos);

            auxiliar = segundaPos->getSiguiente();
            segundaPos->setSiguiente(primeraPos);
            primeraPos->setSiguiente(auxiliar);

            if(this->primero == primeraPos)
            {
                this->primero = segundaPos;
            }
        }
        else
        {
            if (primeraPos->getAnterior() != nullptr)
            {
                primeraPos->getAnterior()->setSiguiente(segundaPos);
            }

            if (segundaPos->getAnterior() != nullptr)
            {
                segundaPos->getAnterior()->setSiguiente(primeraPos);
            }

            if (primeraPos->getSiguiente() != nullptr)
            {
                primeraPos->getSiguiente()->setAnterior(segundaPos);
            }

            if (segundaPos->getSiguiente() != nullptr)
            {
                segundaPos->getSiguiente()->setAnterior(primeraPos);
            }


            Nodo<T>* temp;


            temp = primeraPos->getAnterior();
            primeraPos->setAnterior(segundaPos->getAnterior());
            segundaPos->setAnterior(temp);


            temp = primeraPos->getSiguiente();
            primeraPos->setSiguiente(segundaPos->getSiguiente());
            segundaPos->setSiguiente(temp);

            if (this->primero == primeraPos)
            {
                this->primero = segundaPos;
            }
        }
    }
}
template<class T>
void Lista<T>::Imprimir()
{
    Nodo<T>* auxiliar = this->primero;

    cout << "[ ";

    while(auxiliar->getSiguiente() != nullptr)
    {
        cout << auxiliar->getElemento() << ", ";
        auxiliar= auxiliar->getSiguiente();
    }

    cout << auxiliar->getElemento() << " ]" << endl;
}
template<class T>
Lista<T>::~Lista()
{
    Nodo<T>* auxiliar = nullptr;

    while (this->primero != nullptr)
    {
        auxiliar = this->primero;
        this->primero = this->primero->getSiguiente();
        delete auxiliar;
    }
}