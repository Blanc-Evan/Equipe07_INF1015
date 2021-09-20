#include <iostream>
#include <math.h>
using namespace std;

bool isPremier(int nb);

int main() {
    while (true) {

        int nb = 0;
        int n;
        cout << "Entrez un nombre \n";
        cin >> nb;
        if (nb == -1) break;
        n = nb - 1;
        do {
            n++;
        } while (!isPremier(n));

        cout << "Le nombre premier suivant est : " << n << endl;
    }
    return 0;
}

bool isPremier(int nb) { // Rappel : un nb premier n'est divisible que par 1 et lui meme

    int racine = (int)sqrt(nb);
    for (int i = 2; i <= racine; i++) {
        if (!(nb % i)) return false;
    }

    return true;
}