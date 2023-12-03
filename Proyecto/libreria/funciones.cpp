#include "funciones.h"
#include <iomanip>



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
// Función para convertir una cadena de fecha en formato específico a time_t
time_t ConvertirFechaATime_t(const std::string& fechaStr) {
    std::tm tm = {};

    std::istringstream iss(fechaStr);
    char dash;  // Variable para almacenar el guion entre los componentes de la fecha

    // Lee los componentes de la fecha directamente
    iss >> tm.tm_mday >> dash >> tm.tm_mon >> dash >> tm.tm_year;

    // Convierte la estructura tm a time_t
    time_t tiempo = mktime(&tm);

    return tiempo;
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


bool YaInscriptoHorario(time_t horario, unsigned int idCliente, sAsistencia *asistPrevia, int n) {
    for (int i = 0; i < n; ++i) {
        sInscripcion *aux = asistPrevia[i].CursosInscriptos;

        for (int j = 0; aux[j].fechaInscripcion != 0; ++j) {
            if (asistPrevia[i].idCliente == idCliente && aux[j].fechaInscripcion == horario) {
                return true;
            }
        }
    }
    return false;
}


sCliente* RandomSeleccionCliente(sCliente*Cliente){
    int ClienteAleatorio = rand()%250+1;
    sCliente& CleinteSeleccionado = Cliente[ClienteAleatorio];
    sCliente* punteroSCliente = new sCliente{CleinteSeleccionado.idCliente, CleinteSeleccionado.nombre, CleinteSeleccionado.apellido, CleinteSeleccionado.email ,CleinteSeleccionado.telefono, CleinteSeleccionado.fechaNac, CleinteSeleccionado.estado};
    return punteroSCliente;
}

void copiar_archivo(sAsistencia* archi_inscripcion, sAsistencia*& archi_asistencia,int& nasist)
{
    for (int i = 0; i < nasist; ++i) {
        // Verifica si es necesario redimensionar archi_asistencia
        if (i >= nasist)
            resizeAsist(archi_asistencia,nasist);

       // Copiar los datos desde archi_inscripcion a archi_asistencia
        archi_asistencia[i] = archi_inscripcion[i];
    }
}

void resizeAsist(sAsistencia*& asistencia, int &n)
{
    n++;
    sAsistencia* aux = new sAsistencia[n];
    for (int i = 0; i < n - 1; i++) {
        aux[i] = asistencia[i];
    }
    delete[]asistencia;
    asistencia = aux;
}
