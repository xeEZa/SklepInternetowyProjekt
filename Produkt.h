#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

using namespace std;

class Produkt {
private:
    int idProduktu;
    string nazwa;
    string marka;
    string kategoria;
    double cena;
    bool czyDostepny;

public:
    Produkt();
    Produkt(int idProduktu, string nazwa, string marka, string kategoria, double cena, bool czyDostepny = true);

    int pobierzId() const;
    string pobierzNazwe() const;
    string pobierzMarke() const;
    string pobierzKategorie() const;
    double pobierzCene() const;
    bool pobierzDostepnosc() const;

    void ustawDostepnosc(bool dostepnosc);
    
};

#endif
