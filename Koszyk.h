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
    Koszyk();
    ~Koszyk();
    double pobierzWartoscKoszyka() const;
    vector<Produkt> pobierzProduktyWKoszyku() const;
    void dodajDoKoszyka(const Produkt& p);
    void usunZKoszyka(const Produkt& p);
    void wyczyscKoszyk();
};

#endif
