#include "encabezados.h"
#include "archivos.cpp"
#include "funciones.cpp"
int main() {
    ifstream archivoclase;
    archivoclase.open("../entrega-final-tp-2023-g04_ferrarimeyerzavidowski/iriClasesGYM.csv");
    int N=-1;
    sTipoLectura* tipos=new sTipoLectura[N];
    resizeTipos(tipos,N);
    LeerClases(&archivoclase,tipos);
    archivoclase.close();


    delete[] tipos;
    return 0;
}
