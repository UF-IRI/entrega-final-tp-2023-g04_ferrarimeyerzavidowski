#ifndef CLIENTE_H
#define CLIENTE_H
#include "encabezados.h"
#include "clases.h"

struct Cliente {
    unsigned int idCliente;
    string nombre;
    string apellido;
    string email;
    string telefono;
    string fechaNac;
    int estado;
};typedef struct Cliente sCliente;

bool Inscribirse(); //random para obtener horario y que clase ir  (usar el archivo de clases (.csv))
void EstadoCuenta(); //chequear estado y pagar lo faltante "set del estado"
void DarseDeBaja(sClase* clase,float horario);

#endif // CLIENTE_H
