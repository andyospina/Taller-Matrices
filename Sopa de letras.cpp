#include <iostream>
#include <cstring>

using namespace std;

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;
const int DIRECCIONES[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool buscarPalabra(char tablero[MAX_FILAS][MAX_COLUMNAS], const char* palabra, int filas, int columnas, int fila, int columna, int dx, int dy, int indice) {
    if (palabra[indice] == '\0') {
        return true; // Se encontró la palabra completa
    }

    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        return false; 
    }

    if (toupper(tablero[fila][columna]) != toupper(palabra[indice])) {
        return false; 
    }

    return buscarPalabra(tablero, palabra, filas, columnas, fila + dx, columna + dy, dx, dy, indice + 1);
}

int main() {
    int filas, columnas;
    char tablero[MAX_FILAS][MAX_COLUMNAS];
    char palabra[100];

    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

    cout << "Ingrese los caracteres del tablero (letras separadas por espacios):\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> tablero[i][j];
        }
    }

    cout << "Ingrese la palabra a buscar: ";
    cin >> palabra;

    bool encontrada = false;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            for (int k = 0; k < 8; k++) {
                int dx = DIRECCIONES[k][0];
                int dy = DIRECCIONES[k][1];
                if (buscarPalabra(tablero, palabra, filas, columnas, i, j, dx, dy, 0)) {
                    cout << "La palabra '" << palabra << "' se encuentra en la posición (" << i << ", " << j << ") en dirección (" << dx << ", " << dy << ")" << endl;
                    encontrada = true;
                }
            }
        }
    }

    if (!encontrada) {
        cout << "La palabra '" << palabra << "' no se encuentra en el tablero." << endl;
    }

    return 0;
}
