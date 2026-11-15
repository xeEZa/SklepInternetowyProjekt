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
    Platnosc();
    Platnosc(int idPlatnosci, string metodaPlatnosci, double kwota, bool czyOplacone = false);

    bool zrealizujPlatnosc();
    double pobierzKwote() const;
    bool CzyOplacone() const;
    int pobierzIdPlatnosci() const;
    string pobierzMetodePlatnosci() const;
    void ustawMetodePlatnosci(string metoda);
    void ustawKwote(double nowaKwota);
};

#endif
