#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <stdexcept>
using namespace std;

class AlumnoNoEncontradoException : public exception {
public:
    const char* what() const noexcept override {
        return "No se encontro al alumno.";
    }
};

int main() {
    int opcion;
    int codigo;
    string nombre;

    do {
        cout << "\n--- SISTEMA DE REGISTRO DE ALUMNOS ---\n";
        cout << "1. Registrar alumno\n";
        cout << "2. Buscar alumno\n";
        cout << "3. Mostrar archivo de alumnos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Error: debe ingresar un numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            if (opcion == 1) {
                cout << "Ingrese codigo del alumno: ";

                if (!(cin >> codigo)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("El codigo debe ser un numero.");
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Ingrese nombre del alumno: ";
                getline(cin, nombre);

                if (nombre.empty()) {
                    throw invalid_argument("El nombre no puede estar vacio.");
                }

                ofstream archivo("alumnos.txt", ios::app);

                if (!archivo.is_open()) {
                    throw runtime_error("No se pudo abrir el archivo.");
                }

                archivo << codigo << ";" << nombre << "\n";
                archivo.close();

                cout << "Alumno registrado correctamente.\n";
            }
            else if (opcion == 2) {
                cout << "Ingrese codigo a buscar: ";

                if (!(cin >> codigo)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("El codigo debe ser un numero.");
                }

                ifstream archivo("alumnos.txt");

                if (!archivo.is_open()) {
                    throw runtime_error("Archivo no encontrado o no se pudo abrir.");
                }

                string linea;
                bool encontrado = false;

                while (getline(archivo, linea)) {
                    size_t separador = linea.find(';');

                    if (separador == string::npos) {
                        throw runtime_error("El archivo esta corrupto.");
                    }

                    if (stoi(linea.substr(0, separador)) == codigo) {
                        cout << "Alumno encontrado: "
                             << linea.substr(separador + 1) << "\n";
                        encontrado = true;
                        break;
                    }
                }

                archivo.close();

                if (!encontrado) {
                    throw AlumnoNoEncontradoException();
                }
            }
            else if (opcion == 3) {
                ifstream archivo("alumnos.txt");

                if (!archivo.is_open()) {
                    throw runtime_error("Archivo no encontrado o no se pudo abrir.");
                }

                string linea;
                cout << "\n--- LISTA DE ALUMNOS ---\n";

                while (getline(archivo, linea)) {
                    cout << linea << "\n";
                }

                archivo.close();
            }
            else if (opcion != 4) {
                cout << "Opcion no valida.\n";
            }
        }
        catch (const AlumnoNoEncontradoException& e) {
            cout << "Error: " << e.what() << "\n";
        }
        catch (const invalid_argument& e) {
            cout << "Error de entrada: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const exception& e) {
            cout << "Error del sistema: " << e.what() << "\n";
        }

    } while (opcion != 4);

    cout << "Programa finalizado.\n";
    return 0;
}
