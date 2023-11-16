#include <catch2/catch.hpp>
#include "cliente.h"

TEST_CASE("EstadoCuenta, cliente endeudado y decide pagar") {
    sCliente* cliente = new sCliente;
    cliente->idCliente = 12;
    cliente->nombre = "mar";
    cliente->apellido = "lopez";
    cliente->email = "martu@fava";
    cliente->telefono = "15432";
    cliente->estado = -30;


    REQUIRE(cliente->estado < 0);
    // Llama a la función para cambiar el estado
    bool a=EstadoCuenta(cliente);

    if(a ==true){// Verifica que el estado cambió a 0 después de pagar
        REQUIRE(cliente->estado == 0);
    }
    else
    {
        REQUIRE(cliente->estado==-30);
    }
    delete cliente;
}

TEST_CASE("EstadoCuenta - Cliente no endeudado") {
    sCliente* cliente = new sCliente;
    cliente->idCliente = 12;
    cliente->nombre = "mar";
    cliente->apellido = "lopez";
    cliente->email = "martu@fava";
    cliente->telefono = "15432";
    cliente->estado = 20;

    //miro qu no este en deuda
    REQUIRE(cliente->estado >= 0);

    EstadoCuenta(cliente);

    // Verifica que el estado no cambió al no estar endeudado
    REQUIRE(cliente->estado == 20);
    delete cliente;
}

