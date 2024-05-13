#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ESTUDIANTES = 100;
const int MAX_MATERIAS = 100;

void ingresarDatos(int estudiantes, int materias, double notas[MAX_ESTUDIANTES][MAX_MATERIAS]) {
    for (int i = 0; i < estudiantes; i++) {
        cout << "Ingrese las notas del estudiante " << i + 1 << ":\n";
        for (int j = 0; j < materias; j++) {
            cout << "Materia " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }
}

void calcularPromedios(int estudiantes, int materias, double notas[MAX_ESTUDIANTES][MAX_MATERIAS], double promediosEstudiantes[], double promediosMaterias[]) {
    for (int i = 0; i < estudiantes; i++) {
        double suma = 0;
        for (int j = 0; j < materias; j++) {
            suma += notas[i][j];
        }
        promediosEstudiantes[i] = suma / materias;
    }

    for (int j = 0; j < materias; j++) {
        double suma = 0;
        for (int i = 0; i < estudiantes; i++) {
            suma += notas[i][j];
        }
        promediosMaterias[j] = suma / estudiantes;
    }
}

void ordenarPromedios(double promedios[], int cantidad, bool ascendente) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (ascendente && promedios[j] > promedios[j + 1]) {
                swap(promedios[j], promedios[j + 1]);
            } else if (!ascendente && promedios[j] < promedios[j + 1]) {
                swap(promedios[j], promedios[j + 1]);
            }
        }
    }
}

int main() {
    int estudiantes, materias;
    double notas[MAX_ESTUDIANTES][MAX_MATERIAS];
    double promediosEstudiantes[MAX_ESTUDIANTES];
    double promediosMaterias[MAX_MATERIAS];

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> estudiantes;
    cout << "Ingrese la cantidad de materias: ";
    cin >> materias;

    ingresarDatos(estudiantes, materias, notas);
    calcularPromedios(estudiantes, materias, notas, promediosEstudiantes, promediosMaterias);

    char opcion;
    cout << "¿Desea ordenar los promedios de manera ascendente (a) o descendente (d)? ";
    cin >> opcion;
    bool ascendente = (opcion == 'a');

    ordenarPromedios(promediosEstudiantes, estudiantes, ascendente);
    ordenarPromedios(promediosMaterias, materias, ascendente);

    cout << "\nPromedios por estudiante:\n";
    for (int i = 0; i < estudiantes; i++) {
        cout << "Estudiante " << i + 1 << ": " << promediosEstudiantes[i] << endl;
    }

    cout << "\nPromedios por materia:\n";
    for (int j = 0; j < materias; j++) {
        cout << "Materia " << j + 1 << ": " << promediosMaterias[j] << endl;
    }

    return 0;
}
