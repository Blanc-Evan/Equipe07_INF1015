#include <fstream>
#include "bibliotheque_cours.hpp"
#include "Heros.hpp"
#include "Vilain.hpp"
#include "VilainHeros.hpp"

using UInt8  = uint8_t;
using UInt16 = uint16_t;

UInt8 lireUint8(std::istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(std::istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

std::string lireString(std::istream& fichier)
{
	std::string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), std::streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

using namespace std;


int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	// Trait de separation
	static const string trait =
		"-------------------------------------------------------------------------";

	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin", ios::binary);
	ifstream fichierVilains("vilains.bin", ios::binary);
	fichierHeros.exceptions(ios::failbit);
	fichierVilains.exceptions(ios::failbit);

	//TODO: Votre code pour le main commence ici
	std::vector<shared_ptr<Heros>> heros;
	std::vector<shared_ptr<Vilain>> vilains;
	std::vector<shared_ptr<Personnage>> personnages;

	// Lecture Hero

	unsigned nHeros = lireUint16(fichierHeros);

	for (int i = 0; i < nHeros; i++) {
		vector<string> allies;
		string nom = lireString(fichierHeros);
		string parution = lireString(fichierHeros);
		string ennemi = lireString(fichierHeros);

		shared_ptr<Heros> h = make_shared<Heros>(nom, parution, ennemi);

		int n = lireUint8(fichierHeros);
		for (int i = 0; i < n; i++) 
			h->ajouterAllie(lireString(fichierHeros));
		
		heros.push_back(h);
	}
	

	// Lecture Vilain

	unsigned nVilain = lireUint16(fichierVilains);

	for (int i = 0; i < nHeros; i++) {
		string nom = lireString(fichierVilains);
		string parution = lireString(fichierVilains);
		string objectif = lireString(fichierVilains);

		shared_ptr<Vilain> v = make_shared<Vilain>(nom, parution, objectif);
		
		vilains.push_back(v);
	}


	// TODO : Lecture et remplissage des vecteurs à partir des fichiers
	

	
	for (auto& h : heros) {
		h->changerCouleur("BLUE");
		h->afficher();
		cout << trait << endl;
	}

	for (auto& v : vilains) {
		v->changerCouleur("RED");
		v->afficher();
		cout << trait << endl;
	}

	// Ajout à personnages

	for (auto& h : heros) {
		personnages.push_back(h);
	}

	for (auto& v : vilains) {
		personnages.push_back(v);
	}


	// Affichage avec polymorphisme

	for (auto& p : personnages) {
		p->afficher();
		cout << trait << endl;
	}

	unique_ptr<VilainHeros> vh = make_unique<VilainHeros>(vilains[0], heros[0]);

	vh->afficher();

}
