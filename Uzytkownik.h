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
    // Wirtualny destruktor - dobra praktyka dla klas bazowych (z których się dziedziczy)
    virtual ~Uzytkownik() = default;
    
    // Tu w przyszłości dodasz konstruktor i metody dostępowe
};

#endif // UZYTKOWNIK_H
