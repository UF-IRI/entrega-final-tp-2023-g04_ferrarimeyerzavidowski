
#include "archivos.cpp"
#include "gimnasio.cpp"
#include "funciones.cpp"


int main() {

    ifstream archi2;
    //archi2.open("C:/Users/User/Desktop/UNIVERSIDAD/IRI/VersionFinalTP/entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClientesGYM.csv", ios::in)
    //archi2.open("C:/Users/zavid/OneDrive/Escritorio/archivoos/entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClientesGYM.csv", ios::in);
    archi2.open("/Users/isabellaferrari/Desktop/Facultad /Primer Año /intr. Redes e Internet/entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClientesGYM.csv", ios::in);
    int n = 0;
    sCliente* clientes = nullptr;
    if (!archi2.is_open()) {
        return -1;
    }
    string header;
    getline(archi2, header);  // Leer la línea de encabezado y descartarla

    char coma = ',';  // Separador
    string line;
    while (getline(archi2, line)) {
        resizeClientes(clientes, n);
        sCliente nuevoCliente;
        std::stringstream iss(line);
        string auxn,auxa,auxe,auxtel;
        time_t fechaNaci;
        // Lee los campos de la línea
        iss >> nuevoCliente.idCliente >> coma;
        getline(iss, auxn, coma);
        getline(iss, auxa, coma);
        getline(iss, auxe, coma);
        getline(iss, auxtel, coma);
        string fechaNacStr;
        getline(iss, fechaNacStr, coma);
        fechaNaci = ConvertirFechaATime_t(fechaNacStr);
        iss >>nuevoCliente.estado >> coma;
        nuevoCliente.nombre=auxn;
        nuevoCliente.apellido=auxa;
        nuevoCliente.email=auxe;
        nuevoCliente.telefono=auxtel;
        nuevoCliente.fechaNac=fechaNaci;
        clientes[n-1]=nuevoCliente;
    }
    archi2.close();


    ifstream archi;
    //archi.open("C:/Users/User/Desktop/UNIVERSIDAD/IRI/VersionFinalTP/entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClasesGYM.csv", ios::in);
    //archi.open("C:/Users/zavid/OneDrive/Escritorio/archivoos/entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClasesGYM.csv", ios::in);
    archi.open("/Users/isabellaferrari/Desktop/Facultad /Primer Año /intr. Redes e Internet/entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClasesGYM.csv", ios::in);
    int N = 0;
    sTipoLectura* tipos = nullptr;
    if (!archi.is_open()) {
        return -1;
    }
    string header1;
    getline(archi, header1);  // Leer la línea de encabezado y descartarla

    //la variable de la coma y el string line fueron definidos e inicializados

    while (getline(archi, line)) {
        resizeTipos(tipos, N); // Redimensionar
        sTipoLectura nuevoTipo;
        std::stringstream iss(line);
        string auxin;

        // Leer los campos de la línea
        iss>>nuevoTipo.idClase>>coma;
        getline(iss,auxin,coma);
        iss>>nuevoTipo.horario>>coma;
        nuevoTipo.nombreClase=auxin;
        tipos[N-1]=nuevoTipo;
    }
    archi.close();

    sTipo* tiposNuevo=new sTipo[N];
    Actualizar_estructura(tipos,tiposNuevo,N);
    delete[] tipos;
    sGimnasio Musculito;
    Musculito.misClases=tiposNuevo;
    Musculito.misClientes=clientes;

    int Nins=0, Nas=0;
    sAsistencia* archi_inscripcion = new sAsistencia[Nins];

    int PersonasAInscribirse=10;
    for(int i=0 ; i<PersonasAInscribirse;i++){
        sCliente* clienteActual=RandomSeleccionCliente(clientes);
        sTipo* ClaseElegida=Inscribirse(tiposNuevo,N);
        eReserva reserva= Reserva(clienteActual,ClaseElegida,archi_inscripcion,Nins);
        std::cout << "\033[1;32m";
        std::cout << "La Reserva fue exitosa, para el cliente con ID : " << clienteActual->idCliente;
        std::cout << "\033[0m" << std::endl;

        std::cout << "\033[4;36m";
        std::cout << "Para la clase " << ClaseElegida->nombreClase;
        std::cout << "\033[0m" << std::endl; // Restaura el color

        std::cout << "\033[1;35m";
        std::cout << "A las: " << ClaseElegida->horario;
        std::cout << "\033[0m" << std::endl;
    }

    //"termino las reservas", lo paso a archivo de asistencia
    sAsistencia* archi_asistencia = new sAsistencia[Nas];
    copiar_archivo(archi_inscripcion,archi_asistencia,Nas);


    delete[] clientes;
    delete[] tiposNuevo;
    delete[] archi_inscripcion;
    delete[] archi_asistencia;

    return 0;
}

