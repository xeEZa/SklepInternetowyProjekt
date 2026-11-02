#include "Zamowienie.h"
#include <iostream>

using namespace std;

// Logika biznesowa 1: Obliczanie całkowitej kwoty zamówienia
double Zamowienie::obliczKwote() {
    double suma = 0.0;
    
    // W profesjonalnym kodzie przeszlibyśmy przez wszystkie pozycje i zsumowali ich wartość:
    // (zakładając, że dopiszemy odpowiednie gettery w klasie PozycjaZamowienia)
    /*
    for (size_t i = 0; i < pozycje.size(); i++) {
        suma += pozycje[i].pobierzCene() * pozycje[i].pobierzIlosc();
    }
    */
    
    // Zabezpieczenie biznesowe: kwota zamówienia nigdy nie może być ujemna
    if (suma < 0.0) {
        cout << "Blad krytyczny: Wyliczona kwota zamowienia jest ujemna!" << endl;
        return 0.0; // W razie bledu, system zabezpiecza sie zwracajac 0
    }
    
    return suma; // Tutaj uzywamy return z konkretna wartoscia (suma), poniewaz funkcja zwraca typ double
}

// Logika biznesowa 2: Aktualizacja statusu z systemem walidacji (sprawdzania)
void Zamowienie::aktualizujStatus(string nowyStatus) {
    
    // Reguła biznesowa A: Zamówienie "Anulowane" to stan ostateczny, z którego nie ma powrotu.
    if (status == "Anulowane") {
        cout << "Odrazono: To zamowienie zostalo juz anulowane. Nie mozesz zmienic jego statusu na " << nowyStatus << "." << endl;
        return; // Znowu - ewakuacja, nie wykonujemy kodu ponizej
    }
    
    // Reguła biznesowa B: Zapobiegamy wpisaniu "bzdur" jako statusu (np. literówki, zmyślone słowa).
    // Dopuszczamy tylko określone, zatwierdzone z góry wartości.
    if (nowyStatus == "Oplacone" || nowyStatus == "Wyslane" || nowyStatus == "Zrealizowane" || nowyStatus == "Anulowane") {
        status = nowyStatus;
        cout << "Sukces! Status zamowienia zostal zaktualizowany na: " << status << endl;
    } else {
        // Jeśli nowStatus to np. "Paczka_w_trakcie_transportu_koniem", system to odrzuci
        cout << "Blad: Nierozpoznany status '" << nowyStatus << "'. Aktualizacja przerwana." << endl;
    }
}
