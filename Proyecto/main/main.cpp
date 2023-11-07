#include "encabezados.h"
#include "archivos.cpp"
#include "funciones.cpp"

int main() {
    ifstream archivoclase;
    archivoclase.open("../entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClasesGYM.csv");
    int N=-1;
    sTipoLectura* tiposlectura=new sTipoLectura[N];
    resizeTipos(tiposlectura,N);
    LeerClases(&archivoclase,tiposlectura);
    archivoclase.close();
    Actualizar_estructura(tiposlectura);
    delete[] tiposlectura;


    ifstream archivoclientes;
    archivoclientes.open("../entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClientesGYM.csv");
    int n= -1;
    sCliente* clientes = new sCliente[n];
    resizeClientes(clientes, n);
    LeerClientes(&archivoclientes, clientes);
    archivoclientes.close();
    delete [ ] clientes;


    return 0;


}
