#include <iostream>
#include <stdlib.h> 
using namespace std;

int  nbTentative = 0;

const int MIN = 0;
const int MAX = 1000;

/*
*@return nb, le nombre lu
*@param min : borne minimum de l'interval
*@param max : borne maximum de l'interval
*/
int readNumber(string text, int min, int max);

int main(int argc, char const* argv[]) {

    int nb;

    int nbtrouver = (rand() % ((MAX + 1) - MIN)) + MIN;
    do {
        nb = readNumber("entrez un nombre entier :", MIN, MAX);

        if (nb > nbtrouver) {
            cout << "Trop haut. \n";
        }
        else if (nb < nbtrouver) {
            cout << "Trop bas. \n";
        }

    } while (nb != nbtrouver);

    cout << "bravo vous avez reussi en " << nbTentative << " tentatives !\n";
    return 0;
}

int readNumber(string text, int min, int max) {

    int nb = 0;

    do {
        nbTentative++;
        cout << text;
        cin >> nb;
    } while (!(nb >= min & nb <= max));

    return nb;
}