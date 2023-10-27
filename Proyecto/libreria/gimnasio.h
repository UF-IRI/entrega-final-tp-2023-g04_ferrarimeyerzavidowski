#ifndef GIMNASIO_H
#define GIMNASIO_H
#include "encabezados.h"
#include "cliente.h"
#include "clases.h"

struct Gimnasio{
    string nombre;
    sCliente* misClientes;
    sClase* misClases;
};

enum ReservaCliente{ReservaExitosa=1,CuposLlenos=-1,YaInscripto=0,Superposicion=-2,EnDeuda=-3};
typedef ReservaCliente eReserva;

eReserva Reserva(float hora,sClase* clase); //ojo verificar si esta endeudado
void AgregarClienteArchivo(sCliente* cliente);


#endif // GIMNASIO_H
