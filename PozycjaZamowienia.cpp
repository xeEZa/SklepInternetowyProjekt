#include "PozycjaZamowienia.h"
#include <iostream>

using namespace std;
double PozycjaZamowienia::pobierzCene() {
    return cenaJednostkowa;
}

int PozycjaZamowienia::pobierzIlosc() {
    return ilosc;
}
