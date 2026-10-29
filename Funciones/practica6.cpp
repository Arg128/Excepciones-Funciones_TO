#include <cstddef>
#include <cstdio>
#include <format>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>

using namespace std;
class Fecha {
public:
  Fecha(time_t time) {
    struct tm *tm_info = localtime(&time);
    Fecha(time_t time) {
        struct tm *tm_info = localtime(&time);

    this->dia = tm_info->tm_wday;
    this->mes = tm_info->tm_mon;
    this->anio = tm_info->tm_year;
  }
        this->dia = tm_info->tm_wday;
        this->mes = tm_info->tm_mon;
        this->anio = tm_info->tm_year;
    }

<<<<<<< HEAD
  Fecha(size_t dia, size_t mes, size_t anio) : dia(dia), mes(mes), anio(anio) {
    validar();
  }
=======
    Fecha(size_t dia, size_t mes, size_t anio) : dia(dia), mes(mes), anio(anio) {}
>>>>>>> b24a65372a6cd559e1c727f2dfa41b40f8b31f64

  friend ostream &operator<<(ostream &os, const Fecha &obj) {
    friend ostream &operator<<(ostream &os, const Fecha &obj) {

    os << obj.dia << "/" << obj.mes << "/" << obj.anio;
        os << obj.dia << "/" << obj.mes << "/" << obj.anio;

    return os;
  }
        return os;
    }

private:
<<<<<<< HEAD
  static bool esBisiesto(size_t a) {
    return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
  }

  static size_t diasEnMes(size_t m, size_t a) {
    static const size_t d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2 && esBisiesto(a)) ? 29 : d[m - 1];
  }

  void validar() const {
    if (mes < 1 || mes > 12)
      throw std::invalid_argument("mes invalido: " + std::to_string(mes));
    if (dia < 1 || dia > diasEnMes(mes, anio))
      throw std::invalid_argument("dia invalido: " + std::to_string(dia));
  }
  size_t dia;
  size_t mes;
  size_t anio;
};

int main(int argc, char *argv[]) {
  Fecha *primero = new Fecha(10, 13, 10);
  cout << "Fecha de : " << *primero << endl;
  return 0;
=======
    size_t dia;
    size_t mes;
    size_t anio;
};

int main(int argc, char *argv[]) {
    Fecha *primero = new Fecha(10, 10, 10);
    cout << "Fecha de : " << *primero << endl;
    return 0;
>>>>>>> b24a65372a6cd559e1c727f2dfa41b40f8b31f64
}
