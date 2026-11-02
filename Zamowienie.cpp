#include "Zamowienie.h"
#include <iostream>

using namespace std;


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
