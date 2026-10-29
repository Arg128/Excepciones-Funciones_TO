#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int opcion;
    string nombre;

    do {
        cout << "\n--- SISTEMA DE ALUMNOS ---\n";
        cout << "1. Registrar alumno\n";
        cout << "2. Buscar alumno\n";
        cout << "3. Mostrar alumnos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            ofstream archivo("alumnos.txt", ios::app);

            cout << "Ingrese nombre del alumno: ";
            cin >> nombre;

            archivo << nombre << "\n";
            archivo.close();

            cout << "Alumno guardado correctamente.\n";
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