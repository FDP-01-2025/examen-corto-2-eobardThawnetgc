//Código realizado por Juan Manuel Flores Crisóstomo - 00135025

#include <iostream>

using namespace std;

//función para realizar la compra
void purchaseProduct(string productName, int productPrice, int userType) {
    int availableCash = 1000, finalPrice;

    //aplicación del 20% a estudiante y 10% a profesionales
    if (userType == 1) finalPrice = productPrice - (productPrice * 20 / 100);
    else finalPrice = productPrice - (productPrice * 10 / 100);

    //saldo insuficiente
    if (availableCash < productPrice) {
        cout << "\nError al realizar la compra, el saldo en su cuenta es insuficiente";
        cout << "\n Su saldo: $" << availableCash;
        cout << "\n Para obtener el producto: " << productName << " necesita: $";
        cout << productPrice - availableCash << " (precio original)";
        cout << " " << finalPrice - availableCash << " (precio con descuento aplicado)"; 
    }
    //saldo suficiente 
    else {
        cout << "La transaccion fue realizada exitosamente, ¡gracias por su compra!";
        cout << "\n\n El producto adquirido es: " << productName << " (" << finalPrice << ")";
        cout << "\n Su saldo actual es: $" << availableCash - finalPrice;
    }
}

int main() {
    int age, userType, productOption;
    //precios productos
    int basicLaptop = 900, studentsTablet = 600, chromebook = 700, advancedLaptop = 1500, proTablet = 1200, workStation = 2000;

    cout << "Bienvenido, ingrese su edad: ";
    cin >> age;

    //validar edad
    if (age < 16) {
        cout << "\n Lo sentimos, para realizar una compra debe tener una edad mayor de 16";
        return 1;
    }

    cout << "Seleccione una categoria de cliente: ";
    cout << "\n 1- Estudiante \n 2- Profesional \n 3- Ver todos los productos \n";
    cin >> userType;

    //evaluación de categoría de cliente
    switch(userType) {
        //estudiante
        case 1:
            cout << "\n 1- Laptop basica: $900 \n 2- Tablet Estudiantil: $600 \n 3- Chromebook: $700";
            cout << "\n\n Por favor seleccione un producto (cuenta con un descuento del 20%): ";
            cin >> productOption;

            switch(productOption) {
                case 1: 
                    purchaseProduct("Laptop basica", basicLaptop, userType);
                break;

                case 2: 
                    purchaseProduct("Tablet estudiantil", studentsTablet, userType);
                break;

                case 3: 
                    purchaseProduct("Chromebook", chromebook, userType);
                break;

                default: 
                    cout << "\n La opcion ingresada no es valida";
                break;
            }
        break;
        //profesional
        case 2:
            cout << "\n 1- Laptop Avanzada: $1500 \n 2-Tablet Pro: $1200 \n 3- Estacion de Trabajo: $2000";
            cout << "\n\n Por favor seleccione un producto (cuenta con un descuento del 10%): ";
            cin >> productOption;

            switch(productOption) {
                case 1: 
                    purchaseProduct("Laptop avanzada", advancedLaptop, userType);
                break;

                case 2: 
                    purchaseProduct("Tablet pro", proTablet, userType);
                break;

                case 3: 
                    purchaseProduct("Estacion de trabajo", workStation, userType);
                break;

                default: 
                    cout << "\n La opcion ingresada no es valida";
                break;
            }
        break;
        //ver todos los productos
        case 3:
            cout << "\n Laptop basica: $900 \n Estudiantil: $600 \n Chromebook: $700";
            cout << "\n Laptop Avanzada: $1500 \n Tablet Pro: $1200 \n Estacion de Trabajo: $2000";
            cout << "\n\n Para realizar una compra debe ingresar una categoria de cliente";
        break;
        //ninguno de los casos
        default:
            cout << "El numero ingresado no es valido ";
        break;
    }

    return 0;
}