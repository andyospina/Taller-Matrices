#include <iostream>
#include <cstring>

using namespace std;

const int MAX_TRANSACCIONES = 10;

struct Cuenta {
    int numero;
    double saldo;
    char clave[5];
    bool bloqueada;
    int numTransacciones;
    double transacciones[MAX_TRANSACCIONES];
};

void consultarSaldo(Cuenta& cuenta) {
    cout << "Su saldo actual es: $" << cuenta.saldo << endl;
}

void depositarDinero(Cuenta& cuenta) {
    double cantidad;
    cout << "Ingrese la cantidad a depositar: $";
    cin >> cantidad;
    if (cantidad > 0) {
        cuenta.saldo += cantidad;
        cuenta.transacciones[cuenta.numTransacciones++] = cantidad;
        if (cuenta.numTransacciones >= MAX_TRANSACCIONES) {
            cuenta.numTransacciones = 0;
        }
        cout << "Depósito exitoso. Nuevo saldo: $" << cuenta.saldo << endl;
    } else {
        cout << "Cantidad inválida." << endl;
    }
}

void retirarDinero(Cuenta& cuenta) {
    double cantidad;
    cout << "Ingrese la cantidad a retirar: $";
    cin >> cantidad;
    if (cantidad > 0 && cantidad <= cuenta.saldo && cantidad <= 1000) {
        cuenta.saldo -= cantidad;
        cuenta.transacciones[cuenta.numTransacciones++] = -cantidad;
        if (cuenta.numTransacciones >= MAX_TRANSACCIONES) {
            cuenta.numTransacciones = 0;
        }
        cout << "Retiro exitoso. Nuevo saldo: $" << cuenta.saldo << endl;
    } else {
        cout << "Cantidad inválida o sin fondos suficientes." << endl;
    }
}

void transferirDinero(Cuenta& cuentaOrigen, Cuenta& cuentaDestino) {
    double cantidad;
    cout << "Ingrese la cantidad a transferir: $";
    cin >> cantidad;
    if (cantidad > 0 && cantidad <= cuentaOrigen.saldo) {
        cuentaOrigen.saldo -= cantidad;
        cuentaDestino.saldo += cantidad; // Sin comisión
        cuentaOrigen.transacciones[cuentaOrigen.numTransacciones++] = -cantidad;
        cuentaDestino.transacciones[cuentaDestino.numTransacciones++] = cantidad;
        if (cuentaOrigen.numTransacciones >= MAX_TRANSACCIONES) {
            cuentaOrigen.numTransacciones = 0;
        }
        if (cuentaDestino.numTransacciones >= MAX_TRANSACCIONES) {
            cuentaDestino.numTransacciones = 0;
        }
        cout << "Transferencia exitosa. Nuevo saldo: $" << cuentaOrigen.saldo << endl;
    } else {
        cout << "Cantidad inválida o sin fondos suficientes." << endl;
    }
}

void historialTransacciones(Cuenta& cuenta) {
    cout << "Historial de transacciones:\n";
    for (int i = 0; i < cuenta.numTransacciones; i++) {
        cout << "Transacción " << i + 1 << ": $" << cuenta.transacciones[i] << endl;
    }
}

void cambiarClave(Cuenta& cuenta) {
    char nuevaClave[5];
    cout << "Ingrese la nueva clave (4 dígitos): ";
    cin >> nuevaClave;
    if (strlen(nuevaClave) == 4) {//determinar la longitud de una cadena de caracteres.
        strcpy(cuenta.clave, nuevaClave);//se utiliza para copiar una cadena de caracteres a otra.
        cout << "Clave cambiada exitosamente." << endl;
    } else {
        cout << "Clave inválida. Debe tener 4 dígitos." << endl;
    }
}

void bloquearTarjeta(Cuenta& cuenta) {
    cuenta.bloqueada = true;
    cout << "Tarjeta bloqueada exitosamente." << endl;
}

int main() {
    Cuenta cuenta1 = {1234, 5000.0, "1234", false, 0, {}};
    Cuenta cuenta2 = {5678, 10000.0, "5678", false, 0, {}};

    int opcion;
    do {
        cout << "\nMenú:\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Depositar dinero\n";
        cout << "3. Retirar dinero\n";
        cout << "4. Transferir dinero\n";
        cout << "5. Historial de transacciones\n";
        cout << "6. Cambiar clave\n";
        cout << "7. Bloquear tarjeta\n";
        cout << "8. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                consultarSaldo(cuenta1);
                break;
            case 2:
                depositarDinero(cuenta1);
                break;
            case 3:
                retirarDinero(cuenta1);
                break;
            case 4:
                transferirDinero(cuenta1, cuenta2);
                break;
            case 5:
                historialTransacciones(cuenta1);
                break;
            case 6:
                cambiarClave(cuenta1);
                break;
            case 7:
                bloquearTarjeta(cuenta1);
                break;
            case 8:
                cout << "Saliendo del cajero automático..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 8);

    return 0;
}

