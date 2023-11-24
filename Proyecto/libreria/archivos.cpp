#include "archivos.h"

// Función para redimensionar el arreglo dinámico
void resizeTipos(sTipoLectura*& tipos, int& n) {
    n++;
    sTipoLectura* aux = new sTipoLectura[n];
    for (int i = 0; i < n - 1; i++) {
        aux[i] = tipos[i];
    }
    delete[] tipos;
    tipos = aux;
}

// Función para leer clases desde un archivo CSV
eCodArchivos LeerClases(ifstream* archi, sTipoLectura*& tipos, int& n) {
    if (!archi->is_open()) {
       return eCodArchivos::ErrorApertura;
    }

    string linea;
    getline(*archi, linea);  // Leer la línea de encabezado y descartarla

    while (getline(*archi, linea)) {
        stringstream ss(linea);
        char coma;

        // Leer los campos de la línea
        ss >> tipos[n].idClase >> coma >> tipos[n].nombreClase >> coma >> tipos[n].horario;

        // Incrementar el contador
        n++;

        // Redimensionar el arreglo dinámico
        resizeTipos(tipos, n);
    }
    return eCodArchivos::ExitoOperacion;
}

/*eCodArchivos LeerClientes(ifstream *archi,sCliente *clientes, int&n)
{
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    string header;
    getline(*archi, header);

    unsigned int auxid;
    int auxest;
    string auxap,auxnom,auxem,auxtel;
    time_t auxfecha;
    char coma;
    int i=0;

    while(*archi>>auxid>>coma>>auxnom>>coma>>auxap>>coma>>auxem>>coma>>auxtel>>coma>>auxfecha>>coma>>auxest){
        resizeClientes(clientes,n);
        (clientes+i)->apellido=auxap;
        (clientes+i)->email=auxnom;
        (clientes+i)->estado=auxest;
        (clientes+i)->fechaNac=auxfecha; //OJOOOO VERIFICAR SI SE ESTA GUARDANDO BIEN COMO VARIABLE TIME-T, SINO HACER UNA FUNCION APARTE
        (clientes+i)->idCliente=auxid;
        (clientes+i)->nombre=auxnom;
        (clientes+i)->telefono=auxtel;
        i++;
    }
    return eCodArchivos::ExitoOperacion;
}
eCodArchivos LeerAsistencia(fstream * archi,sAsistencia* asistencia)
{
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

  //leemos la struct completa
    archi->read((char*)asistencia, sizeof(sAsistencia));

    if(!*archi){
        return eCodArchivos::ErrorEscritura;
    }

    return eCodArchivos::ExitoOperacion;
}
eCodArchivos BorrarArchInscripcion(fstream* archi,sInscripcion* inscripcion){
    if (!archi->is_open()) {
        return eCodArchivos::ErrorApertura;
    }

    // Cierra el archivo para evitar problemas al truncarlo
    archi->close();

    // Abre el archivo en modo de escritura con truncamiento
    archi->open("asistencia.dat", std::ios::binary | std::ios::out | std::ios::trunc);

    if (archi->is_open()) {
        // El archivo se ha truncado con éxito y está vacío
        return eCodArchivos::BorradoExitoso;
    } else
        return eCodArchivos::ErrorBorrado;
}
eCodArchivos EscribirAsistencia(fstream *archi,sAsistencia* asistencia){

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->write((char*)asistencia, sizeof(sAsistencia));

    return eCodArchivos::ExitoOperacion;
}
eCodArchivos EscribirInscripcion(fstream* archi,sInscripcion* inscripcion){
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->write((char*)inscripcion, sizeof(sInscripcion));

    return eCodArchivos::ExitoOperacion;
}*/
