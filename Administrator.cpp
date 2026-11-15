#include "Administrator.h"

Administrator::Administrator()
    : Uzytkownik(), numerPracownika(""), uprawnienia("") {}

Administrator::Administrator(int id, string imie, string nazwisko, string email, string numerPracownika, string uprawnienia)
    : Uzytkownik(id, imie, nazwisko, email), numerPracownika(numerPracownika), uprawnienia(uprawnienia) {}

string Administrator::pobierzNumerPracownika() const {
    return numerPracownika;
}

string Administrator::pobierzUprawnienia() const {
    return uprawnienia;
}