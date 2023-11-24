#include <catch2/catch.hpp>
#include <archivos.cpp>


/*TEST_CASE("LeerClases con archivo CSV válido", "[LeerClases]") {
// Crear un archivo de prueba con datos conocidos
std::ofstream archivo_prueba("archivo_prueba.csv");
archivo_prueba << "1,Clase1,1637841600\n2,Clase2,1637845200\n";
archivo_prueba.close();

// Abrir el archivo de prueba para lectura
std::ifstream archivo_lectura("archivo_prueba.csv");
sTipoLectura tipos[2];  // Ajusta el tamaño según el número de elementos en tu archivo de prueba
int n = 0;

// Llamar a la función LeerClases
eCodArchivos resultado = LeerClases(&archivo_lectura, tipos, n);

// Verificar el resultado y los datos leídos
REQUIRE(resultado == eCodArchivos::ExitoOperacion);
REQUIRE(n == 2);

// Verificar los datos específicos (ajusta según tu caso)
REQUIRE(tipos[0].idClase == 1);
REQUIRE(tipos[0].nombreClase == "Clase1");
REQUIRE(tipos[0].horario == 1637841600);

REQUIRE(tipos[1].idClase == 2);
REQUIRE(tipos[1].nombreClase == "Clase2");
REQUIRE(tipos[1].horario == 1637845200);

// Cierra el archivo de prueba
archivo_lectura.close();
}*/



