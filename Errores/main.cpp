#include <iostream>
using namespace std;

int main() {
    int opcion;

    do {
        cout << "\n--- SISTEMA DE ALUMNOS ---\n";
        cout << "1. Registrar alumno\n";
        cout << "2. Buscar alumno\n";
        cout << "3. Mostrar alumnos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Ingrese nombre del alumno: ";
            cin >> nombre;
            cout << "Alumno registrado: " << nombre << "\n";
        }
        else if (opcion == 4) {
            cout << "Programa finalizado.\n";
        }
        else {
            cout << "Opcion seleccionada: " << opcion << "\n";
        }
        
    } while (opcion != 4);

    return 0;
}