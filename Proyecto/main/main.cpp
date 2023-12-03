
#include "archivos.cpp"
#include "gimnasio.cpp"
#include "funciones.cpp"


int main() {

    ifstream archi2;
    archi2.open("iriClientesGYM.csv", ios::in);
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

        // Lee los campos de la línea
        iss >> nuevoCliente.idCliente >> coma;
        getline(iss, auxn, coma);
        getline(iss, auxa, coma);
        getline(iss, auxe, coma);
        getline(iss, auxtel, coma);
        string fechaNacStr;
        getline(iss, fechaNacStr, coma);
        nuevoCliente.fechaNac = ConvertirFechaATime_t(fechaNacStr);
        iss >>nuevoCliente.estado >> coma;
        nuevoCliente.nombre=auxn;
        nuevoCliente.apellido=auxa;
        nuevoCliente.email=auxe;
        nuevoCliente.telefono=auxtel;
        clientes[n-1]=nuevoCliente;
    }
    archi2.close();


    ifstream archi;
    archi.open("iriClasesGYM.csv", ios::in);
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

    int PersonasAInscribirse=5;
    for(int i=0 ; i<5;i++){
        sCliente* clienteActual=RandomSeleccionCliente(clientes);
        sTipo* ClaseElegida=Inscribirse(tiposNuevo,N);
        eReserva reserva= Reserva(clienteActual,ClaseElegida,archi_inscripcion,Nins);

        std::cout<<"La Reserva fue"<<reserva<<",para el cliente con id:"<<clienteActual->idCliente<<endl;
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
