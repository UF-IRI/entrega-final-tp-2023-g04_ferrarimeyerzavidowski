#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cliente.h"
#include "asistencia.h"

sCliente* RandomSeleccionCliente(); //le paso el archivo por parametro
sTipo* RandomSeleccionClase(); //le paso el archivo por parametro
bool YaInscriptoHorario(time_t horario,unsigned int idCliente,sAsistencia *asistPrevia);
void resizeTipos(sTipoLectura*& tipos, int& n);
void resizeClientes(sCliente*&clientes, int &n);
void Actualizar_estructura(sTipoLectura*tiposlectura,sTipo*tipos,int N);
int ClaseCupoMax(string nombreclase);
#endif // FUNCIONES_H
