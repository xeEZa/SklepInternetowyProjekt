#ifndef KOSZYK_H
#define KOSZYK_H

#include <vector>
#include "Produkt.h"

using namespace std;

class Koszyk {
private:
    vector<Produkt> produktyWKoszyku;
    double wartoscKoszyka;

public:
    void dodajDoKoszyka(Produkt p);
    void usunZKoszyka(Produkt p);
    void wyczyscKoszyk();
};

#endif
