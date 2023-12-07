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
