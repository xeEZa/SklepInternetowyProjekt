#ifndef PLATNOSC_H
#define PLATNOSC_H

#include <string>

using namespace std;

class Platnosc {
private:
    int idPlatnosci;
    string metodaPlatnosci;
    double kwota;
    bool czyOplacone;

public:
    bool zrealizujPlatnosc();
};

#endif
