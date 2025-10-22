#include <iostream>
#include <cstring>

using namespace std;

const int CANT_GRADUADOS = 3;

/*

Dado un arreglo de N graduados y teniendo en cuenta que el registro de tipo Graduado
tiene la siguiente forma:

struct Graduado {
  int legajo;
  char nombre[50];
  bool diplomaDeHonor;
}

Se pide:

a)  realizar una función que reciba un legajo y devuelva la posición del elemento en el
arreglo.  Si  no  encuentra  al  estudiante  por  su  legajo  debe  retornar  un  mensaje
indicando que no lo encontró.
b)  se necesita un arreglo con estudiantes que recibirán diploma de honor, pensar la
mejor manera de hacerlo.

*/

struct Graduado
{
    int legajo;
    char nombre[50];
    bool diplomaDeHonor;
};

int buscarGraduado(Graduado graduados[], int legajoBuscado)
{
    bool encontrado = false;
    int posicionEncontrado = -1;

    for (int pos = 0; pos < CANT_GRADUADOS && encontrado == false; pos++)
    {
        if (graduados[pos].legajo == legajoBuscado)
        {
            encontrado = true;
            posicionEncontrado = pos;
        }
    }

    if (encontrado == false)
    {
        cout << "Legajo no encontrado " << legajoBuscado;
    }

    return posicionEncontrado;
}

int main()
{

    Graduado graduados[CANT_GRADUADOS] = {{1, "Pepito", true}, {2, "Fulanito", false}, {3, "Menganito", true}};

    // si busco el legajo 2, deberíá devolver la posición 1
    cout << buscarGraduado(graduados, 2) << endl;

    // si busco el legajo 792, deberíá devolver la -1 y mostrar un mensaje acorde
    cout << buscarGraduado(graduados, 792);
}