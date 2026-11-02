#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <string>
#include <vector>
#include "PozycjaZamowienia.h"
#include "Platnosc.h"

using namespace std;

class Zamowienie {
private:
    int idZamowienia;
    string dataZlozenia;
    string status;
    vector<PozycjaZamowienia> pozycje;
    Platnosc platnosc;

public:
    double obliczKwote();
    void aktualizujStatus(string nowyStatus);
};

#endif
