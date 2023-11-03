#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cliente.h"

sCliente* RandomSeleccionCliente(); //le paso el archivo por parametro
sTipo* RandomSeleccionClase(); //le paso el archivo por parametro
bool YaInscriptoHorario(time_t horario,unsigned int idCliente);

#endif // FUNCIONES_H
