#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <encabezados.h>
#include <cliente.h>
#include <tipo.h>
#include <funciones.h>

struct Gimnasio{
    string nombre;
    sCliente* misClientes;
    sTipo* misClases;
};typedef struct Gimnasio sGimnasio;

enum ReservaCliente{ReservaExitosa=1,CuposLlenos=-1,Superposicion=-2,EnDeuda=-3,DatosIncorrectos=-5};
typedef ReservaCliente eReserva;

eReserva Reserva(sCliente* cliente ,sTipo* clase);
void AgregarClienteArchivoInscri(sCliente* cliente);
bool VerificarClase (sTipo* clase);

#endif // GIMNASIO_H
