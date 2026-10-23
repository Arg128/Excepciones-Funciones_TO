#include <format>
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;
class Fecha {
public:
  // Fecha(time_t time) {
  //   this->dia = time.day;
  //   this->mes = time.month;
  //   this->anio = time.year;
  // }

  Fecha(string dia, string mes, string anio) : dia(dia), mes(mes), anio(anio) {}

  void operator<<(char *arg) {
    return format("DATE : {0} // {1} // {2}", this->dia, this->mes, this->anio);
  }

private:
  string dia;
  string mes;
  string anio;
}

int main (int argc, char *argv[]) {

  return 0;
}
