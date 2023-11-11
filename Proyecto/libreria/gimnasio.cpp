#include "gimnasio.h"

eReserva Reserva(sCliente* cliente ,sTipo* clase,sAsistencia* asistPrevia){

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
    if(ok==false)  return eReserva::DatosIncorrectos;

    //datos correctos

    //verificar espacio disp
    if(clase->cupoActual>=clase->cupoMax){
        //no hay mas lugar
        return eReserva::CuposLlenos;
    }
        //tengo lugar
        //ver si esta endeudado
        bool x=EstadoCuenta(cliente); //ver si es & o sin nada
        if (x==false) //endeudado
            return eReserva::EnDeuda;

        //verifico si el usuario ya esta inscripto para otra clase en el mismo horario de inicio
        bool esta=YaInscriptoHorario(clase->horario,cliente->idCliente,asistPrevia);
        if (esta==true)
            return eReserva::Superposicion;

        //si esta todo en orden entonces:
        AgregarClienteArchivoInscri(cliente);
        clase->cupoActual=clase->cupoActual+1; //incremento cupo
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
