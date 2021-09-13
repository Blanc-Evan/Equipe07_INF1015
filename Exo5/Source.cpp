#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const string FILENAME = "inventaire.txt";
const int TAILLE = 10;

struct Aliment {

	string nom;
	string type;
	unsigned int quantite = 0;
	float prix = 0;
};


int main(int argc, char const* argv[]) {

	Aliment tab[TAILLE];
	int i = 0;
	ifstream file(FILENAME);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {

			istringstream str(line);
			Aliment a;
			str >> a.nom >> a.type >> a.quantite >> a.prix;
			tab[i] = a;
			i++;
		}
	}
}