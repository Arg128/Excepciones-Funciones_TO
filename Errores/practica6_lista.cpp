#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> lista = {"Manzana", "Pera", "Uva", "Fresa", "Mango"};
    cout << "Lista de 5 elementos (indices 0 a 4):" << endl;

    for (size_t i = 0; i < lista.size(); ++i)
        cout << "  [" << i << "] " << lista[i] << endl;
    int indice;

    cout << "Ingrese un indice (0-4): ";
    cin >> indice;

    try {
        cout << "Elemento: " << lista.at(indice) << endl;
    } catch (const out_of_range &) {
        cout << "Error: el indice " << indice << " no existe en la lista." << endl;
    }
    return 0;
}
