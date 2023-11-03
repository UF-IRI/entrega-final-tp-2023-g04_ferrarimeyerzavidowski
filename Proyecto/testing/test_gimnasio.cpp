#include <catch2/catch.hpp>
#include <gimnasio.cpp>

TEST_CASE("Verificar clase"){
    sTipo tipo;
    tipo.nombreClase="Spinning";
    tipo.idClase=4;
    tipo.horario=8;

    bool a=VerificarClase(&tipo);
    REQUIRE(a==true);
    REQUIRE(true==true);

}
