
#include "archivos.cpp"
#include "gimnasio.cpp"
#include "funciones.cpp"

int main() {
    ifstream archi;
    archi.open("iriClasesGYM.csv", ios::in);
    int N = 0;
    sTipoLectura* tipos = new sTipoLectura[N];
    if (!archi.is_open()) {
        return -1;
    }

    string linea;
    getline(archi, linea);  // Leer la línea de encabezado y descartarla

    while (getline(archi, linea)) {
        // Redimensionar el arreglo dinámico
        resizeTipos(tipos, N);

        stringstream ss(linea);  // Asignar la línea al stringstream
        char coma;

        // Leer los campos de la línea
        ss >> tipos[N].idClase >> coma >> tipos[N].nombreClase >> coma >> tipos[N].horario;

        // Incrementar el contador
        N++;
    }
    archi.close();

    ifstream archi2;
    archi2.open("iriClientesGYM.csv", ios::in);
    int n = 0;
    sCliente* clientes = new sCliente[n];
    if (!archi2.is_open()) {
        return -1;
    }

    string header;
    getline(archi2, header);  // Leer la línea de encabezado y descartarla

    char coma = ',';  // Separador
    string line;
    while (getline(archi2, line)) {
        resizeClientes(clientes, n);

        std::stringstream iss(line);
        sCliente& nuevoCliente = clientes[n];  // Corregir el acceso al nuevo cliente

        // Lee los campos de la línea
        iss >> nuevoCliente.idCliente >> coma;
        getline(iss, nuevoCliente.nombre, coma);  //ACA SALTA EL ERROR
        getline(iss, nuevoCliente.apellido, coma);
        getline(iss, nuevoCliente.email, coma);
        getline(iss, nuevoCliente.telefono, coma);
        string fechaNacStr;
        iss >> fechaNacStr >> coma;
        nuevoCliente.fechaNac = ConvertirFechaATime_t(fechaNacStr);
        iss >> nuevoCliente.estado >> coma;

        // Incrementar el contador
        n++;
    }

    archi2.close();



    sTipo* tiposNuevo=new sTipo[N];
    Actualizar_estructura(tipos,tiposNuevo,N);
    delete[] tipos;
    sGimnasio Musculito;
    Musculito.misClases=tiposNuevo;
    Musculito.misClientes=clientes;

    /*
    int Nins=0, Nas=0;
    sAsistencia* archi_inscripcion = new sAsistencia[Nins];
    sAsistencia* archi_asistencia = new sAsistencia[Nas];
    //funcion copiar uno a uno, recibo las dos listas de arriba y voy llamando al resize de archi_asistencia para copiar de una a otra
    delete[] clientes;
    delete[] tipos;*/

    return 0;
}
