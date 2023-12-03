#ifndef TIPO_H
#define TIPO_H
#include "encabezados.h"

struct TipoLectura{
    unsigned int idClase;
    string nombreClase;
    unsigned int horario;
};typedef struct TipoLectura sTipoLectura;

struct Tipo{
    unsigned int idClase;
    string nombreClase;
    unsigned int horario;
    unsigned int cupoMax;
    unsigned int cupoActual;
};typedef struct Tipo sTipo;

#endif // TIPO_H
