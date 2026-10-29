#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline double calcularDescuento(double precio, double porcentaje) {
    return precio - (precio * porcentaje / 100.0);
}

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    void mostrarDatos() const {
        cout << *this << endl;
    }

    double obtenerPrecio() const {
        return precio;
    }

    Producto operator+(const Producto &otro) const {
        return Producto(nombre + " + " + otro.nombre,
                        precio + otro.precio,
                        cantidad + otro.cantidad);
    }

    friend void compararPrecios(const Producto &a, const Producto &b) {
        if (a.precio > b.precio) {
            cout << a.nombre << " tiene el mayor precio." << endl;
        } else if (b.precio > a.precio) {
            cout << b.nombre << " tiene el mayor precio." << endl;
        } else {
            cout << a.nombre << " y " << b.nombre
                 << " tienen el mismo precio." << endl;
        }
    }

    friend ostream &operator<<(ostream &salida, const Producto &producto) {
        salida << "Producto: " << producto.nombre
               << " | Precio: S/ " << fixed << setprecision(2) << producto.precio
               << " | Cantidad: " << producto.cantidad;
        return salida;
    }
};

int main() {
    vector<Producto> productos = {
        Producto("Laptop", 3500.00, 5),
        Producto("Mouse", 80.00, 20),
        Producto("Teclado", 150.00, 15),
        Producto("Monitor", 900.00, 8)
    };

    cout << "=== SISTEMA DE PRODUCTOS ===" << endl;
    cout << "\nLista de productos:" << endl;
    for (const Producto &producto : productos) {
        producto.mostrarDatos();
    }

    cout << "\nDescuento del 10% en la Laptop: S/ "
         << fixed << setprecision(2)
         << calcularDescuento(productos[0].obtenerPrecio(), 10.0) << endl;

    cout << "\nComparacion de precios:" << endl;
    compararPrecios(productos[0], productos[3]);

    const double precioMinimo = 500.0;
    vector<Producto> productosFiltrados;
    auto precioSuperiorA = [precioMinimo](const Producto &producto) {
        return producto.obtenerPrecio() > precioMinimo;
    };

    copy_if(productos.begin(), productos.end(),
            back_inserter(productosFiltrados), precioSuperiorA);

    cout << "\nProductos con precio mayor a S/ " << precioMinimo << ":" << endl;
    for (const Producto &producto : productosFiltrados) {
        cout << producto << endl;
    }

    Producto productoCombinado = productos[1] + productos[2];
    cout << "\nProductos combinados con el operador +:" << endl;
    cout << productoCombinado << endl;

    return 0;
}
