#include "Game.hpp"

void Game::initialize() {
	shared_ptr<Salle> entree = make_shared<Salle>("Entrée", "Vous êtes dans l'entrée. Il y a un tapis sur le sol.\n");
	shared_ptr<Salle> salon = make_shared<Salle>("Salon", "Vous êtes dans le salon.\n");
	shared_ptr<Salle> couloir = make_shared<Salle>("Couloir", "Vous êtes dans le couloir.\n");
	shared_ptr<Salle> petiteChambre = make_shared<Salle>("PetiteChambre", "Vous êtes dans une petite chambre. Elle n'a rien de spécial autre que d'être petite.\n");
	shared_ptr<Salle> cuisine = make_shared<Salle>("Cuisine", "Vous êtes dans la cuisine. Elle est très jaune 'beurre' comme la mode d'une certaine époque.\n");
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