#include "producto.h"
#include <fstream>

//Prototipo
int Menu();

/* Función principal que lleva a cabo la aplicación descrita. Se crea
una cola de objetos tipo Producto y la misma se va modificando a medida
que se compran o se venden productos. El uso de una cola para guardar
los productos facilita el cumplimiento de la condición impuesta para su
venta: el primero que se compre será el primero que se venda. Al final
de las transacciones se imprime el total de dinero recaudado con las
ventas. */
int main(){
    system("color F1");

    Cola<Producto> Deposito;//Deposito de Productos (Cola de productos)
    Producto Prod;
    int Opc;
    double Total= 0;

    Opc= Menu();

    while (Opc == 1 || Opc == 2){
        switch (Opc){
            case 1: cout<<"\t\t\tREGISTRAR PRODUCTO"<<endl;
                cin>>Prod; 
                if (!(Deposito + Prod)){//Si ya no se agrega el producto a la pila
                    cout<<"\n\nNo hay lugar en el deposito para registrar el producto.\n";
                }

                cout<<endl<<endl;
                system("pause"); system("cls");
                break;
        
            case 2: 
                if(Deposito - &Prod){//Si se pueden ir sacando los elementos de la cola
                    cout<<Prod;
                    Total = Total + Prod.RegresaPrecio();
                }
                else{
                    cout<<"\n\n\nYa no hay productos en el deposito.\n\n";
                }
                
            cout<<endl<<endl;
            system("pause"); system("cls");
            break;
        }
        Opc= Menu();
    }
    cout<<"\t\t\tVENTAS";
    cout<<"\n\n\nTotal vendido: "<<Total<<endl<<endl<<endl;

    return 0;
}

/* Función auxiliar que despliega al usuario las opciones de trabajo. En
este caso registrar la compra o la venta de un producto. */
int Menu(){
int Resp;
    do{
        cout<<"\t\t\tMENU DE OPCIONES";
        cout<<"\n\nIngrese operacion a registrar: ";
        cout<<"\n\n1. Compra de un producto ";
        cout<<"\n2. Venta de un producto ";
        cout<<"\n3. Termina el registro\n\n";

        cout<<"Digita una opcion: ";
        cin>>Resp;

        system("cls");

    }while(Resp != 1 && Resp != 2 && Resp != 3);

return Resp;
}