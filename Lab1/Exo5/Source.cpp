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
	float prix = 0.0;
};

void afficherAlimentLePlusCher(vector<Aliment> inventaire);

int main() {

	vector<Aliment> inventaire;
	int i = 0;
	ifstream file(FILENAME);

	if (file.is_open()) {
		string mot;
		while (file && i < 10) {

			Aliment a;

			getline(file, a.nom, '\t');
			getline(file, a.type, '\t');
			file >> mot;
			a.quantite = stoi(mot);
			file >> mot;
			a.prix = stof(mot);


			inventaire.push_back(a);
			i++;
		}
		file.close();
		afficherAlimentLePlusCher(inventaire);
	}
	else {
		cout << "Exception: File not found";
	}
}

void afficherAlimentLePlusCher(vector<Aliment> inventaire) {

	Aliment lePlusCher = inventaire[0];

	for (size_t i = 1; i < inventaire.size() - 1; i++)
		if (inventaire[i].prix > lePlusCher.prix)
			lePlusCher = inventaire[i];

	cout << lePlusCher.quantite
		<< " "
		<< lePlusCher.nom
		<< " ("
		<< lePlusCher.type
		<< ") "
		<< lePlusCher.prix
		<< "$ chacun";
}