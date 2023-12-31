TEMPLATE = lib
DEFINES += LIBRERIA_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    archivos.cpp \
    cliente.cpp \
    funciones.cpp \
    gimnasio.cpp \
    libreria.cpp

HEADERS += \
    archivos.h \
    asistencia.h \
    cliente.h \
    encabezados.h \
    funciones.h \
    gimnasio.h \
    libreria_global.h \
    libreria.h \
    tipo.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
