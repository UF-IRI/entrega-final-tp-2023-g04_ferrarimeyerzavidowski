
#include "archivos.cpp"
#include "gimnasio.cpp"

int main() {
    ifstream archi;
    archi.open("iriClasesGYM.csv", ios::in);
    int N=0;
    sTipoLectura* tipos=new sTipoLectura[N];
    if (!archi.is_open()) {
        return -1;
    }

    string linea;
    getline(archi, linea);  // Leer la línea de encabezado y descartarla

    while (getline(archi, linea)) {
        stringstream ss(linea);
        char coma;

        // Leer los campos de la línea
        ss >> tipos[N].idClase >> coma >> tipos[N].nombreClase >> coma >> tipos[N].horario;

        // Incrementar el contador
        N++;

        // Redimensionar el arreglo dinámico
        resizeTipos(tipos, N);
    }
    archi.close();
    ifstream archi2;
    archi2.open("iriClientesGYM.csv", ios::in);
    int n=0;
    sCliente *cli= new sCliente [n];
    if(!archi2->is_open()){
            return -1;
    }
        string linea;
        getline(archi, linea);

        unsigned int auxid;
        int auxest;
        string auxap,auxnom,auxem,auxtel;
        time_t auxfecha;
        char coma;
        int i=0;

        while(*archi2>>auxid>>coma>>auxnom>>coma>>auxap>>coma>>auxem>>coma>>auxtel>>coma>>auxfecha>>coma>>auxest){
            resizeClientes(clientes,n);
            (clientes+i)->apellido=auxap;
            (clientes+i)->email=auxnom;
            (clientes+i)->estado=auxest;
            (clientes+i)->fechaNac=auxfecha; //OJOOOO VERIFICAR SI SE ESTA GUARDANDO BIEN COMO VARIABLE TIME-T, SINO HACER UNA FUNCION APARTE
            (clientes+i)->idCliente=auxid;
            (clientes+i)->nombre=auxnom;
            (clientes+i)->telefono=auxtel;
            i++;
        }
        return eCodArchivos::ExitoOperacion;


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
