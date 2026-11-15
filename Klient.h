#ifndef KLIENT_H
#define KLIENT_H

#include <string>
#include "Uzytkownik.h"
#include "Koszyk.h"

using namespace std;

class Klient : public Uzytkownik {
private:
    Koszyk koszyk;
    string adresDostawy;
    
public:
    Klient();
    Klient(int id, string imie, string nazwisko, string email, string adresDostawy);
    virtual ~Klient() = default;

    Koszyk& pobierzKoszyk();
    string pobierzAdresDostawy() const;
};

#endif
