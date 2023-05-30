#include <iostream>
#include <cmath>

using namespace std;
class Star {
public:
    std::string orderByBrightness; // kolejność względem jasności gwiazdy
    std::string starName; // nazwa gwiazdy
    const double declination; // deklinacja
    const std::string rectascension; // rektascensja
    double osm; // obserwowalna wielkość gwiazdowa (observable star magnitude)
    double distance; // odległość
    std::string constellation; // gwiazdobiór
    std::string hemisphere; // półkula
    double temperature; // temperatura
    double mass; // masa
    const double asm; // absolutna wielkość gwiazdowa (absolute star magnitude)

    Star(std::string nazwa_gwiazdy, double deklinacja, std::string rektascensja, double obserwowalna_wielkosc_gwiazdowa,
         double odleglosc, std::string gwiazdoZbior, double temperatura, double masa)
            : starName(nazwa_gwiazdy),
              declination(deklinacja),
              rectascension(rektascensja),
              osm(std::max(obserwowalna_wielkosc_gwiazdowa, -27.4)),
              distance(odleglosc),
              constellation(gwiazdoZbior),
              hemisphere(deklinacja > 0 ? "NORTH" : "SOUTH"),
              temperature(temperatura > 2000 ? temperatura : 2000),
              mass(masa),
              asm(osm - 5 * log10(distance) + 5) {
    }

    std::string toString() { // metoda do wypisywania danych gwiazdy
        return std::to_string(orderByBrightness) + ". " + starName + " " + std::to_string(declination) + " " +
               rectascension + " " + std::to_string(osm) + " " + std::to_string(distance) + " " + constellation + " " +
               hemisphere + " " + std::to_string(temperature) + " " + std::to_string(mass) + " " + std::to_string(asm);
    }

    int compareTo(const Star& o) { // metoda do porównywania obserwowalnej wielkości gwiazdowej (osm)
        return std::signbit(o.osm - osm) ? -1 : 1;
    }
};

int main() {
    // Przykładowe użycie klasy Star
    Star star("NazwaGwiazdy", 10.5, "Rektascensja", 5.5, 100.0, "Gwiazdozbiór", 3000.0, 2.0);
    std::cout << star.toString() << std::endl;

    return 0;
}

#include "Star.h"
