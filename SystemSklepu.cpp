#include "SystemSklepu.h"
#include <iostream>

using namespace std;

SystemSklepu::SystemSklepu() {}

SystemSklepu::SystemSklepu(vector<Klient> klienci, vector<Produkt> produkty, vector<Zamowienie> zamowienia, vector<Rezerwacja> rezerwacje)
    : listaKlientow(klienci), katalogProduktow(produkty), listaZamowien(zamowienia), aktywneRezerwacje(rezerwacje) {}

vector<Klient> SystemSklepu::pobierzListeKlientow() const {
    return listaKlientow;
}

vector<Produkt> SystemSklepu::pobierzKatalogProduktow() const {
    return katalogProduktow;
}

vector<Zamowienie> SystemSklepu::pobierzListeZamowien() const {
    return listaZamowien;
}

vector<Rezerwacja> SystemSklepu::pobierzAktywneRezerwacje() const {
    return aktywneRezerwacje;
}

vector<Produkt> SystemSklepu::wyszukajProdukt(string fraza, string kategoria, string marka) {
    vector<Produkt> znalezione;
    
    for (const auto& produkt : katalogProduktow) {
        bool pasuje = true;
        
        if (!fraza.empty() && produkt.pobierzNazwe().find(fraza) == string::npos) {
            pasuje = false;
        }
        
        if (!kategoria.empty() && produkt.pobierzKategorie() != kategoria) {
            pasuje = false;
        }
        
        if (!marka.empty() && produkt.pobierzMarke() != marka) {
            pasuje = false;
        }
        
        if (pasuje) {
            znalezione.push_back(produkt);
        }
    }
    
    return znalezione;
}

void SystemSklepu::dodajProdukt(int id_admina, Produkt p) {
    cout << "[LOG] Administrator (ID: " << id_admina << ") dodal nowy produkt: " << p.pobierzNazwe() << endl;
    katalogProduktow.push_back(p);
}

void SystemSklepu::zlozZamowienie(int id_klienta, Zamowienie z) {
    cout << "[LOG] Klient (ID: " << id_klienta << ") zlozyl zamowienie nr: " << z.pobierzId() << endl;
    listaZamowien.push_back(z);
}

