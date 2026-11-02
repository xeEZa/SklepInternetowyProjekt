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
    virtual ~Uzytkownik() = default;
    
    
};

#endif
