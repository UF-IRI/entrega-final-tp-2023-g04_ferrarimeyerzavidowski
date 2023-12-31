#ifndef ASISTENCIA_H
#define ASISTENCIA_H
#include "tipo.h" //incluye encabezado


typedef struct {
    unsigned int idCurso;
    time_t fechaInscripcion;
} sInscripcion;

typedef struct {
    unsigned int idCliente, cantInscriptos;
    sInscripcion* CursosInscriptos;
} sAsistencia;


#endif // ASISTENCIA_H
