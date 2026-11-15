#include "Koszyk.h"
#include <iostream>

using namespace std;

void Koszyk::dodajDoKoszyka(const Produkt& p) {
    produktyWKoszyku.push_back(p);
    cout << "Produkt zostal dodany do koszyka." << endl;
}

void Koszyk::usunZKoszyka(const Produkt& p) {
    if (produktyWKoszyku.empty()) {
        cout << "Koszyk jest pusty. Nie mozna nic usunac." << endl;
        return;
    }
    
    for (auto it = produktyWKoszyku.begin(); it != produktyWKoszyku.end(); ++it) {
        if (it->pobierzId() == p.pobierzId()) {
            produktyWKoszyku.erase(it);
            cout << "Usunieto produkt z koszyka." << endl;
            return;
        }
    }
}
void Koszyk::wyczyscKoszyk() {
    produktyWKoszyku.clear();
    wartoscKoszyka = 0.0;
    cout << "Koszyk zostal wyczyszczony." << endl;
}
