#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "cliente.h" //incluyo el asistencia.h
#include "funciones.h"


typedef enum codArchivos{ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1,BorradoExitoso=2,ErrorBorrado=-2} eCodArchivos;

eCodArchivos LeerAsistencia(fstream * archi,sAsistencia* asistencia);
eCodArchivos EscribirAsistencia(fstream *archi,sAsistencia* asistencia); //sobreesribo el archivo con las cosas de archivo inscripcion; veriffico que no esten repetidos sino no copio
eCodArchivos BorrarArchInscripcion(fstream* archi,sInscripcion* inscripcion); //lo limpio para el prox dia
eCodArchivos EscribirInscripcion(fstream* archi,sInscripcion* inscripcion); //verifico que no este repetido sino no copio
void copiar_archivo(sAsistencia* archi_inscripcion, sAsistencia* archi_asistencia);
void resizeClientes(sCliente*&clientes, int &n);
void resizeTipos(sTipoLectura*& tipos, int& n);
#endif // ARCHIVOS_H
