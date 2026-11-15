#include "Rezerwacja.h"

Rezerwacja::Rezerwacja()
    : idRezerwacji(0), dataUtworzenia(""), czasWygasniecia24h(""), oplataRezerwacyjna(0.0), produkt() {}

Rezerwacja::Rezerwacja(int idRezerwacji, string dataUtworzenia, string czasWygasniecia24h, double oplataRezerwacyjna, Produkt produkt)
    : idRezerwacji(idRezerwacji), dataUtworzenia(dataUtworzenia), czasWygasniecia24h(czasWygasniecia24h), oplataRezerwacyjna(oplataRezerwacyjna), produkt(produkt) {
    this->produkt.ustawDostepnosc(false);
}

int Rezerwacja::pobierzId() const {
    return idRezerwacji;
}

string Rezerwacja::pobierzDateUtworzenia() const {
    return dataUtworzenia;
}

string Rezerwacja::pobierzCzasWygasniecia() const {
    return czasWygasniecia24h;
}

double Rezerwacja::pobierzOplateRezerwacyjna() const {
    return oplataRezerwacyjna;
}

Produkt Rezerwacja::pobierzProdukt() const {
    return produkt;
}
