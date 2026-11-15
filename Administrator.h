#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "Uzytkownik.h"

using namespace std;

class Administrator : public Uzytkownik {
private:
    string numerPracownika;
    string uprawnienia;

public:
    Administrator();
    Administrator(int id, string imie, string nazwisko, string email, string numerPracownika, string uprawnienia);

    string pobierzNumerPracownika() const;
    string pobierzUprawnienia() const;
    
};

#endif
