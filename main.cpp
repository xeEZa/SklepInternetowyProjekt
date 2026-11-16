#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "SystemSklepu.h"
#include "Produkt.h"
#include "Klient.h"
#include "Zamowienie.h"
#include "Platnosc.h"
#include "PozycjaZamowienia.h"
#include "Koszyk.h"

using namespace std;

int main() {
    vector<Klient> bazaKlientow = {
        Klient(1, "Adam", "Nowak", "adam@test.pl", "ul. Prosta 1, Warszawa"),
        Klient(2, "Ewa", "Kowalska", "ewa@test.pl", "ul. Krzywa 2, Krakow")
    };
    
    vector<Produkt> poczatkowyAsortyment = {
        Produkt(1, "Kurtka KPOP Demon Hunters", "Huntrix", "Kurtka", 30000.00, true),
        Produkt(2, "Kukirin", "Saja Boys", "Hulajnogi", 1200.00, true),
        Produkt(3, "Soda Pop T-Shirt", "Saja Boys", "Koszulki", 200.00, true),
        Produkt(4, "Ramones", "Rick Owens", "Buty", 3000.00, true),
        Produkt(5, "Gats Low", "Maison Margiela", "Buty", 2500.00, true),
        Produkt(6, "Czarna suknya z cekinami", "NYA>_<", "Suknya", 750.00, true),
        Produkt(7, "Krutkie skarpetki", "Bilip", "Skarpetki", 69.00, true),
        Produkt(8, "garniEtur", "niE", "Garnitur", 1550.00, true),
    }; 

    SystemSklepu sklep(bazaKlientow, poczatkowyAsortyment, vector<Zamowienie>(), vector<Rezerwacja>());
    
    int idZalogowanego = 1; 
    int ID_ADMINA = 999; 

    int wybor = 0;
    do {
        cout << "\n=================================================" << endl;
        cout << "       KOMPLEKSOWE MENU SYSTEMU SKLEPU           " << endl;
        
        try {
            Klient& aktualny = sklep.pobierzKlientaPoId(idZalogowanego);
            cout << "       >>> ZALOGOWANY KLIENT: ID " << aktualny.pobierzID() 
                 << " (" << aktualny.pobierzImie() << ") <<<" << endl;
        } catch (...) {
            cout << "       >>> ZALOGOWANY KLIENT: BRAK LUB BŁĄD <<<" << endl;
        }
        
        cout << "=================================================" << endl;
        cout << " [1] Wyswietl katalog" << endl;
        cout << " [2] Zarejestruj klienta" << endl;
        cout << " [3] Dodaj produkt [ADMIN]" << endl;
        cout << " [4] Wyszukaj produkt" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << " [5] Dodaj wybrany produkt do Koszyka)" << endl;
        cout << " [6] Usun wybrany produkt z koszyka" << endl;
        cout << " [7] Zloz zamowienie z koszyka i OPLAC" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << " [8] Zmien status zamowienia [ADMIN]" << endl;
        cout << " [9] Zarezerwuj produkt " << endl;
        cout << " [10] Podsumowanie systemu " << endl;
        cout << " [11] Wypisz wszystkich klientow i ich koszyki" << endl;
        cout << " [12] >>> ZALOGUJ SIE (Wybierz aktywnego klienta)" << endl;
        cout << " [0] Wyjscie" << endl;
        cout << "=================================================" << endl;
        cout << "Wybierz akcje: ";
        
        cin >> wybor;

        switch (wybor) {
            case 1: sklep.wyswietlKatalog(); break;
            case 2: {
                int noweId = sklep.pobierzListeKlientow().size() + 1;
                string imie, nazw, email, adres;
                cout << "\nImie: "; cin >> ws; getline(cin, imie);
                cout << "Nazwisko: "; getline(cin, nazw);
                cout << "Email: "; getline(cin, email);
                cout << "Adres Dostawy: "; getline(cin, adres);
                
                Klient nowyK(noweId, imie, nazw, email, adres);
                sklep.rejestrujKlienta(nowyK);
                break;
            }
            case 3: {
                int noweId = sklep.pobierzKatalogProduktow().size() + 1;
                string nazwa, kategoria, marka; double cena;
                cout << "\nNazwa: "; cin >> ws; getline(cin, nazwa);
                cout << "Kategoria: "; getline(cin, kategoria);
                cout << "Marka: "; getline(cin, marka);
                cout << "Cena: "; cin >> cena;
                Produkt p(noweId, nazwa, marka, kategoria, cena, true);
                sklep.dodajProdukt(ID_ADMINA, p);
                break;
            }
            case 4: {
                cout << "\nPodaj fraze do wyszukania: ";
                string szukana; cin >> ws; getline(cin, szukana);
                vector<Produkt> zn = sklep.wyszukajProdukt(szukana, "", "");
                cout << "-> Znaleziono: " << zn.size() << endl;
                for(const auto& x : zn) cout << "   ID: " << x.pobierzId() << " | " << x.pobierzNazwe() << endl;
                break;
            }
            case 5: {
                vector<Produkt> kat = sklep.pobierzKatalogProduktow();
                if(kat.empty()) { cout << "Katalog jest pusty!" << endl; break; }
                
                cout << "\n--- DOSTEPNE PRODUKTY ---" << endl;
                for (const auto& p : kat) cout << "ID: " << p.pobierzId() << " | " << p.pobierzNazwe() << endl;
                
                cout << "Podaj ID produktu do dodania: ";
                int idWybrane; cin >> idWybrane;
                
                bool znaleziono = false;
                for (const auto& p : kat) {
                    if (p.pobierzId() == idWybrane) {
                        try {
                            sklep.pobierzKlientaPoId(idZalogowanego).pobierzKoszyk().dodajDoKoszyka(p);
                            cout << "-> Dodano pomyślnie!" << endl;
                        } catch (const invalid_argument& e) {
                            cout << "[BLAD] " << e.what() << endl;
                        }
                        znaleziono = true;
                        break;
                    }
                }
                if (!znaleziono) cout << "[BLAD] Brak produktu o podanym ID w katalogu." << endl;
                break;
            }
            case 6: {
                try {
                    vector<Produkt> wKoszyku = sklep.pobierzKlientaPoId(idZalogowanego).pobierzKoszyk().pobierzProduktyWKoszyku();
                    if(wKoszyku.empty()) { cout << "Twoj koszyk jest pusty." << endl; break; }
                    
                    cout << "\n--- ZAWARTOSC KOSZYKA ---" << endl;
                    for (const auto& p : wKoszyku) cout << "ID: " << p.pobierzId() << " | " << p.pobierzNazwe() << endl;
                    
                    cout << "Podaj ID produktu do usuniecia (0 anuluje): ";
                    int idUsuwane; cin >> idUsuwane;
                    
                    if (idUsuwane != 0) {
                        for (const auto& p : wKoszyku) {
                            if (p.pobierzId() == idUsuwane) {
                                sklep.pobierzKlientaPoId(idZalogowanego).pobierzKoszyk().usunZKoszyka(p);
                                break;
                            }
                        }
                    }
                } catch (const invalid_argument& e) {
                    cout << "[BLAD] " << e.what() << endl;
                }
                break;
            }
            case 7: {
                try {
                    Klient& k = sklep.pobierzKlientaPoId(idZalogowanego);
                    vector<Produkt> wKoszyku = k.pobierzKoszyk().pobierzProduktyWKoszyku();
                    if(wKoszyku.empty()) { cout << "[BLAD] Koszyk pusty." << endl; break; }

                    vector<PozycjaZamowienia> pozycje;
                    for(const auto& prod : wKoszyku) pozycje.push_back(PozycjaZamowienia(prod, 1, prod.pobierzCene()));

                    double doZaplaty = k.pobierzKoszyk().pobierzWartoscKoszyka();
                    int idPlatnosci = sklep.pobierzListeZamowien().size() + 1;
                    Platnosc platnosc(idPlatnosci, "BLIK", doZaplaty, false);
                    
                    int idZam = sklep.pobierzListeZamowien().size() + 1;
                    Zamowienie noweZamowienie(idZam, "2026-11-16", pozycje, platnosc, "Nowe");
                    
                    noweZamowienie.pobierzPlatnosc().zrealizujPlatnosc(); 
                    sklep.zlozZamowienie(k.pobierzID(), noweZamowienie);
                    
                    k.pobierzKoszyk().wyczyscKoszyk();
                    
                } catch (const invalid_argument& e) {
                    cout << "[BLAD] " << e.what() << endl;
                }
                break;
            }
            case 8: {
                cout << "\nPodaj ID zamowienia: "; 
                int idz; 
                cin >> idz;
                cout << "Podaj status: "; string nowyStatus; cin >> ws; getline(cin, nowyStatus);
                sklep.zmienStatusZamowienia(ID_ADMINA, idz, nowyStatus);
                break;
            }
            case 9: {
                vector<Produkt> kat = sklep.pobierzKatalogProduktow();
                string dataUtworzenia;
                string czasWygasniecia;
                cout << "Podaj date utworzenia rezerwacji (YYYY-MM-DD): ";
                cin >> dataUtworzenia;
                cout << "Podaj czas wygasniecia rezerwacji (YYYY-MM-DD): ";
                cin >> czasWygasniecia;
                if(!kat.empty()) {
                    sklep.zarezerwujProdukt(idZalogowanego, kat.back(), dataUtworzenia, czasWygasniecia);
                }
                break;
            }
            case 10: {
                cout << "\n--- STATYSTYKI BAZY ---" << endl;
                cout << "Klienci: " << sklep.pobierzListeKlientow().size() << endl;
                cout << "Produkty: " << sklep.pobierzKatalogProduktow().size() << endl;
                cout << "Zamowienia: " << sklep.pobierzListeZamowien().size() << endl;
                break;
            }
            case 11: {
                cout << "\n--- KLIENCI I ICH KOSZYKI ---" << endl;
                vector<Klient> klienci = sklep.pobierzListeKlientow();
                if (klienci.empty()) {
                    cout << "Brak zarejestrowanych klientow." << endl;
                } else {
                    for (Klient k : klienci) {
                        cout << "Klient: " << k.pobierzImie() << " " << k.pobierzNazwisko() 
                             << " (ID: " << k.pobierzID() << ")" << endl;
                        vector<Produkt> wKoszyku = k.pobierzKoszyk().pobierzProduktyWKoszyku();
                        if (wKoszyku.empty()) {
                            cout << "  -> Koszyk: PUSTY" << endl;
                        } else {
                            for (const auto& p : wKoszyku) {
                                cout << "  -> ID: " << p.pobierzId() << " | " << p.pobierzNazwe() << endl;
                            }
                            cout << "  -> Suma: " << k.pobierzKoszyk().pobierzWartoscKoszyka() << " PLN" << endl;
                        }
                    }
                }
                break;
            }
            case 12: {
                cout << "\n--- DOSTEPNI KLIENCI ---" << endl;
                vector<Klient> klienci = sklep.pobierzListeKlientow();
                for (const auto& k : klienci) {
                    cout << "ID: " << k.pobierzID() << " | " << k.pobierzImie() << " " << k.pobierzNazwisko() << endl;
                }
                
                cout << "Wpisz ID klienta, na ktorego chcesz sie zalogowac: ";
                int wybraneID; cin >> wybraneID;
                
                try {
                    Klient& k = sklep.pobierzKlientaPoId(wybraneID);
                    idZalogowanego = wybraneID;
                    cout << "[SUKCES] Zalogowano jako: " << k.pobierzImie() << endl;
                } catch (const invalid_argument& e) {
                    cout << "[BLAD] Nie ma klienta o takim ID!" << endl;
                }
                break;
            }
            case 0: cout << "Zamykanie systemu." << endl; break;
            default: cout << "Nieprawidlowa opcja!" << endl; break;
        }
    } while (wybor != 0);

    return 0;
}