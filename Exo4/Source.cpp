#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

void readTab(int tab[]);

void trierTab(int tab[]);

const int TAILLE = 10;


int main() {

    int tab[TAILLE];

    readTab(tab);

    trierTab(tab);

    cout << endl;

    for (int i = 0; i < TAILLE; i++) {
        cout << tab[i];
    }

    return 0;
}

void readTab(int tab[]) {

    cout << "Entrez " << TAILLE << " nombres entiers : " << endl;
    for (int i = 0; i < TAILLE; i++) {
        cin >> tab[i];
    }
}

void trierTab(int tab[]) {

    int indiceMin = 0;
    int i, j, temp;

    for (i = 0; i < TAILLE - 1; i++) {
        indiceMin = i;
        for (j = i + 1; j < TAILLE; j++)
            if (tab[j] < tab[indiceMin])
                indiceMin = j;
        temp = tab[i];
        tab[i] = tab[indiceMin];
        tab[indiceMin] = temp;
    }
}