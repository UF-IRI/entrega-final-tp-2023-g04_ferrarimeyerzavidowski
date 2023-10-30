#ifndef TIPO_H
#define TIPO_H
#include <encabezados.h>

enum Clase {Musculacion=0,Spinning,Yoga,Pilates,Stretching,Zumba,Boxeo};
typedef enum Clase eClase;

struct Tipo{
    unsigned int idClase;
    eClase nombreClase;
    time_t horario;
};typedef struct Tipo sTipo;

#endif // TIPO_H
