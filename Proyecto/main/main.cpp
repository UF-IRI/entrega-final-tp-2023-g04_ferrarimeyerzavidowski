
#include "archivos.cpp"
#include "gimnasio.cpp"

int main() {

    ifstream archi;
    archi.open("iriClasesGYM.csv", ios::in);
    int N=0;
    sTipoLectura* tipos=new sTipoLectura[N];
    if (!archi.is_open()) {
        return -1;
    }

    string linea;
    getline(archi, linea);  // Leer la línea de encabezado y descartarla

    while (getline(archi, linea)) {
        stringstream ss(linea);
        char coma;

        // Leer los campos de la línea
        ss >> tipos[N].idClase >> coma >> tipos[N].nombreClase >> coma >> tipos[N].horario;

        // Incrementar el contador
        N++;

        // Redimensionar el arreglo dinámico
        resizeTipos(tipos, N);
    }
    archi.close();

    //leo el de clientes
    ifstream archi2;
    archi2.open("iriClientesGYM.csv", ios::in);
    int n=0;
    sCliente *clientes= new sCliente [n];
    if (!archi2.is_open()) {
        return eCodArchivos::ErrorApertura;
    }

    std::string header;
    getline(archi2, header);  // Leer la línea de encabezado y descartarla

    while (!archi2.eof()) {
        resizeClientes(clientes, n);
        sCliente& nuevoCliente = clientes[n - 1];

        archi >> nuevoCliente.idCliente >> nuevoCliente.nombre >> nuevoCliente.apellido >> nuevoCliente.email >> nuevoCliente.telefono >> nuevoCliente.fechaNac >> nuevoCliente.estado;

        // Si el archivo aún no ha llegado al final, incrementar el contador
        if (!archi.eof()) {
            n++;
        }
    }
    sGimnasio Musculito;
    Musculito.misClases=tipos;
    Musculito.misClientes=clientes;

    /*sTipo* tipos=new sTipo[N];
    Actualizar_estructura(tiposlectura,tipos,N);
    delete[] tiposlectura;
    int Nins=0, Nas=0;
    sAsistencia* archi_inscripcion = new sAsistencia[Nins];
    sAsistencia* archi_asistencia = new sAsistencia[Nas];
    //funcion copiar uno a uno, recibo las dos listas de arriba y voy llamando al resize de archi_asistencia para copiar de una a otra
    delete[] clientes;
    delete[] tipos;*/

    return 0;
}
