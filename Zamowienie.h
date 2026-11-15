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
    Zamowienie();
    Zamowienie(int idZamowienia, string dataZlozenia, vector<PozycjaZamowienia> pozycje, Platnosc platnosc, string status = "Nowe");

    double obliczKwote();
    void aktualizujStatus(string nowyStatus);

    int pobierzId() const;
    string pobierzDateZlozenia() const;
    string pobierzStatus() const;
    vector<PozycjaZamowienia> pobierzPozycje() const;
    Platnosc& pobierzPlatnosc();

    void ustawId(int id);
    void ustawDateZlozenia(string data);
    void dodajPozycje(PozycjaZamowienia pozycja);
    void ustawPlatnosc(Platnosc nowaPlatnosc);
};

#endif
