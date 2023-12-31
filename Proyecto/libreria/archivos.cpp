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

void resizeClientes(sCliente*& clientes, int& n) {
    n++;
    sCliente* aux = new sCliente[n];
    for (int i = 0; i < n - 1; i++) {
        aux[i] = clientes[i];
    }
    delete[] clientes;
    clientes = aux;
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
