#ifndef CLASES_H
#define CLASES_H
#include "encabezados.h"

enum Clase {Musculacion=0,Spinning,Yoga,Pilates,Stretching,Zumba,Boxeo};
typedef enum Clase eClase;
struct Clase{
    unsigned int idClase;
    eClase nombreClase;
    float horario;
};typedef struct Clase sClase;

#endif // CLASES_H
