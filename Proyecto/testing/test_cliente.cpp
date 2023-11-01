#include <cliente.h>
#include <catch2/catch.hpp>
#include <encabezados.h>

//OJO CAMBIE LA FUNCION
TEST_CASE ("Estado de pago"){
    sCliente* cliente= new sCliente;
    cliente->idCliente = 12;
    cliente->nombre = "mar";
    cliente->apellido = "lopez";
    cliente->email = "martu@fava";
    cliente->telefono = "15432";
    cliente->estado=-30;

    REQUIRE (cliente!=nullptr);
    SECTION("Estado neg"){
        EstadoCuenta(cliente,1);
        REQUIRE(cliente->estado==0);
    }
    delete cliente;
}

