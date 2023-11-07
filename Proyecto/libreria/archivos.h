#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "asistencia.h"
#include "cliente.h"
#include <sstream>


typedef enum codArchivos{ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1,BorradoExitoso=2,ErrorBorrado=-2} eCodArchivos;

eCodArchivos LeerClases(ifstream *archi,sTipoLectura* tipos);
eCodArchivos LeerClientes(fstream *archi,sCliente *clientes);
eCodArchivos LeerAsistencia(fstream * archi,sAsistencia* asistencia);
eCodArchivos EscribirAsistencia(fstream *archi,sAsistencia* asistencia); //sobreesribo el archivo con las cosas de archivo inscripcion; veriffico que no esten repetidos sino no copio
eCodArchivos BorrarArchInscripcion(fstream* archi,sInscripcion* inscripcion); //lo limpio para el prox dia
eCodArchivos EscribirInscripcion(fstream* archi,sInscripcion* inscripcion); //verifico que no este repetido sino no copio

#endif // ARCHIVOS_H
