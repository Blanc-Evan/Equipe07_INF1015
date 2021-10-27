#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//TODO: Vos surcharges d'opérateur endl
ostream& operator<<(ostream os, const Concepteur element) {
	return os << "Nom: "+element.getNom() << "Année Naissance : "+element.getAnneeNaissance() << "Pays: "+element.getPays() << endl;
}

ostream& operator<<(ostream os, const Jeu element) {
	string s = "";
	for (auto i : iter::range(element.getListConcepteurs().size())) {
		auto c =  element.getListConcepteurs()[i];
		string annee = c->getAnneeNaissance() + "";
		s += "nom: "+ c->getNom() + " Année Naissance: "+annee + " Pays: "+c->getPays() + "\n";
	}
	return os << "Titre: " + element.getTitre() << "Année Sortie : " + element.getAnneeSortie() << "Developpeur: " + element.getDeveloppeur() << "Liste Concepteurs: \n"+s << endl;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	Liste<Jeu> lj = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	//cout << ligneSeparation << lj;
	//ofstream("sortie.txt") << lj;

	//TODO: Compléter le main avec les tests demandés.
	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.

	//for (int i = 0; i < 2; i++) {
	//	std::shared_ptr<Concepteur> c = lj.getElements()[i].get()->trouverConcepteur([](Concepteur c) {return c.getNom() == "Yoshinori Kitaze"; });
		//if (c != nullptr) {
			///cout << c;
		//}
	//}

	//Jeu copieJeu = *lj[2];

	//copieJeu.getListConcepteurs()[2] = lj[0]->getListConcepteurs()[0];

	//cout << lj[2];

	//cout << std::make_shared<Jeu> (copieJeu);

	// La création de la liste couvre les autres fonctions de notre code
}
