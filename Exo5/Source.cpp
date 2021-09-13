#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const string FILENAME = "./inventaire.txt";
const int TAILLE = 10;

struct Aliment {

	string nom;
	string type;
	unsigned int quantite = 0;
	float prix = 0;
};

void afficherAlimentLePlusCher(vector<Aliment> inventaire);

int main(int argc, char const* argv[]) {
	
	vector<Aliment> inventaire;
	int i = 0;
	ifstream file(FILENAME);
	if (file.is_open()) {	// Read File
		string line;
		while (getline(file, line)) {

			istringstream str(line);
			Aliment a;
			str >> a.nom >> a.type >> a.quantite >> a.prix;
			inventaire[i] = a;
			i++;
		}
		afficherAlimentLePlusCher(inventaire);
	}
	else {
		cout << "Exception: File not found";
	}


}

void afficherAlimentLePlusCher(vector<Aliment> inventaire) {

	Aliment &lePlusCher = inventaire[0];

	for (int i = 1; i < inventaire.size()-1; i++) 
		if (inventaire[i].prix > lePlusCher.prix)
			lePlusCher = inventaire[i];
	
	cout << lePlusCher.quantite
			<< " " 
			<< lePlusCher.nom
			<< " (" 
			<< lePlusCher.type
			<< ""
			<< lePlusCher.prix
			<< "$ chacun";
}