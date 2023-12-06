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
/*time_t ConvertirFechaATime_t(const std::string& fechaStr) {
    std::tm tm = {0};

    std::istringstream iss(fechaStr);
    char dash;  // Variable para almacenar el guion entre los componentes de la fecha

    // Lee los componentes de la fecha directamente
    iss >> tm.tm_mday >> dash >> tm.tm_mon;
    tm.tm_mon--;
    iss>> dash >> tm.tm_year;
    tm.tm_year-=1900;
    // Convierte la estructura tm a time_t
    time_t tiempo = mktime(&tm);

    return tiempo;
}*/

/*std::time_t ConvertirFechaATime_t(const std::string& fechaStr, bool is_dst, const std::string& format) {
    std::tm tm = {0};
    tm.tm_isdst = is_dst ? 1 : 0;

    std::istringstream ss(fechaStr);
    ss >> std::get_time(&tm, format.c_str());

    // Verifica si la conversión fue exitosa
    if (ss.fail()) {
        std::cerr << "Error al convertir la fecha: " << fechaStr << std::endl;
        return -1;  // Indica un error
    }

    return std::mktime(&tm);
}*/
/*std::time_t ConvertirFechaATime_t(const std::string& fecha) {
    std::tm tiempo = {0};
    std::istringstream ss(fecha);
    ss.imbue(std::locale("es_ES.utf-8"));
    ss >> std::get_time(&tiempo, "%d/%m/%Y");
    std::time_t time_tValue = std::mktime(&tiempo);
    return time_tValue;
}*/

std::time_t ConvertirFechaATime_t(const std::string& fechaStr) {
    std::tm tiempo = {0};
    std::istringstream ss(fechaStr);

    char delim;  // Carácter separador entre los componentes de la fecha

    // Lee los componentes de la fecha
    ss >> tiempo.tm_mday >> delim >> tiempo.tm_mon >> delim >> tiempo.tm_year;

    // Verifica si la lectura fue exitosa
    if (ss.fail()) {
        std::cerr << "Error al convertir la fecha: " << fechaStr << std::endl;
        return -1;  // Indica un error
    }

    // Ajusta la estructura tm
    tiempo.tm_mon--;   // Ajusta el mes para que esté en el rango 0-11
    tiempo.tm_year -= 1900;  // Ajusta el año para que sea compatible con la estructura tm

    // Validación de rangos para los componentes de la fecha
    if (tiempo.tm_mday < 1 || tiempo.tm_mday > 31 || tiempo.tm_mon < 0 || tiempo.tm_mon > 11 || tiempo.tm_year < 0) {
        std::cerr << "Fecha inválida: " << fechaStr << std::endl;
            return -1;  // Indica un error
    }

    std::time_t time_tValue = std::mktime(&tiempo);

    if (time_tValue == -1) {
        std::cerr << "Error al convertir la estructura tm a time_t." << std::endl;
        std::cerr << "Fecha: " << fechaStr << std::endl;
        std::cerr << "Componentes de la fecha: " << tiempo.tm_mday << ", " << tiempo.tm_mon << ", " << tiempo.tm_year << std::endl;
    }

    return time_tValue;
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
