#include <cstddef>
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

        this->dia = tm_info->tm_wday;
        this->mes = tm_info->tm_mon;
        this->anio = tm_info->tm_year;
    }

    Fecha(size_t dia, size_t mes, size_t anio) : dia(dia), mes(mes), anio(anio) {}

    friend ostream &operator<<(ostream &os, const Fecha &obj) {

        os << obj.dia << "/" << obj.mes << "/" << obj.anio;

        return os;
    }

private:
    size_t dia;
    size_t mes;
    size_t anio;
};

int main(int argc, char *argv[]) {
    Fecha *primero = new Fecha(10, 10, 10);
    cout << "Fecha de : " << *primero << endl;
    return 0;
}
