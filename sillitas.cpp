#include <iostream>

using namespace std;

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

bool esFilaMinimo(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, int fila, int columna) {
    for (int j = 0; j < columnas; j++) {
        if (matriz[fila][j] < matriz[fila][columna]) {
            return false;
        }
    }
    return true;
}

bool esColumnaMaximo(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, int fila, int columna) {
    for (int i = 0; i < filas; i++) {
        if (matriz[i][columna] > matriz[fila][columna]) {
            return false;
        }
    }
    return true;
}

void encontrarPuntosSilla(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    cout << "Puntos de silla encontrados:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (esFilaMinimo(matriz, filas, columnas, i, j) && esColumnaMaximo(matriz, filas, columnas, i, j)) {
                cout << "(" << i << ", " << j << ") = " << matriz[i][j] << endl;
            }
        }
    }
}

int main() {
    int filas, columnas;
    int matriz[MAX_FILAS][MAX_COLUMNAS];

    cout << "Ingrese el número de filas y columnas de la matriz: ";
    cin >> filas >> columnas;

    cout << "Ingrese los elementos de la matriz (separados por espacios):\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
        }
    }

    encontrarPuntosSilla(matriz, filas, columnas);

    return 0;
}
