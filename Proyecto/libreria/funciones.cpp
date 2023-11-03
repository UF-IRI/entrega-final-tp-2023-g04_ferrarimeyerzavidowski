#include "funciones.h"

void resizeTipos(sTipoLectura*& tipos, int &n){
    n=(n)+1;
    sTipoLectura *aux=new sTipoLectura[n];
    for(int i=0;i<n-1;i++){
        aux[i]=tipos[i];}
    delete[] tipos;
    tipos=aux;
}
