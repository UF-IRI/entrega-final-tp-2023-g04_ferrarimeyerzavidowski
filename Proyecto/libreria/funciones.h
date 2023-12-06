#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "cliente.h"




sCliente* RandomSeleccionCliente(sCliente*Cliente); //le paso el archivo por parametro
bool YaInscriptoHorario(time_t horario,unsigned int idCliente,sAsistencia *asistPrevia, int n);
void Actualizar_estructura(sTipoLectura*tiposlectura,sTipo*tipos,int N);
int ClaseCupoMax(string nombreclase);
//time_t ConvertirFechaATime_t(const std::string& fechaStr);
std::time_t ConvertirFechaATime_t(const std::string& fechaStr);
void resizeAsist(sAsistencia*& asistencia, int &n);
void copiar_archivo(sAsistencia* archi_inscripcion, sAsistencia *&archi_asistencia, int &nasist);
#endif // FUNCIONES_H
