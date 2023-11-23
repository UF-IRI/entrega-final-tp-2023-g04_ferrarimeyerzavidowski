#include <archivos.cpp>
#include <tipo.h>
//#include <sstream>

TEST_CASE("LeerClases con archivo CSV válido", "[LeerClases]") {
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
}

/*TEST_CASE("LeerClases") {
// Abrimos el archivo para lectura
std::ifstream archivo_lectura("iriClasesGYM.csv");
sTipoLectura tipos[63];  // cantidad máxima esperada de elementos
int n = 0;

// Llamar a la función LeerClases
eCodArchivos resultado = LeerClases(&archivo_lectura, tipos, n);

// Verificamos el resultado y los datos leídos
REQUIRE(resultado == eCodArchivos::ExitoOperacion);
REQUIRE(n > 0);  // Verifica que se haya leído al menos un elemento con eso nos alcanza

// Cierra el archivo de prueba
archivo_lectura.close();
}

TEST_CASE("LeerClientes") {
    // Abrir el archivo de prueba existente para lectura
    std::fstream archivo_lectura("iriClientesGYM.csv");
    sCliente clientes[252];  //la cantidad máxima esperada de elementos
    int n = 0;

    // Llamar a la función LeerClientes
    eCodArchivos resultado = LeerClientes(&archivo_lectura, clientes, n);

    // Verificar el resultado y los datos leídos
    REQUIRE(resultado == eCodArchivos::ExitoOperacion);
    REQUIRE(n > 0);  // Verifica que se haya leído al menos un cliente

    // Cierra el archivo de prueba
    archivo_lectura.close();
}

TEST_CASE("LeerAsistencia") {
    // Abrir el archivo de prueba existente para lectura
    std::fstream archivo_lectura("asistencias_1697673600000.dat", std::ios::binary | std::ios::in);
    sAsistencia asistencia;

    // Llamar a la función LeerAsistencia
    eCodArchivos resultado = LeerAsistencia(&archivo_lectura, &asistencia);

    // Verificar el resultado y los datos leídos
    REQUIRE(resultado == eCodArchivos::ExitoOperacion);

    // Imprimimo esta información sobre las asistencias leídas
    INFO("ID Cliente: " << asistencia.idCliente);
    INFO("Cantidad de Inscriptos: " << asistencia.cantInscriptos);

    // Cierra el archivo de prueba
    archivo_lectura.close();
}

/*TEST_CASE("EscribirAsistencia y LeerAsistencia con archivo binario") {
    // Crear un archivo de prueba
    std::fstream archivo_prueba("asistencias_prueba.dat", std::ios::binary | std::ios::out | std::ios::in | std::ios::trunc);
    sAsistencia asistencia_original = {123, 2, new sInscripcion[2]{{456, 1697673600000}, {789, 1697673610000}}};

    // Llamar a la función EscribirAsistencia
    eCodArchivos resultado_escritura = EscribirAsistencia(&archivo_prueba, &asistencia_original);

    // Verificar el resultado de la escritura
    REQUIRE(resultado_escritura == eCodArchivos::ExitoOperacion);

    // Posicionar el puntero de lectura/escritura al principio del archivo
    archivo_prueba.seekg(0, std::ios::beg);

    // Llamar a la función LeerAsistencia para verificar lo q escribi
    sAsistencia asistencia_leida;
    eCodArchivos resultado_lectura = LeerAsistencia(&archivo_prueba, &asistencia_leida);

    // Verificar el resultado de la lectura
    REQUIRE(resultado_lectura == eCodArchivos::ExitoOperacion);

    archivo_prueba.close();
}

TEST_CASE("EscribirInscripcion y LeerInscripcion con archivo binario") {
    // Crear un archivo de prueba
    std::fstream archivo_prueba("inscripcion_prueba.dat", std::ios::binary | std::ios::out | std::ios::in | std::ios::trunc);
    sInscripcion inscripcion_original = {123, 1697673600000};

    // Llamar a la función EscribirInscripcion
    eCodArchivos resultado_escritura = EscribirInscripcion(&archivo_prueba, &inscripcion_original);

    // Verificar el resultado de la escritura
    REQUIRE(resultado_escritura == eCodArchivos::ExitoOperacion);

    // Posicionar el puntero de lectura/escritura al principio del archivo
    archivo_prueba.seekg(0, std::ios::beg);

    // Llamar a la función LeerInscripcion para verificar lo q escribi
    sInscripcion inscripcion_leida;
    eCodArchivos resultado_lectura = LeerInscripcion(&archivo_prueba, &inscripcion_leida);

    // Verificar el resultado de la lectura
    REQUIRE(resultado_lectura == eCodArchivos::ExitoOperacion);


    archivo_prueba.close();
}*/

/*TEST_CASE("archivo leer clase") {
    ifstream archivo;
    archivo.open("C:\Users\User\Desktop\UNIVERSIDAD\IRI\EntregaFinal\entrega-final-tp-2023-g04_ferrarimeyerzavidowski");
    sTipo tipos;
    eCodArchivos prueba=LeerClases(archivo,tipos);

    REQUIRE(prueba==ExitoOperacion);
    REQUIRE(tipos[0].idClase== 1);
    REQUIRE(tipos[0].nombreclase== spinning);
    REQUIRE(TIPOS[0].horario== 8);
}

/*TEST_CASE("archivo leer cliente") {
    ifstream archivo;
    archivo.open("C:\Users\User\Desktop\UNIVERSIDAD\IRI\EntregaFinal\entrega-final-tp-2023-g04_ferrarimeyerzavidowski");
    sTipo tipos;
    eCodArchivos prueba=LeerCliente(archivo,clientes);

    REQUIRE(prueba==ExitoOperacion);
    REQUIRE(clientes[0].idCliente == 1);
    REQUIRE(clientes[0].nombre == Agustin);
    REQUIRE(clientes[0].apellido == Guerra);
    REQUIRE(clientes[0].email == AgustinGuerra@blandia.iri);
    REQUIRE(clientes[0].telefono == 462-185-1730);
    REQUIRE(clientes[0].fechaNac == 10-12-1966);
    REQUIRE(clientes[0].estado == 0);
}

TEST_CASE("archivo leer asistencia") {

}*/

