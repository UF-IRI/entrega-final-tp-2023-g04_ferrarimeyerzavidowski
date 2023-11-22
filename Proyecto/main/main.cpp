#include "encabezados.h"
#include "archivos.h"
#include "gimnasio.h"
#include "funciones.h"

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
    int n= 0;
    sCliente* clientes = new sCliente[n];
    LeerClientes(&archivoclientes, clientes,n);
    Musculito.misClientes=clientes;
    archivoclientes.close();
    int Nins=0, Nas=0;
    sAsistencia* archi_inscripcion = new sAsistencia[Nins];
    sAsistencia* archi_asistencia = new sAsistencia[Nas];
    //funcion copiar uno a uno, recibo las dos listas de arriba y voy llamando al resize de archi_asistencia para copiar de una a otra
    delete[]clientes;
    delete[]tipos;

    return 0;

}
