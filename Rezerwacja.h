#ifndef REZERWACJA_H
#define REZERWACJA_H

#include <string>
#include "Produkt.h"

using namespace std;

class Rezerwacja {
private:
    int idRezerwacji;
    string dataUtworzenia;
    string czasWygasniecia24h;
    double oplataRezerwacyjna;
    Produkt produkt;

public:
    Rezerwacja();
    Rezerwacja(int idRezerwacji, string dataUtworzenia, string czasWygasniecia24h, double oplataRezerwacyjna, Produkt produkt);

    int pobierzId() const;
    string pobierzDateUtworzenia() const;
    string pobierzCzasWygasniecia() const;
    double pobierzOplateRezerwacyjna() const;
    Produkt pobierzProdukt() const;
    
};

#endif
