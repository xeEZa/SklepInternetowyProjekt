#include "Platnosc.h"
#include <iostream>

using namespace std;

bool Platnosc::zrealizujPlatnosc() {
    
    if (czyOplacone) {
        cout << "Ta transakcja (ID: " << idPlatnosci << ") zostala juz oplacona." << endl;
        return false;
    }

    if (kwota <= 0.0) {
        cout << "Kwota do zaplaty nie moze byc zerowa ani ujemna (" << kwota << " PLN)." << endl;
        return false;
    }

    if (metodaPlatnosci != "BLIK" && metodaPlatnosci != "Karta" && metodaPlatnosci != "Przelew") {
        cout << "Nieobslugiwana metoda platnosci (" << metodaPlatnosci << ")." << endl;
        return false;
    }

    czyOplacone = true;
    cout << "Sukces: Platnosc w wysokosci " << kwota << " zl zostala poprawnie zrealizowana (" << metodaPlatnosci << ")." << endl;
    
    return true;
}
