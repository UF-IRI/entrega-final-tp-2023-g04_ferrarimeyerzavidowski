#include "encabezados.h"
#include "archivos.cpp"
#include "gimnasio.h"
#include "funciones.cpp"

int main() {
    ifstream archivoclase;
    archivoclase.open("../entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClasesGYM.csv");
    int N=-1;
    sTipoLectura* tiposlectura=new sTipoLectura[N];
    LeerClases(&archivoclase,tiposlectura,N);
    archivoclase.close();
    sTipo* tipos=new sTipo[N];
    Actualizar_estructura(tiposlectura,tipos,N);
    delete[] tiposlectura; //lo cierro porq ya no lo necesito
    sGimnasio Musculito;
    Musculito.misClases=tipos; //le asigno las clases

    ifstream archivoclientes;
    archivoclientes.open("../entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClientesGYM.csv");
    int n= -1;
    sCliente* clientes = new sCliente[n];
    LeerClientes(&archivoclientes, clientes,n);
    Musculito.misClientes=clientes;
    archivoclientes.close();




    delete[]clientes;
    delete[]tipos;

    return 0;

}
