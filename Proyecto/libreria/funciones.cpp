#include "funciones.h"

void resizeTipos(sTipoLectura*& tipos, int& n){
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

void Actualizar_estructura(sTipoLectura*tiposlectura,sTipo*tipos,int N){
    for (int i=0;i<N;i++)
    {//copio miembro a miembro porque no son la misma estructura
        tipos[i].idClase=tiposlectura[i].idClase;
        tipos[i].nombreClase=tiposlectura[i].nombreClase;
        tipos[i].horario=tiposlectura[i].horario;
        tipos[i].cupoActual=0;
        int cupos_max= ClaseCupoMax(tiposlectura[i].nombreClase); //en base a que clase es veo cual es el cupo max
        tipos[i].cupoMax=cupos_max;
    }
}
int ClaseCupoMax(string nombreclase){
    int num=0;
    if(nombreclase=="Spinning")
        num=45;
    else if (nombreclase=="Yoga")
        num=25;
    else if (nombreclase=="Pilates")
        num=15;
    else if (nombreclase=="Stretching")
        num=40;
    else if(nombreclase=="Zumba")
        num=50;
    else if(nombreclase=="Boxeo"||nombreclase=="Musculacion")
        num=30;

    return num;
}

/*bool YaInscriptoHorario(time_t horario,unsigned int idCliente,sAsistencia *asistPrevia,int N){
    int tam=asistPrevia->size();
    sInscripcion* aux=asistPrevia->CursosInscriptos;
    int tamin=aux->length();
    for (int i=0;i<tam;i++){ //recorro la lista asistPrevia
        for(int j=0;j<tamin;j++){ //recorro la lista de cursosInscriptos
            if(asistPrevia[i].idCliente == idCliente) //&& aux[j]==el horario)
                //OJOOOO NO TENGO ACCESO AL HORARIO DE LAS CLASES DENTRO DE INSCRIPCION O ASISTENCIA!!!!!!!
                return true;
        }
    }
    return false;
}*/
sTipo* RandomSeleccionClase(sTipo* tipos){
    int IndiceAleatorio = rand()%60+1;
    sTipo& elementoSeleccionado = tipos[IndiceAleatorio];
    sTipo* punteroSTipo = new sTipo{elementoSeleccionado.idClase, elementoSeleccionado.nombreClase, elementoSeleccionado.horario};
    return punteroSTipo;
}

