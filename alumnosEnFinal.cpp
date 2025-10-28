/*
Se cuenta con la siguiente estructura que representa una clase universitaria 

struct Cursada {
  char nombreCursada[50];
  Alumno alumnosInscriptos[20];
  int cantidadAlumnosEnFinal;
  Alumno alumnosEnFinal[20];
}

Los estudiantes inscriptos en una clase y las notas correspondientes al primer y segundo parcial 
se encuentran precargadas, pero es necesario  procesar la información para completar la información de cantidadAlumnosEnFinal 
y completar la lista alumnosEnFinal con los alumnos que corresponda.
Realizar además una función que reciba solo Cursada y muestre por consola los alumnos que tienen que ir a final.

*/

#include <iostream>
using namespace std;

const int MAX_ALUMNOS = 5;

struct Alumno
{
    char nombre[50];
    int notaPrimerParcial;
    int notaSegundoParcial;
};

struct Cursada {
  char nombreCursada[50];
  Alumno alumnosInscriptos[MAX_ALUMNOS];
  int cantidadAlumnosEnFinal;
  Alumno alumnosEnFinal[MAX_ALUMNOS];
};

Cursada obtenerCursada() {
     Cursada miCursada = {
        "Programacion I",
        {
            {"Juan Perez", 8, 7},
            {"Maria Gomez", 5, 9},
            {"Carlos Lopez", 10, 10},
            {"Ana Martinez", 6, 4},
            {"Luis Rodriguez", 7, 8}
        },
        0,
        {}
    };

    return miCursada;
}

void procesarCursada(Cursada &cursada) {
    cursada.cantidadAlumnosEnFinal = 0;
    for (int i = 0; i < MAX_ALUMNOS; i++) {
        Alumno alumno = cursada.alumnosInscriptos[i];
        if (alumno.notaPrimerParcial < 6 || alumno.notaSegundoParcial < 6) {
            cursada.alumnosEnFinal[cursada.cantidadAlumnosEnFinal] = alumno;
            cursada.cantidadAlumnosEnFinal++;
        }
    }
}


void mostrarAlumnosEnFinal(const Cursada cursada) {
    cout << "Alumnos que deben rendir final en la cursada: " << cursada.nombreCursada << endl;
    for (int i = 0; i < cursada.cantidadAlumnosEnFinal; i++) {
        cout << cursada.alumnosEnFinal[i].nombre << endl;
    }
}


int main() {

    Cursada miCursada = obtenerCursada(); // Supongamos que esta función carga la cursada con datos precargados
    procesarCursada(miCursada);
    mostrarAlumnosEnFinal(miCursada);
    return 0;
}
