#include "Zamowienie.h"
#include <iostream>

using namespace std;
Zamowienie::Zamowienie() : idZamowienia(0), dataZlozenia(""), status("Nowe"), pozycje(), platnosc() {}
Zamowienie::Zamowienie(int idZamowienia, string dataZlozenia, string status, vector<PozycjaZamowienia> pozycje, Platnosc platnosc, string status)
    : idZamowienia(idZamowienia), dataZlozenia(dataZlozenia), status(status), pozycje(pozycje), platnosc(platnosc) {}

double Zamowienie::obliczKwote() {
    double suma = 0.0;
    
    for (size_t i = 0; i < pozycje.size(); i++) {
        suma += pozycje[i].pobierzCene() * pozycje[i].pobierzIlosc();
    }
    
    
    if (suma < 0.0) {
        cout << "Wyliczona kwota zamowienia jest ujemna" << endl;
        return 0.0;
    }
    
    return suma;
}

void Zamowienie::aktualizujStatus(string nowyStatus) {
    

    if (status == "Anulowane") {
        cout << "To zamowienie zostalo juz anulowane. Nie mozesz zmienic jego statusu na " << nowyStatus << "." << endl;
        return;
    }
    
    if (nowyStatus == "Oplacone" || nowyStatus == "Wyslane" || nowyStatus == "Zrealizowane" || nowyStatus == "Anulowane") {
        status = nowyStatus;
        cout << "Sukces! Status zamowienia zostal zaktualizowany na: " << status << endl;
    } else {
        cout << "Blad: Nierozpoznany status '" << nowyStatus << "'. Aktualizacja przerwana." << endl;
    }
}

int Zamowienie::pobierzId() const {
    return idZamowienia;
}

string Zamowienie::pobierzDateZlozenia() const {
    return dataZlozenia;
}

string Zamowienie::pobierzStatus() const {
    return status;
}

vector<PozycjaZamowienia> Zamowienie::pobierzPozycje() const {
    return pozycje;
}

Platnosc& Zamowienie::pobierzPlatnosc() {
    return platnosc;
}

void Zamowienie::ustawId(int id) {
    idZamowienia = id;
}

void Zamowienie::ustawDateZlozenia(string data) {
    dataZlozenia = data;
}

void Zamowienie::dodajPozycje(PozycjaZamowienia pozycja) {
    pozycje.push_back(pozycja);
}

void Zamowienie::ustawPlatnosc(Platnosc nowaPlatnosc) {
    platnosc = nowaPlatnosc;
}