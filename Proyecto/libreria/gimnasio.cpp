#include "gimnasio.h"
#include "cliente.cpp"

eReserva Reserva(sCliente* cliente ,sTipo* clase,sAsistencia* asistPrevia,int &n){

    time_t horaInicioGym, horaFinGym;
    struct tm* tm_info; //de libreria

    //vamos a hacer todo en seg, cada hora se simula como 1 seg
    //por eso se establece la hora de inicio a las 8 segundos.
    tm_info = localtime(&(clase->horario)); //la funcion localtime (libreria) va a desglosar una variable de time-t a la estructura de libreria
    //& porque le paso la direc de memoria en donde se encuentra esa clase
    tm_info->tm_hour = 0;
    tm_info->tm_min = 0;
    tm_info->tm_sec = 8;
    horaInicioGym = mktime(tm_info); //paso de la struct tm a una variable de time-t

    //ahora cuando cierra (19 hs)
    tm_info->tm_hour = 0;
    tm_info->tm_min = 0;
    tm_info->tm_sec = 19;
    horaFinGym = mktime(tm_info);

    //verificamos ingreso de datos (sean validos)
    if (clase->horario < horaInicioGym && clase->horario > horaFinGym) {
        // El horario está entre las 8 y las 19 segundos.
        // Puedes continuar con la reserva.
        return eReserva::DatosIncorrectos;
    }

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
void AgregarClienteArchivoInscri(sCliente*& cliente, sAsistencia* asistPrev, int& n,int idCurso){
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
        asistPrev[N].cantInscriptos=asistPrev[N].cantInscriptos+1;

        // Asignar memoria para el nuevo curso inscrito
        asistPrev[N].CursosInscriptos = new sInscripcion[asistPrev[N].cantInscriptos];

        // Asignar la fecha de inscripción y el ID del curso al nuevo curso inscrito
        asistPrev[N].CursosInscriptos[asistPrev[N].cantInscriptos - 1].fechaInscripcion = time(0);
        asistPrev[N].CursosInscriptos[asistPrev[N].cantInscriptos - 1].idCurso = idCurso;

        delete [ ] asistPrev;
        asistPrev = aux;
    }
}
