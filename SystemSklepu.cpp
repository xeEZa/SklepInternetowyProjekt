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

void SystemSklepu::dodajProdukt(int id_admina, Produkt& p) {
    cout << "[LOG] Administrator (ID: " << id_admina << ") dodal nowy produkt: " << p.pobierzNazwe() << endl;
    katalogProduktow.push_back(p);
}

void SystemSklepu::zlozZamowienie(int id_klienta, Zamowienie& z) {
    bool znalezionoKlienta = false;
    for (const auto& klient : listaKlientow) {
        if (klient.pobierzID() == id_klienta) {
            znalezionoKlienta = true;
            break;
        }
    }
    if (!znalezionoKlienta) {
        cout << "[BLAD] Nie znaleziono klienta o ID: " << id_klienta << endl;
        return;
    }
    cout << "[LOG] Klient (ID: " << id_klienta << ") zlozyl zamowienie nr: " << z.pobierzId() << endl;
    listaZamowien.push_back(z);
}


void SystemSklepu::zmienStatusZamowienia(int id_admina, int id_zamowienia, string status) {
    bool znaleziono = false;
    
    for (auto& zamowienie : listaZamowien) {
        if (zamowienie.pobierzId() == id_zamowienia) {
            cout << "[LOG] Administrator (ID: " << id_admina << ") zmienia status zamowienia nr " << id_zamowienia << " na: " << status << endl;
            zamowienie.aktualizujStatus(status);
            znaleziono = true;
            break;
        }
    }
    
    if (!znaleziono) {
        cout << "[BLAD] Nie znaleziono zamowienia o ID: " << id_zamowienia << endl;
    }
}

Rezerwacja SystemSklepu::zarezerwujProdukt(int id_klienta, Produkt& p, string dataUtworzenia, string czasWygasniecia) {
    bool znalezionoKlienta = false;
    for (const auto& klient : listaKlientow) {
        if (klient.pobierzID() == id_klienta) {
            znalezionoKlienta = true;
            break;
        }
    }
    
    if (!znalezionoKlienta) {
        cout << "[BLAD] Klient o ID " << id_klienta << " nie istnieje. Rezerwacja odrzucona." << endl;
        return Rezerwacja();
    }
    int noweId = aktywneRezerwacje.size() + 1;
    double oplata = p.pobierzCene() * 0.10;
    
    Rezerwacja nowaRezerwacja(noweId, dataUtworzenia, czasWygasniecia, oplata, p);
    
    aktywneRezerwacje.push_back(nowaRezerwacja);
    
    cout << "[LOG] Klient (ID: " << id_klienta << ") zarezerwowal produkt: " << p.pobierzNazwe() 
         << ". Oplata rezerwacyjna: " << oplata << " zl." << endl;
         
    return nowaRezerwacja;
}

void SystemSklepu::rejestrujKlienta(const Klient& k) {
    listaKlientow.push_back(k);
    cout << "[LOG] Zarejestrowano nowego klienta: " << k.pobierzImie() << " " << k.pobierzNazwisko() << endl;
}

void SystemSklepu::wyswietlKatalog() const {
    cout << "\n--- KATALOG PRODUKTOW ---" << endl;
    if (katalogProduktow.empty()) {
        cout << "Katalog jest pusty." << endl;
        return;
    }
    
    for (const auto& p : katalogProduktow) {
        cout << "ID: " << p.pobierzId() 
             << " | " << p.pobierzNazwe() 
             << " | Cena: " << p.pobierzCene() << " PLN "
             << "| Dostepny: " << (p.pobierzDostepnosc() ? "Tak" : "Nie") << endl;
    }
}