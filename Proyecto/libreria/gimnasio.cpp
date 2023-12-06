#include "gimnasio.h"
#include "cliente.cpp"

eReserva Reserva(sCliente* cliente ,sTipo* clase,sAsistencia* asistPrevia,int &n){

    bool ok=VerificarClase(clase);
    if(ok==false) {

        return eReserva::DatosIncorrectos;
    }
    //datos correctos

    //verificar espacio disp
    if(clase->cupoActual>=clase->cupoMax){
        //no hay mas lugar
        return eReserva::CuposLlenos;
    }
        //tengo lugar
        //ver si esta endeudado
        bool x = EstadoCuenta(cliente); //ver si es & o sin nada
        if (x==false) //endeudado
            return eReserva::EnDeuda;
        //verifico si el usuario ya esta inscripto para otra clase en el mismo horario de inicio
        bool esta=YaInscriptoHorario(clase->horario,cliente->idCliente,asistPrevia,n);
        if (esta==true)
            return eReserva::Superposicion;

        //si esta todo en orden entonces:
        AgregarClienteArchivoInscri(cliente, asistPrevia,n,clase->idClase);
        clase->cupoActual=clase->cupoActual+1; //incremento cupo
        return eReserva::ReservaExitosa;
}

bool VerificarClase (sTipo* clase){
    if(clase==nullptr)
            return false;
    else if (clase->nombreClase != "Spinning" && clase->nombreClase != "Yoga" && clase->nombreClase != "Pilates"  && clase->nombreClase != "Stretching" && clase->nombreClase !="Zumba" && clase->nombreClase !="Boxeo" && clase->nombreClase !="Musculacion"){
        //clase invalida
        return false;
    }
    return true;
}
void AgregarClienteArchivoInscri(sCliente*& cliente, sAsistencia*& asistPrev, int& n,int idCurso){
    int cont=0;
    for (int i=0;i<n;i++) //si esta el cliente subido con otra clase
    {
        if(asistPrev[i].idCliente==cliente->idCliente){ //veo si esta
            cont++;
            asistPrev[i].cantInscriptos=asistPrev[i].cantInscriptos+1;

            // Asignar memoria para el nuevo curso inscrito
            asistPrev[i].CursosInscriptos = new sInscripcion[asistPrev[i].cantInscriptos];

            // Asignar la fecha de inscripción y el ID del curso al nuevo curso inscrito
            asistPrev[i].CursosInscriptos[asistPrev[i].cantInscriptos - 1].fechaInscripcion = time(0);
            asistPrev[i].CursosInscriptos[asistPrev[i].cantInscriptos - 1].idCurso = idCurso;
        }

    }
    if (cont==0){//entonces no estaba hacer un lugarcito "cajoncito nuevo" para el
        //planteo resize para darle lugar en memoria

        int N;
        N=(n)+1;
        sAsistencia *aux= new sAsistencia [N];
        for(int i=0;i<N-1;i++){
            aux [i]= asistPrev [ i ];
        }
        aux[N-1].cantInscriptos=1;

        // Asignar memoria para el nuevo curso inscrito
        aux[N-1].CursosInscriptos = new sInscripcion[aux[N-1].cantInscriptos];

        // Asignar la fecha de inscripción y el ID del curso al nuevo curso inscrito
        aux[N-1].CursosInscriptos[aux[N-1].cantInscriptos - 1].fechaInscripcion = time(0);
        aux[N-1].CursosInscriptos[aux[N-1].cantInscriptos - 1].idCurso = idCurso;

        delete [ ] asistPrev;
        asistPrev = aux;
    }
}
