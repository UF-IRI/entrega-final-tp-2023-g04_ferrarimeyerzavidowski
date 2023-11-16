#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cliente.h"
#include "asistencia.h"

sCliente* RandomSeleccionCliente(sCliente*Cliente); //le paso el archivo por parametro
sTipo* RandomSeleccionClase(sTipo* tipos); //le paso el archivo por parametro
bool YaInscriptoHorario(time_t horario,unsigned int idCliente,sAsistencia *asistPrevia, int n);
void resizeTipos(sTipoLectura*& tipos, int& n);
void resizeClientes(sCliente*&clientes, int &n);
void Actualizar_estructura(sTipoLectura*tiposlectura,sTipo*tipos,int N);
int ClaseCupoMax(string nombreclase);
void copiar_archivo(sAsistencia* archi_inscripcion, sAsistencia* archi_asistencia);
#endif // FUNCIONES_H
