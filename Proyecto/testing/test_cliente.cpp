
#include <catch2/catch.hpp>
#include <cliente.cpp>


//OJO CAMBIE LA FUNCION
TEST_CASE ("Estado de pago"){
    sCliente* cliente= new sCliente;
    cliente->idCliente = 12;
    cliente->nombre = "mar";
    cliente->apellido = "lopez";
    cliente->email = "martu@fava";
    cliente->telefono = "15432";
    cliente->estado=-30;
    //averiguar como saber lo de numero random dentro de la funcion
    REQUIRE (cliente!=nullptr);
    SECTION("Estado neg"){
        EstadoCuenta(cliente);
        REQUIRE(cliente->estado==0);
    }
    delete cliente;
}

