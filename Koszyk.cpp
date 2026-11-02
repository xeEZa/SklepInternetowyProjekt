#include "Koszyk.h"
#include <iostream>

using namespace std;

void Koszyk::dodajDoKoszyka(Produkt p) {
    produktyWKoszyku.push_back(p);
    cout << "Produkt zostal dodany do koszyka." << endl;
}

void Koszyk::usunZKoszyka(Produkt p) {
    if (produktyWKoszyku.empty()) {
        cout << "Koszyk jest pusty. Nie mozna nic usunac." << endl;
        return;
    }
    
    produktyWKoszyku.pop_back(); 
    cout << "Usunieto produkt z koszyka." << endl;
}

void Koszyk::wyczyscKoszyk() {
    produktyWKoszyku.clear();
    wartoscKoszyka = 0.0;
    cout << "Koszyk zostal wyczyszczony." << endl;
}
