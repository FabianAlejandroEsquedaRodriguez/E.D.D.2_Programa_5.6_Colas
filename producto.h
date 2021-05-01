#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "cola.h"

#include <iostream>
#include <string.h>
using namespace std;

/* Aplicación de una estructura de datos tipo cola. Se define la clase
Producto y una cola de objetos tipo Producto. Considerando que se
quieren vender los productos de acuerdo al orden en el que fueron
comprados, se usó una cola para almacenarlos. La cola se actualiza a
medida que se compran o se venden productos. */

/* Definición de la clase Producto. */
class Producto{
public:
    Producto();
    Producto(int, char[], double);
    double RegresaPrecio();
    friend istream &operator>>(istream &, Producto &);//Sobrecarga del operador de insercion
    friend ostream &operator<<(ostream &, Producto &);//Sobrecarga del operador de extraccion
    
private:
    int Clave;
    char NomProd[10];
    double Precio;
};

/* Declaración del método constructor por omisión. */
Producto::Producto(){

}
/* Declaración del método constructor con parámetros. */
Producto::Producto(int Cla, char NomP[], double Pre){
    Clave= Cla;
    strcpy(NomProd, NomP);
    Precio= Pre;
}

/* Método que permite, a usuarios externos a la clase, conocer el valor
del atributo privado Precio. */
double Producto::RegresaPrecio(){
    return Precio;
}

/* Sobrecarga del operador >>. De esta forma se permite leer objetos de
tipo Producto de manera directa . */
istream &operator>>(istream &Lee, Producto &ObjProd)
{
    cout<<"\n\nIngrese clave del producto: ";
    Lee>>ObjProd.Clave; 
    
    cout<<"\nIngrese nombre del producto: ";
    Lee>>ObjProd.NomProd; 
    
    cout<<"\nIngrese precio: ";
    Lee>>ObjProd.Precio;

    return Lee;
}

/* Sobrecarga del operador <<. De esta forma se permite imprimir objetos
de tipo Producto de manera directa . */
ostream &operator<< (ostream &Escribe, Producto &ObjProd)
{
    Escribe<<"\n\nDatos del producto\n";
    Escribe<<"\nClave: "<<ObjProd.Clave;
    Escribe<<"\nNombre: "<<ObjProd.NomProd;
    Escribe<<"\nPrecio: "<<ObjProd.Precio;

    return Escribe;
}


#endif //PRODUCTO_H