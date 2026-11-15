#include "Uzytkownik.h"

Uzytkownik::Uzytkownik()
    : id(0), imie(""), nazwisko(""), email("") {}

Uzytkownik::Uzytkownik(int id, string imie, string nazwisko, string email)
    : id(id), imie(imie), nazwisko(nazwisko), email(email) {}

int Uzytkownik::pobierzID() const {
    return id;
}

string Uzytkownik::pobierzImie() const {
    return imie;
}

string Uzytkownik::pobierzNazwisko() const {
    return nazwisko;
}

string Uzytkownik::pobierzEmail() const {
    return email;
}

