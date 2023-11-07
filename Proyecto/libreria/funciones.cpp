#include "funciones.h"

void resizeTipos(sTipoLectura*& tipos, int &n){
    n=(n)+1;
    sTipoLectura *aux=new sTipoLectura[n];
    for(int i=0;i<n-1;i++){
        aux[i]=tipos[i];}
    delete[] tipos;
    tipos=aux; //actualizas con los nuevos cambios
}

void resizeClientes(sCliente*&clientes, int &n){

    n=(n)+1;
    sCliente *cli= new sCliente [n];
    for(int i=0;i<n-1;i++){
        cli [i]= clientes [ i ];
    }
    delete [ ] clientes;
    clientes = cli; //actualizas con los nuevos cambios
}
