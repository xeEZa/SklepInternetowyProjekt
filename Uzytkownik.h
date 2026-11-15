#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <string>

using namespace std;

class Uzytkownik {
protected:
    int id;
    string imie;
    string nazwisko;
    string email;

public:
    Uzytkownik();
    Uzytkownik(int id, string imie, string nazwisko, string email);
    virtual ~Uzytkownik() = default;

    int pobierzID() const;
    string pobierzImie() const;
    string pobierzNazwisko() const;
    string pobierzEmail() const;
    
    
};

#endif
