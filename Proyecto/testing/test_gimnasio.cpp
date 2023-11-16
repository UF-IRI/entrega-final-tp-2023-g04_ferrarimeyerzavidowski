#include <catch2/catch.hpp>
#include <gimnasio.h>

TEST_CASE("Verificar clase"){
    sTipo tipo;
    tipo.nombreClase="Spinning";
    tipo.idClase=4;
    tipo.horario=8;

    bool a=VerificarClase(&tipo);
    REQUIRE(a==true);
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
    REQUIRE(resultado == eReserva::DatosIncorrectos);
    delete cliente;
    delete clase;
    delete asistPrevia;
}

TEST_CASE("Reserva - Cupos Llenos") {

    sCliente* cliente = new sCliente;
    sTipo* clase = new sTipo;
    sAsistencia* asistPrevia = new sAsistencia;
    int n = 0;

    // cupos llenos
    clase->horario = time(nullptr);  // Horario actual
    clase->cupoActual = clase->cupoMax;

    eReserva resultado = Reserva(cliente, clase, asistPrevia, n);

    // Verificamos que devuelva CuposLlenos
    REQUIRE(resultado == eReserva::CuposLlenos);
    delete cliente;
    delete clase;
    delete asistPrevia;
}

TEST_CASE("Reserva - En Deuda") {
    sCliente* cliente = new sCliente;
    sTipo* clase = new sTipo;
    sAsistencia* asistPrevia = new sAsistencia;
    int n = 0;

    //datos con cliente en deuda
    clase->horario = time(nullptr);  // Horario actual
    cliente->estado = -30;  // Cliente en deuda

    eReserva resultado = Reserva(cliente, clase, asistPrevia, n);

    // Verifica que se devuelve EnDeuda
    REQUIRE(resultado == eReserva::EnDeuda);
    delete cliente;
    delete clase;
    delete asistPrevia;
}

TEST_CASE("Reserva - Superposición de Horarios") {
    sCliente* cliente = new sCliente;
    sTipo* clase = new sTipo;
    sAsistencia* asistPrevia = new sAsistencia;
    int n = 0;

// Configurar datos con cliente ya inscrito para otra clase en el mismo horario
    clase->horario = time(nullptr);  // Horario actual
    asistPrevia->CursosInscriptos[0].fechaInscripcion = clase->horario;
    asistPrevia->CursosInscriptos[1].fechaInscripcion = 0;  // Marcar el final de la lista

eReserva resultado = Reserva(cliente, clase, asistPrevia, n);
REQUIRE(resultado == eReserva::Superposicion);
delete cliente;
delete clase;
delete asistPrevia;
}

TEST_CASE("Reserva - Éxito") {
    sCliente* cliente = new sCliente;
    sTipo* clase = new sTipo;
    sAsistencia* asistPrevia = new sAsistencia;
    int n = 0;

    clase->horario = time(nullptr);
    clase->cupoActual = 5;  //hay espacio disponible

eReserva resultado = Reserva(cliente, clase, asistPrevia, n);
REQUIRE(resultado == eReserva::ReservaExitosa);
delete cliente;
delete clase;
delete asistPrevia;
}
