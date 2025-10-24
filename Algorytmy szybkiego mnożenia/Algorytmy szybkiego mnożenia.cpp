#include <iostream>
#include <stdio.h>
#include <cstdlib>  // dla system()

using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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
    switch (a)
    {
        case 1:
            cout << "Test 1";
            break;
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