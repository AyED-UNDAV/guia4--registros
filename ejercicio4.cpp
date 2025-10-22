#include <iostream>
#include <cstring>

using namespace std;

const int MAX_FACTURA = 5;
const int MAX_CUIT = 12;

/*

Nos pasan un módulo que devuelve una factura para su procesamiento.

El registro de tipo
Factura tiene la siguiente forma:

struct Factura {
​
char tipoFactura; // ‘A’, ‘B’ o ‘C’
char numero[MAX_FACTURA];​
char cuit[11];
float importe;

}

Factura obtenerFacturaParaProcesar();

En el caso que no haya más facturas pendientes de procesar, la Factura viene con el
número “fin”.

Para cada factura se pide informar el cuit a quien se le vendió, el importe y el tipo de
factura.

Para el total de las ventas se pide informar:
-​ el total por tipo de factura
-​ el cuit de la factura de mayor importe


*/

struct Factura
{
    char tipoFactura; // ‘A’, ‘B’ o ‘C’
    char numero[MAX_FACTURA];
    char cuit[MAX_CUIT];
    float importe;
};

Factura FACTURAS[5] = {
    {'A', "0001", "20203040814", 1265.5},
    {'C', "0002", "20203104555", 12224},
    {'B', "0222", "20203104555", 722224},
    {'C', "6532", "20445123468", 822324},
    {' ', "fin", "", -1}};
int CONTADOR = -1;

Factura obtenerFacturaParaProcesar()
{
    Factura f;
    if (CONTADOR < 4)
    {
        CONTADOR++;
        f = FACTURAS[CONTADOR];
    }
    else
    {
        f = FACTURAS[4];
    }
    return f;
}

struct Totales
{
    float tipoA;
    float tipoB;
    float tipoC;
};

void informoFactura(Factura f)
{
    cout << f.cuit << endl;
    cout << f.tipoFactura << endl;
    cout << f.importe << endl;
    cout << "************" << endl;
}

void procesarTotales(Totales &t, Factura factura)
{
    switch (factura.tipoFactura)
    {
    case 'A':
        t.tipoA += factura.importe;
        break;
    case 'B':
        t.tipoB += factura.importe;
        break;
    case 'C':
        t.tipoC += factura.importe;
        break;
    }
}

void imprimirTotales(Totales t)
{
    cout << "***** TOTALES *****" << endl;
    cout << "A: " << t.tipoA << endl;
    cout << "B: " << t.tipoB << endl;
    cout << "C: " << t.tipoC << endl;
}

int main()
{

    Totales totales;
    totales.tipoA = 0;
    totales.tipoB = 0;
    totales.tipoC = 0;

    char cuitMayorImporte[MAX_CUIT] = "";
    float mayorImporte = -1;

    Factura facturaAProcesar = obtenerFacturaParaProcesar();

    while (strcmp(facturaAProcesar.numero, "fin") != 0)
    {
        informoFactura(facturaAProcesar);

        if (facturaAProcesar.importe > mayorImporte)
        {
            mayorImporte = facturaAProcesar.importe;
            strcpy(cuitMayorImporte, facturaAProcesar.cuit);
        }

        procesarTotales(totales, facturaAProcesar);

        facturaAProcesar = obtenerFacturaParaProcesar();
    }

    imprimirTotales(totales);
    cout << "El CUIT del máximo importe es " << cuitMayorImporte;
}