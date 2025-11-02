#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>  // dla system()

using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int wczytajLiczbe(const string& komunikat) {
    string wejscie;
    while (true) {
        cout << komunikat;
        cin >> wejscie;

        bool poprawne = !wejscie.empty();

        // sprawdzenie, czy wszystkie znaki to cyfry, opcjonalnie minus na początku
        for (size_t i = 0; i < wejscie.size(); i++) {
            if (i == 0 && wejscie[i] == '-') continue; // minus na początku OK
            if (!isdigit(wejscie[i])) {
                poprawne = false;
                break;
            }
        }

        if (poprawne) {
            try {
                int liczba = stoi(wejscie);  // konwersja na int
                return liczba;
            } catch (out_of_range&) {
                cout << "Liczba jest poza zakresem typu int!\n";
            }
        } else {
            cout << "Niepoprawna wartość! Wpisz liczbę całkowitą.\n";
        }

        // czyszczenie stanu strumienia i bufora, aby pętla mogła działać poprawnie
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int Karacuba (int k,int o) {

    bool kUjemne = (k < 0);
    bool oUjemne = (o < 0);

    long long k3 = kUjemne ? -k : k;
    long long o4 = oUjemne ? -o : o;

    string pierwsza = to_string(k3); //zmiana liczby na string aby policzyć ilość znaków
    string druga = to_string(o4);

    //cout << pierwsza << endl;
    //cout << druga << endl;

    long long rozmiar1 = pierwsza.size();
    long long rozmiar2 = druga.size();

    if (rozmiar1 > rozmiar2 or rozmiar1 < rozmiar2) {
        //cout << "start testu" << endl;
        if (rozmiar1 > rozmiar2) {
            int dlugosc = rozmiar1 - rozmiar2;
            //cout << dlugosc << endl;
            for (int i = 0; i<dlugosc; i++) {
                //cout << "start Fora" << endl;
                druga = "0" + druga;
               //cout << druga << endl;
            }
        }

        if (rozmiar2 > rozmiar1) {
            int dlugosc2 = rozmiar2 - rozmiar1;
            //cout << dlugosc2 << endl;
            for (int i = 0; i<dlugosc2; i++) {
                //cout << "start Fora2" << endl;
                pierwsza = "0" + pierwsza;
                //cout << pierwsza << endl;
            }
        }
    } //dodawanie 0 na początek jeśli liczba znaków jest nieparzysta np. dla 45600 i 34 aby poprawić na 45600 i 00034

    if (pierwsza.size() % 2 != 0) {
        pierwsza = "0" + pierwsza;
    } //dodawanie 0 na początek jeśli liczba znaków jest nieparzysta np. zamiana 123 na 0123

    if (druga.size() % 2 != 0) {
        druga = "0" + druga;
    }

    int n1 = pierwsza.length();
    int m1 = n1/2; //zapisywanie ilości znaków dla K oraz O

    //cout << n1 << " " << m1 << " " << endl;
    int KPolowa = pierwsza.size() / 2;
    int OPolowa = druga.size() / 2;

    string Kcz1 = pierwsza.substr(0, KPolowa);
    string Kcz2 = pierwsza.substr(KPolowa);

    //cout << "Kcz1 " << Kcz1 << endl;
    //cout << "Kcz2 " << Kcz2 << endl;

    string Ocz1 = druga.substr(0, OPolowa);
    string Ocz2 = druga.substr(OPolowa); //dzielenie i zapisywanie liczby na 2 części

    //cout << "Ocz1 " << Ocz1 << endl;
    //cout << "Ocz2 " << Ocz2 << endl;

    long long k1 = stoi(Kcz1);
    long long k2 = stoi(Kcz2);

    long long o1 = stoi(Ocz1);
    long long o2 = stoi(Ocz2); //zamiana z string na int lecz już podzielone na 2 części czyli zamiast 0123 mamy o1=01 oraz o2=23

    long long z1 = k1*o1;
    //cout << z1 << endl;
    long long z2 = k2*o2;
    //cout << z2 << endl;
    long long z3 = ((k1 + k2)*(o1 + o2))-z1-z2;
    //cout << z3 << endl;
    long long wynik = z1*pow(10, 2*m1) + z3*pow(10, m1) + z2; //Algorytm Karacuba
    if (kUjemne != oUjemne) {
        wynik = -wynik;
    }
    cout << "gotowy wynik: " << wynik << endl;
    return wynik;

}

int main()
{
    int a = 0;
    bool executed = false; // jeśli nie będzie potrzeba wykonania pętli while
    cout << "Wybierz którego algorytmu chcesz użyć." << endl;
    cout << "1. Algorytm Karacuby" << endl;
    cout << "2. Algorytm Toom-Cook" << endl;
    cout << "3. Algorytm FFT (Fast Fourier Transform)" << endl;
    cout << "4. Algorytm Schönhage–Strassen" << endl;
    cout << "5. Algorytm Fürera" << endl;
    cout << "6. Algorytm Harvey–van der Hoevena" << endl;

    cin >> a;
    if (a < 1 or a > 6 or cin.fail()) {
        while (true) {
            //clearConsole(); //czyszczenie konsoli
            if (executed == true) {
                goto label;
            }
            cin.clear();              // resetuje flagi błędu (failbit)
            cin.ignore(1000, '\n');   // usuwa resztki z bufora wejściowego
            cout << "Niepoprawna wartość, podaj liczbę od 1 do 6." << endl;
            cin >> a;

            if (a >= 1 and a <= 6) {
                executed = true;
            }
        }
    }
    label:
    cout << "Test Po pętli";
    switch (a) {
        case 1: {
            cout << "Podaj dwie liczby całkowite" << endl;

            long long k = wczytajLiczbe("Podaj k: ");
            long long z = wczytajLiczbe("Podaj c: ");

            cout << "Wynik mnożenia przy użyciu Algorytmu Karacuby to: " << Karacuba(k,z) << endl;
            break;
        }
        case 2:
            cout << "Test 2";
            break;
        case 3:
            cout << "Test 3";
            break;
        case 4:
            cout << "Test 4";
            break;
        case 5:
            cout << "Test 5";
            break;
        case 6:
            cout << "Test 6";
            break;
    }

}