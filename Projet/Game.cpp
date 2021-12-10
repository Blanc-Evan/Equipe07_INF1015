#include "Game.hpp"

void Game::initialize() {
	shared_ptr<Salle> entree = make_shared<Salle>("Entr�e", "Vous �tes dans l'entr�e. Il y a un tapis sur le sol.\n");
	shared_ptr<Salle> salon = make_shared<Salle>("Salon", "Vous �tes dans le salon.\n");
	shared_ptr<Salle> couloir = make_shared<Salle>("Couloir", "Vous �tes dans le couloir.\n");
	shared_ptr<Salle> petiteChambre = make_shared<Salle>("PetiteChambre", "Vous �tes dans une petite chambre. Elle n'a rien de sp�cial autre que d'�tre petite.\n");
	shared_ptr<Salle> cuisine = make_shared<Salle>("Cuisine", "Vous �tes dans la cuisine. Elle est tr�s jaune 'beurre' comme la mode d'une certaine �poque.\n");
	entree->setDirections(couloir, salon, nullptr, nullptr);
	salon ->setDirections(nullptr, nullptr, nullptr, entree);
	couloir->setDirections(cuisine, petiteChambre, entree, nullptr);
	petiteChambre->setDirections(nullptr, nullptr, nullptr, couloir);
	cuisine->setDirections(nullptr, nullptr, couloir, nullptr);

	this->salleActuelle = entree;
}

string Game::play() {
	string commande = "";
	bool correct = false;
	do {
		cout << ">";
		cin >> commande;

		if (verification(commande)) correct = true;
		else cout << "Je ne connais pas cette commande";
	} while (!correct);

	// changer de salle ou regarder
}

bool Game::verification(const string& str) {
	return ((str.size() == 1) && (toupper(str[0]) == 'N' || toupper(str[0]) == 'E' || toupper(str[0]) == 'S' || toupper(str[0]) == 'O') || str == "look");
}