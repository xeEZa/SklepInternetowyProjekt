#include "PozycjaZamowienia.h"
#include <iostream>

PozycjaZamowienia::PozycjaZamowienia()
    : produkt(), ilosc(0), cenaJednostkowa(0.0) {}

PozycjaZamowienia::PozycjaZamowienia(Produkt produkt, int ilosc, double cenaJednostkowa)
    : produkt(produkt), ilosc(ilosc), cenaJednostkowa(cenaJednostkowa) {}

Produkt PozycjaZamowienia::pobierzProdukt() const {
    return produkt;
}

double PozycjaZamowienia::pobierzCene() const {
    return cenaJednostkowa;
}

int PozycjaZamowienia::pobierzIlosc() const {
    return ilosc;
}

void PozycjaZamowienia::zwiekszIlosc(int dodatkowaIlosc) {
    if (dodatkowaIlosc > 0) {
        ilosc += dodatkowaIlosc;
    }
    
}
