#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

void readTab(int tab[]);

void trierTab(int tab[]);

const int TAILLE = 10;


int main(int argc, char const* argv[]) {

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


    int min = tab[0];
    int indiceMin = 0;
    int temp;
    int j;



    for (int i = 0; i < TAILLE; i++) {
        j = i;
        for (int k = j; k < TAILLE; k++) {
            if (tab[k] < tab[j])
                j = k;

            temp = tab[j];
            tab[j] = tab[i];
            tab[i] = temp;

        }

    }




    //do {
        //for (int i = borneInf; i < TAILLE; i++) {

            //if (tab[i] < min) {
                // min = tab[i];
                // indiceMin = i;
            //}
        //}

        //temp = tab[borneInf];
        //tab[borneInf] = tab[indiceMin];
        //tab[indiceMin] = temp;

        //borneInf++;
        //min = tab[borneInf];
    //} while (borneInf != TAILLE);
//