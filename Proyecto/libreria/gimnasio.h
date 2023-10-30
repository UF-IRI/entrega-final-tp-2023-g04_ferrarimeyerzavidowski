#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <encabezados.h>
#include <cliente.h>
#include <tipo.h>

struct Gimnasio{
    string nombre;
    sCliente* misClientes;
    sTipo* misClases;
};typedef struct Gimnasio sGimnasio;

enum ReservaCliente{ReservaExitosa=1,CuposLlenos=-1,YaInscripto=0,Superposicion=-2,EnDeuda=-3};
typedef ReservaCliente eReserva;

eReserva Reserva(sCliente* cliente ,sTipo* clase); //ojo verificar si esta endeudado
void AgregarClienteArchivoInscri(sCliente* cliente);

#endif // GIMNASIO_H
