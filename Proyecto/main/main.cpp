
#include "archivos.cpp" //tiene a gimnasio
#include "funciones.cpp"
#include "gimnasio.cpp"

int main() {
    ifstream archivoclase;
    archivoclase.open("iriClasesGYM.csv", ios::in);
    int N=0;
    sTipoLectura* tiposlectura=new sTipoLectura[N];
    eCodArchivos a = LeerClases(&archivoclase, tiposlectura, N);
    archivoclase.close();
    /*sTipo* tipos=new sTipo[N];
    Actualizar_estructura(tiposlectura,tipos,N);
    delete[] tiposlectura;
    sGimnasio Musculito;
    Musculito.misClases=tipos;

    ifstream archivoclientes;
    archivoclientes.open("iriClientesGYM.csv", ios::in);
    int n= 0;
    sCliente* clientes = new sCliente[n];
    LeerClientes(&archivoclientes, clientes, n);
    Musculito.misClientes=clientes;
    archivoclientes.close();
    int Nins=0, Nas=0;
    sAsistencia* archi_inscripcion = new sAsistencia[Nins];
    sAsistencia* archi_asistencia = new sAsistencia[Nas];
    //funcion copiar uno a uno, recibo las dos listas de arriba y voy llamando al resize de archi_asistencia para copiar de una a otra
    delete[] clientes;
    delete[] tipos;*/

    return 0;
}
