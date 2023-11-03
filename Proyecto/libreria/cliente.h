#ifndef CLIENTE_H
#define CLIENTE_H
#include "encabezados.h"
#include "tipo.h"

struct Cliente {
    unsigned int idCliente;
    string nombre;
    string apellido;
    string email;
    string telefono;
    time_t fechaNac;
    int estado;
};typedef struct Cliente sCliente;

//funcion inscribirse necesita por parametros el archivos de las clase
sTipo* Inscribirse(); //random para obtener horario y que clase ir  (usar el archivo de clases (.csv))

bool EstadoCuenta(sCliente* cliente); //chequear estado y pagar lo faltante "set del estado"

#endif // CLIENTE_H
