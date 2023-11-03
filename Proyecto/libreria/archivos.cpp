#include <archivos.h>
eCodArchivos LeerClases(ifstream *archi,sTipoLectura* tipos)
{

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    string header;
    getline(*archi, header);

    unsigned int auxidClases;
    string auxNombre;
    time_t auxhorario;
    char coma;
    int i=0;

    while(*archi>>auxidClases>>coma>>auxNombre>>coma>>auxhorario){
        (tipos+i)->idClase=auxidClases;
        (tipos+i)->nombreClase=auxNombre;
        (tipos+i)->horario=auxhorario;
        i++;
    }
    return eCodArchivos::ExitoOperacion;
}
eCodArchivos LeerClientes(fstream *archi,sCliente *clientes)
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
        (clientes+i)->apellido=auxap;
        (clientes+i)->email=auxnom;
        (clientes+i)->estado=auxest;
        (clientes+i)->fechaNac=auxfecha;
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
}


