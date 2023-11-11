#ifndef GIMNASIO_H
#define GIMNASIO_H
#include "funciones.h"

struct Gimnasio{
    string nombre;
    sCliente* misClientes;
    sTipo* misClases;
};typedef struct Gimnasio sGimnasio;

enum ReservaCliente{ReservaExitosa=1,CuposLlenos=-1,Superposicion=-2,EnDeuda=-3,DatosIncorrectos=-5};
typedef ReservaCliente eReserva;

eReserva Reserva(sCliente* cliente ,sTipo* clase,sInscripcion* inscripcion);
void AgregarClienteArchivoInscri(sCliente* cliente);
bool VerificarClase (sTipo* clase);

#endif // GIMNASIO_H
