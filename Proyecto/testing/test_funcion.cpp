#include <catch2/catch.hpp>
#include <funciones.h>


TEST_CASE("ClaseCupoMax, verificar cupo máximo por nombre de clase") {
    SECTION("Spinning") {
    REQUIRE(ClaseCupoMax("Spinning") == 45);
    }
}
TEST_CASE("YaInscriptoHorario - Cliente ya inscripto") {
    const int n = 1;
    sAsistencia asistPrevia[n];
    sInscripcion cursoInscrito;
    cursoInscrito.idCurso = 1;
    cursoInscrito.fechaInscripcion = time(nullptr);
    asistPrevia[0].idCliente = 1;
    asistPrevia[0].cantInscriptos = 1;
    asistPrevia[0].CursosInscriptos = new sInscripcion[2];
    asistPrevia[0].CursosInscriptos[0] = cursoInscrito;
    asistPrevia[0].CursosInscriptos[1].fechaInscripcion = 0;
    bool resultado = YaInscriptoHorario(cursoInscrito.fechaInscripcion, asistPrevia[0].idCliente, asistPrevia, n);
    REQUIRE(resultado == true);
    delete[] asistPrevia[0].CursosInscriptos;
}

TEST_CASE("YaInscriptoHorario - Cliente no inscripto") {
    // Configura el estado para el caso de prueba
    const int n = 1; // Puedes ajustar según sea necesario
    sAsistencia asistPrevia[n];
    sInscripcion cursoInscrito;
    cursoInscrito.idCurso = 1;
    cursoInscrito.fechaInscripcion = time(nullptr); // Usa el horario actual para el ejemplo
    asistPrevia[0].CursosInscriptos = new sInscripcion[2];
    asistPrevia[0].CursosInscriptos[0].idCurso = 2; // Cliente diferente
    asistPrevia[0].CursosInscriptos[0].fechaInscripcion = time(nullptr) - 3600; // Hace una hora
    asistPrevia[0].CursosInscriptos[1].fechaInscripcion = 0; // Marca el final del array
    // Realiza la prueba llamando a la función
    bool resultado = YaInscriptoHorario(cursoInscrito.fechaInscripcion, cursoInscrito.idCurso, asistPrevia, n);
    // Verifica que el resultado sea falso (cliente no inscrito)
    REQUIRE(resultado == false);
    // Limpieza de la memoria si es necesario
    delete[] asistPrevia[0].CursosInscriptos;
}
