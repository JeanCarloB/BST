//
// Created by jeanc on 23/09/2022.
//

#include "Menu.h"

Menu::Menu() {
    colaCliente = new ColaPrioritaria<Cliente *>;

    string nombre, id, ingNino, emb, aduMay, categoria;
    bool ingresaNino, embarazo, adultoMayor;
    Cliente *tmp;
    fstream f;
    f.open("DatosBancoUno.txt", ios::in);
    if (f.is_open()) {
        while (true) {
            f >> nombre;
            if (nombre == "") break;
            f >> id;
            f >> ingNino;
            f >> emb;
            f >> aduMay;
            f.ignore(1);
            getline(f, categoria, '\n');

            if (ingNino == "Yes") ingresaNino = false;
            else ingresaNino = true;

            if (emb == "Yes") embarazo = false;
            else embarazo = true;

            if (aduMay == "Yes") adultoMayor = false;
            else adultoMayor = true;

            tmp = new Cliente(nombre, id, ingresaNino, embarazo, adultoMayor, categoria);
            if (!f.eof()) colaCliente->enqueue(tmp);
            else break;
        }
        f.close();
    }

}

Menu::~Menu() {

}

void Menu::menuPrincipal() {
    int opcion;

    do {
        cout << "-------------- Bienvenido a Banco Uno --------------" << endl;
        cout << "1--> Introducir en cola todos los clientes" << endl;
        cout << "2--> Agregar a la cola un unico cliente" << endl;
        cout << "3--> Atender los siguientes 5 clientes" << endl;
        cout << "4--> Mostrar el siguiente cliente a ser atendido" << endl;
        cout << "5--> Simular la atencion de un cliente" << endl;
        cout << "6--> Agregar un cliente Nuevo" << endl;
        cout << "0--> Salir" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Digite una opcion del menu: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                encolarTodos();
                break;
            case 2:
                encolarIndividual();
                break;
            case 3:
                atenderCincoClientes();
                break;
            case 4:
                mostrarSiguienteAtender();
                break;
            case 5:
                simularAtencion();
                break;
            case 6:
                agregarCliente();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida, vuelva a intentar" << endl;
                system("pause");

        }
    } while (opcion != 0);
}

void Menu::encolarTodos() {
    cout << "Los clientes ya se encuentran en la cola" << endl;
}

void Menu::encolarIndividual() {
    cout << "Los clientes ya se encuentran en la cola" << endl;
}

void Menu::atenderCincoClientes() {

    if (!colaCliente->esVacia()) {
        Cliente *auxiliar1 = colaCliente->dequeue();
        cout << *auxiliar1 << "\n";

        Cliente *auxiliar2 = colaCliente->dequeue();
        cout << *auxiliar2 << "\n";

        Cliente *auxiliar3 = colaCliente->dequeue();
        cout << *auxiliar3 << "\n";

        Cliente *auxiliar4 = colaCliente->dequeue();
        cout << *auxiliar4 << "\n";

        Cliente *auxiliar5 = colaCliente->dequeue();
        cout << *auxiliar5 << "\n";
    } else {
        cout << "No hay clientes pendientes en la cola" << endl;
    }

}

void Menu::mostrarSiguienteAtender() {

    if (!colaCliente->esVacia()) {
        Cliente *auxiliar = colaCliente->dequeue();
        cout << *auxiliar << "\n";
    } else {
        cout << "No hay clientes pendientes en la cola" << endl;
    }
}

void Menu::simularAtencion() {
    if (!colaCliente->esVacia()) {
        while (!colaCliente->esVacia()) {
            Cliente *auxiliar = colaCliente->dequeue();
            cout << *auxiliar << "\n";
        }
    } else {
        cout << "No hay clientes pendientes en la cola" << endl;
    }


}

void Menu::agregarCliente() {
    string nombre;
    string id;
    bool ingresaNino;
    bool embarazo;
    bool adultoMayor;
    string categoria;

    cout << "********** Agregar un Cliente Nuevo **********" << endl;

    cout << "Ingrese el nombre del cliente" << endl;
    cin >> nombre;

    cout << "Ingrese el ID del cliente" << endl;
    cin >> id;

    cout << "El cliente ingresa con un nino? Digite 1 para Si y 0 para No" << endl;
    cin >> ingresaNino;

    cout << "El cliente esta en periodo de embarazo? Digite 1 para Si y 0 para No" << endl;
    cin >> embarazo;

    cout << "El cliente es adulto mayor? Digite 1 para Si y 0 para No" << endl;
    cin >> adultoMayor;

    cout << "De que categoria es el cliente?" << endl;
    cin >> categoria;

    Cliente *clienteNuevo = new Cliente(nombre, id, ingresaNino, embarazo, adultoMayor, categoria);

    colaCliente->enqueue(clienteNuevo);

    cout << "Cliente agregado a la cola con exito!";

}