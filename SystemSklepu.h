#ifndef SYSTEM_SKLEPU_H
#define SYSTEM_SKLEPU_H

#include <string>
#include <vector>


#include "Klient.h"
#include "Produkt.h"
#include "Zamowienie.h"
#include "Rezerwacja.h"

using namespace std;

class SystemSklepu {
private:
    vector<Klient> listaKlientow; 
    vector<Produkt> katalogProduktow; 
    vector<Zamowienie> listaZamowien; 
    vector<Rezerwacja> aktywneRezerwacje; 

public:
    vector<Produkt> wyszukajProdukt(string fraza, string kategoria, string marka);  
    void dodajProdukt(int id_admina, Produkt p); 
    void zlozZamowienie(int id_klienta, Zamowienie z);
    void zmienStatusZamowienia(int id_admina, int id_zamowienia, string status); 
    Rezerwacja zarezerwujProdukt(int id_klienta, Produkt p);

#endif