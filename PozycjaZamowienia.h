#ifndef POZYCJAZAMOWIENIA_H
#define POZYCJAZAMOWIENIA_H

#include "Produkt.h"

using namespace std;

class PozycjaZamowienia {
private:
    Produkt produkt;
    int ilosc;
    double cenaJednostkowa;

public:
    PozycjaZamowienia();
    PozycjaZamowienia(Produkt produkt, int ilosc, double cenaJednostkowa);

    Produkt pobierzProdukt() const; 
    double pobierzCene() const;
    int pobierzIlosc() const;
    void zwiekszIlosc(int dodatkowaIlosc);
};

#endif

