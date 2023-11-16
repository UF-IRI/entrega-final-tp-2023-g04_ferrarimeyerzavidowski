#include <catch2/catch.hpp>
#include <gimnasio.h>


TEST_CASE("Verificar clase valida") {
    sTipo* tipo = new sTipo;
    tipo->nombreClase = "Spinning";
    bool resultado = VerificarClase(tipo);
    REQUIRE(resultado == true);
    delete tipo;
}

TEST_CASE("Clase inválida") {
sTipo* tipo = new sTipo;
tipo->nombreClase = "Aewqics";  // Clase no válida
bool resultado = VerificarClase(tipo);
REQUIRE(resultado == false);
delete tipo;
}

TEST_CASE("puntero nulo") {
    sTipo* tipo = nullptr;
    bool resultado = VerificarClase(tipo);
    REQUIRE(resultado == false);
}

TEST_CASE("Reserva,horario incorrecto") {
    sCliente* cliente = new sCliente;
    sTipo* clase = new sTipo;
    sAsistencia* asistPrevia = new sAsistencia;
    int n = 0;


    clase->horario = 1000;

    // Llama a la función de reserva
    eReserva resultado = Reserva(cliente, clase, asistPrevia, n);

    // Verifica que se devuelve DatosIncorrectos
    REQUIRE(resultado == -5); // -5 es el calor de DatosIncorrectos en el enum
    delete cliente;
    delete clase;
    delete asistPrevia;
}


