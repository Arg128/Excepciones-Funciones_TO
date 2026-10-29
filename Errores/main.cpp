#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int opcion;
    string nombre, buscado;

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
        else if (opcion == 2) {
            ifstream archivo("alumnos.txt");
            string linea;
            bool encontrado = false;

            cout << "Ingrese nombre a buscar: ";
            cin >> buscado;

            while (getline(archivo, linea)) {
                if (linea == buscado) {
                    encontrado = true;
                    break;
                }
            }

            if (encontrado) {
                cout << "Alumno encontrado.\n";
            } else {
                cout << "Alumno no encontrado.\n";
            }

            archivo.close();
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