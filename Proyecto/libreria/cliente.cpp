#include "cliente.h"
#include <QRandomGenerator>

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
    int indiceAleatorio = QRandomGenerator::global()->bounded(1, tamlista);

    return &tipos[indiceAleatorio];
}
