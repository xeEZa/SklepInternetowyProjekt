#include "Klient.h"

Klient::Klient() : Uzytkownik(), adresDostawy("") {}

Klient::Klient(int id, string imie, string nazwisko, string email, string adresDostawy)
    : Uzytkownik(id, imie, nazwisko, email), adresDostawy(adresDostawy) {}


Koszyk& Klient::pobierzKoszyk() {
    return koszyk;  
}

string Klient::pobierzAdresDostawy() const {
    return adresDostawy;
}