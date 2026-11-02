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
    
};

#endif
