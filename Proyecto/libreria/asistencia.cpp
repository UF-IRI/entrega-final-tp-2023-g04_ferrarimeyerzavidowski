#include "asistencia.h"


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


