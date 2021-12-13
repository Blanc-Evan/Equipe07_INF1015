#include "Game.hpp"

void Game::initialize() {
	std::shared_ptr<Salle> entree = std::make_shared<Salle>("Entr�e", "Vous �tes dans l'entr�e. Il y a un tapis sur le sol.\n");
	std::shared_ptr<Salle> salon = std::make_shared<Salle>("Salon", "Vous �tes dans le salon.\n");
	std::shared_ptr<Salle> couloir = std::make_shared<Salle>("Couloir", "Vous �tes dans le couloir.\n");
	std::shared_ptr<Salle> petiteChambre = std::make_shared<Salle>("PetiteChambre", "Vous �tes dans une petite chambre. Elle n'a rien de sp�cial autre que d'�tre petite.\n");
	std::shared_ptr<Salle> cuisine = std::make_shared<Salle>("Cuisine", "Vous �tes dans la cuisine. Elle est tr�s jaune 'beurre' comme la mode d'une certaine �poque.\n");
	entree->setDirections(couloir, salon, nullptr, nullptr);
	salon ->setDirections(nullptr, nullptr, nullptr, entree);
	couloir->setDirections(cuisine, petiteChambre, entree, nullptr);
	petiteChambre->setDirections(nullptr, nullptr, nullptr, couloir);
	cuisine->setDirections(nullptr, nullptr, couloir, nullptr);

	salleActuelle_ = entree;

	std::cout << ">>>>>>>>>> INF1015 DUNGEON CRAWLER 2021 <<<<<<<<<<" << std::endl;
	std::cout << salleActuelle_->look() << std::endl; 
}

std::string Game::play() {
	bool correct = false;
	do {
		std::cout << ">";
		std::cin >> commande_;

		if (commande_ == "exit") return commande_;
		if (verification(commande_)) correct = true;
		else std::cout << "Je ne connais pas cette commande" << std::endl;
	} while (!correct);

	execute();
	return commande_;
}

bool Game::verification(const std::string& str) {
	return ((str.size() == 1) && (toupper(str[0]) == 'N' || toupper(str[0]) == 'E' || toupper(str[0]) == 'S' || toupper(str[0]) == 'O') || str == "look");
}

void Game::execute() {
	if (commande_.size() == 1) {
		switch (toupper(commande_[0]))
		{
		case 'N': 
			if (auto salle = salleActuelle_->getDirection('N'); salle != nullptr) {
				std::cout << "Direction le Nord" << std::endl;
				salleActuelle_ = salle;
			}
			else std::cout << "On ne p�ut pas y aller !" << std::endl;
			break;
		case 'E': 
			if (auto salle = salleActuelle_->getDirection('E'); salle != nullptr) {
				std::cout << "Direction l'Est" << std::endl;
				salleActuelle_ = salle;
			}
			else std::cout << "On ne p�ut pas y aller !" << std::endl;
			break;
			
		case 'S': 
			if (auto salle = salleActuelle_->getDirection('S'); salle != nullptr) {
				std::cout << "Direction le Sud" << std::endl;
				salleActuelle_ = salle;
			}
			else std::cout << "On ne p�ut pas y aller !" << std::endl;
			break;

		case 'O':
			if (auto salle = salleActuelle_->getDirection('O'); salle != nullptr) {
				std::cout << "Direction l'Ouest" << std::endl;
				salleActuelle_ = salle;
			}
			else std::cout << "On ne p�ut pas y aller !" << std::endl;
			break;

		default:
			break;
		}
		std::cout << salleActuelle_->look() << std::endl;
	}
	else {
		if (commande_ == "look") {
			std::cout << salleActuelle_->look() << std::endl;
		}
	}
}