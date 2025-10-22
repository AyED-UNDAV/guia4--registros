#include <iostream>

using namespace std;

const int MAX_NOMBRE = 201;
const int MAX_DNI = 11;

/*

Ejercicio 1

Tenemos que modelar un registro que tenga la siguiente información de un trabajador:

-  nombre (char[200])
-  dni (char[10])
-  tieneTituloSecundario (bool)

Con ese registro hacer una función que le pida al usuario que complete toda la información
del registro y la imprima por pantalla

*/

struct Trabajador
{
    char nombre[MAX_NOMBRE];
    char dni[MAX_DNI];
    bool tieneTituloSecundario;
};

void ingresarDatosTrabajador(Trabajador &trabajador)
{
    cout << "Ingrese nombre: ";
    cin >> trabajador.nombre;

    cout << "\n\nIngrese DNI: ";
    cin >> trabajador.dni;

    char titulo;

    cout << "\n\nTiene título secundario? (s/n) ";
    cin >> titulo;

    if (titulo == 's')
    {
        trabajador.tieneTituloSecundario = true;
    }
    else
    {
        trabajador.tieneTituloSecundario = false;
    }
}

void mostrarDatos(Trabajador trabajador)
{
    cout << "Nombre: " << trabajador.nombre << endl;
    cout << "DNI: " << trabajador.dni << endl;
    cout << "Tiene título secundario?: " << trabajador.tieneTituloSecundario << endl;
}

int main()
{
    Trabajador trabajadorEntrada;
    ingresarDatosTrabajador(trabajadorEntrada);
    mostrarDatos(trabajadorEntrada);

    return EXIT_SUCCESS;
}