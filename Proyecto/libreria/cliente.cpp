#include "cliente.h"

bool EstadoCuenta(sCliente* cliente){
    srand(time(NULL));
    int num = rand() % 2 + 1;

    if (cliente->estado < 0) { // endeudado
        if (num == 1) { // lo quiere pagar
            cliente->estado = 0;
            return true;
        } else { // no lo quiere pagar
            return false;
        }
    }

    return true; // no estuvo endeudado
}

sTipo* Inscribirse(sTipo* tipos, int tamlista){
    // Inicializo
    srand(static_cast<unsigned int>(time(nullptr)));

    // Genero un índice aleatorio en el rango [0, tamlista - 1]
    int indiceAleatorio = rand() % tamlista;
    return &tipos[indiceAleatorio];
}
