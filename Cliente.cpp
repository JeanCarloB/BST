//
// Created by jeanc on 06/09/2022.
//

#include "Cliente.h"

Cliente::Cliente(const string &nombre, const string &id, bool ingresaNino, bool embarazo, bool adultoMayor,
                 string categoria) : nombre(nombre), id(id), ingresaNino(ingresaNino), embarazo(embarazo),
                                     adultoMayor(adultoMayor), categoria(categoria) {

    setPrioridad();

}

Cliente::~Cliente() {

}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

const string &Cliente::getId() const {
    return id;
}

void Cliente::setId(const string &id) {
    Cliente::id = id;
}

bool Cliente::isIngresaNino() const {
    return ingresaNino;
}

void Cliente::setIngresaNino(bool ingresaNino) {
    Cliente::ingresaNino = ingresaNino;
}

bool Cliente::isEmbarazo() const {
    return embarazo;
}

void Cliente::setEmbarazo(bool embarazo) {
    Cliente::embarazo = embarazo;
}

bool Cliente::isAdultoMayor() const {
    return adultoMayor;
}

void Cliente::setAdultoMayor(bool adultoMayor) {
    Cliente::adultoMayor = adultoMayor;
}

const string &Cliente::getCategoria() const {
    return categoria;
}

void Cliente::setCategoria(const string &categoria) {
    Cliente::categoria = categoria;
}

int Cliente::getPrioridad() const {
    return prioridad;
}

void Cliente::setPrioridad() {
    Cliente::prioridad = calculaPrioridad();
}

int Cliente::calculaPrioridad() {
    int prioridadTotal;
    int ingresaNino;
    int embarazo;
    int adultoMayor;
    int categoria;

    if (isIngresaNino() == true){
        ingresaNino = 20;
    } else {
        ingresaNino = 0;
    }

    if (isEmbarazo() == true){
        embarazo = 25;
    } else {
        embarazo = 0;
    }

    if (isAdultoMayor() == true){
        adultoMayor = 35;
    } else {
        adultoMayor = 0;
    }

    if (getCategoria() == "1"){
        categoria = 20;
    } else if (getCategoria() == "2"){
        categoria = 10;
    } else {
        categoria = 0;
    }

    return prioridadTotal = ingresaNino + embarazo + adultoMayor + categoria;
}

ostream &operator<<(ostream &os, const Cliente &cliente) {
    os << "Nombre: " << cliente.nombre << " ID: " << cliente.id << " Ingresa con Nino?: " << cliente.ingresaNino
       << " Esta en periodo de embarazo?: " << cliente.embarazo << " Es un adulto mayor?: " << cliente.adultoMayor << " Que categoria es?: "
       << cliente.categoria << " Prioridad: " << cliente.prioridad;
    return os;
}

bool Cliente::operator<(const Cliente & d) {
    return (getId()<d.getId())?true:false;
}

bool Cliente::operator>(const Cliente & d) {
    return (getId()>d.getId())?true:false;
}





