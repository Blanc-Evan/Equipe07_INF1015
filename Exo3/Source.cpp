#include <iostream>
#include <stdlib.h> 
#include <cmath>
using namespace std;

bool isPosition1Superieure = false;
/*
*@return nb, le nombre lu
*@param min : borne minimum de l'interval
*@param max : borne maximum de l'interval
*/
int readNumber(string text, int min, int max);

/*
*@return
*@param temps actuel
*@param position1 : position du premier train
*@param position2 : position du deuxième train
*/
void avancerSimulation1Seconde(int& temps, int& position1, int& position2, const int& vitesse1, const int& vitesse2);


int main(int argc, char const* argv[]) {
    const int tempsTotal = readNumber("Entrez le temps total :", 0, INFINITY);
    int temps = 0;

    const int positionInitiale1 = readNumber("Entrez la postition initiale du premier train :", -1000, 1000);
    const int vitesse1 = readNumber("Entrez la vitesse du premier train :", -100, 100);
    int position1 = positionInitiale1;

    const int positionInitiale2 = readNumber("Entrez la postition initiale du second train :", -1000, 1000);
    const int vitesse2 = readNumber("Entrez la vitesse du second train :", -100, 100);
    int position2 = positionInitiale2;

    if (positionInitiale1 == positionInitiale2) cout << "Il y a eu une collision à 0 secondes";

    if (positionInitiale1 > positionInitiale2) isPosition1Superieure = true;

    while (temps <= tempsTotal) {
        avancerSimulation1Seconde(temps, position1, position2, vitesse1, vitesse2);

        if (isPosition1Superieure) {
            if (position1 < position2) {
                cout << "Il y a eu une collision pendant la " << temps << " seconde !" << endl;
                return 0;
            }
        }
        else {
            if (position1 > position2) {
                cout << "Il y a eu une collision pendant la " << temps << " seconde !" << endl;
                return 0;
            }
        }
    }

    cout << "IL n'y a pas de collision dans les " << tempsTotal << "premières secondes" << endl;

    return 0;
}


int readNumber(string text, int min, int max) {

    int nb = 0;

    do {
        cout << text;
        cin >> nb;
    } while (!(nb >= min & nb <= max));

    return nb;
}

void avancerSimulation1Seconde(int& temps, int& position1, int& position2, const int& vitesse1, const int& vitesse2) {

    temps++;
    cout << "Apres" << temps << " seconde(s)" << endl;

    position1 += vitesse1;
    position2 += vitesse2;

    cout << "Train 1 : " << position1 << endl;
    cout << "Train 2 : " << position2 << endl;

}