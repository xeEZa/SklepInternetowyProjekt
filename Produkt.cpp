#include "Produkt.h"

Produkt::Produkt()
    : idProduktu(0), nazwa(""), marka(""), kategoria(""), cena(0.0), czyDostepny(false) {}

Produkt::Produkt(int idProduktu, string nazwa, string marka, string kategoria, double cena, bool czyDostepny)
    : idProduktu(idProduktu), nazwa(nazwa), marka(marka), kategoria(kategoria), cena(cena), czyDostepny(czyDostepny) {}

int Produkt::pobierzId() const {
    return idProduktu;
}

string Produkt::pobierzNazwe() const {
    return nazwa;
}

string Produkt::pobierzMarke() const {
    return marka;
}

string Produkt::pobierzKategorie() const {
    return kategoria;
}

double Produkt::pobierzCene() const {
    return cena;
}

bool Produkt::pobierzDostepnosc() const {
    return czyDostepny;
}

void Produkt::ustawDostepnosc(bool dostepnosc) {
    czyDostepny = dostepnosc;
}
