#include "SystemSklepu.h"

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
