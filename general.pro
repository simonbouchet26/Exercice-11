TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    Bloc.cpp \
    quitourne.cc \
    Systeme.cpp \
    Vecteur3D.cpp \
    Particule.cpp \
    Enceinte.cpp \
    GenerateurAleatoire.cpp \
    contenu.cc

HEADERS += \
    Bloc.h \
    Machin.h \
    quitourne.h \
    dessinable.h \
    support_a_dessin.h \
    Machin.h \
    Systeme.h \
    Vecteur3D.h \
    Particule.h \
    Enceinte.h \
    GenerateurAleatoire.h \
    contenu.h
