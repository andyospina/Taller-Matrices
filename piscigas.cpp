#include <iostream>

using namespace std;

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

struct Coordenada {
    int fila;
    int columna;
};

Coordenada siguienteMovimiento(int piscina[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, Coordenada actual) {
    int profundidad_actual = piscina[actual.fila][actual.columna];
    Coordenada siguiente = actual;
    int max_profundidad = profundidad_actual;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; 
            int nueva_fila = actual.fila + i;
            int nueva_columna = actual.columna + j;

            if (nueva_fila >= 0 && nueva_fila < filas && nueva_columna >= 0 && nueva_columna < columnas) {
                int profundidad_nueva = piscina[nueva_fila][nueva_columna];
                if (profundidad_nueva > max_profundidad) {
                    max_profundidad = profundidad_nueva;
                    siguiente.fila = nueva_fila;
                    siguiente.columna = nueva_columna;
                }
            }
        }
    }

    return siguiente;
}

int main() {
    int filas, columnas;
    int piscina[MAX_FILAS][MAX_COLUMNAS];
    Coordenada inicio;

    cout << "Ingrese el número de filas y columnas de la piscina: ";
    cin >> filas >> columnas;

    cout << "Ingrese la configuración de la piscina (profundidades separadas por espacios):\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> piscina[i][j];
        }
    }

    cout << "Ingrese la posición inicial de la pelota (fila y columna): ";
    cin >> inicio.fila >> inicio.columna;

    Coordenada actual = inicio;
    cout << "Ruta seguida por la pelota:\n";
    while (true) {
        cout << "(" << actual.fila << ", " << actual.columna << ")\n";
        Coordenada siguiente = siguienteMovimiento(piscina, filas, columnas, actual);
        if (siguiente.fila == actual.fila && siguiente.columna == actual.columna) {
            break; 
        }
        actual = siguiente;
    }

    cout << "Posición final de la pelota: (" << actual.fila << ", " << actual.columna << ")\n";

    return 0;
}
