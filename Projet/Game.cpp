#include "Game.hpp"

void Game::initialize() {

	commandes_.insert(std::pair<std::string, std::function < void()>>("N", [&]() {
		if (auto salle = salleActuelle_->getDirection('N'); salle != nullptr) {
			std::cout << "Direction le Nord" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne p�ut pas y aller !" << std::endl;
	}));

	commandes_.insert(std::pair<std::string, std::function < void()>>("E", [&]() {
		if (auto salle = salleActuelle_->getDirection('E'); salle != nullptr) {
			std::cout << "Direction l'Est" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne p�ut pas y aller !" << std::endl;
	}));

	commandes_.insert(std::pair<std::string, std::function < void()>>("S", [&]() {
		if (auto salle = salleActuelle_->getDirection('S'); salle != nullptr) {
			std::cout << "Direction le Sud" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne p�ut pas y aller !" << std::endl;
	}));

	commandes_.insert(std::pair<std::string, std::function < void()>>("O", [&]() {
		if (auto salle = salleActuelle_->getDirection('O'); salle != nullptr) {
			std::cout << "Direction l'Ouest" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne p�ut pas y aller !" << std::endl;
	}));

	commandes_.insert(std::pair<std::string, std::function < void()>>("look", [&]() {
		std::cout << salleActuelle_->look() << std::endl;
	}));


	std::shared_ptr<Salle> entree = std::make_shared<Salle>("Entr�e", "Vous �tes dans l'entr�e. Il y a un tapis sur le sol.\n");
	std::shared_ptr<Salle> salon = std::make_shared<Salle>("Salon", "Vous �tes dans le salon.\n");
	std::shared_ptr<Salle> couloir = std::make_shared<Salle>("Couloir", "Vous �tes dans le couloir.\n");
	std::shared_ptr<Salle> petiteChambre = std::make_shared<Salle>("PetiteChambre", "Vous �tes dans une petite chambre. Elle n'a rien de sp�cial autre que d'�tre petite.\n");
	std::shared_ptr<Salle> cuisine = std::make_shared<Salle>("Cuisine", "Vous �tes dans la cuisine. Elle est tr�s jaune 'beurre' comme la mode d'une certaine �poque.\n");
	std::shared_ptr<Salle> salleR = std::make_shared<Salle>("Salle 'R'", "Vous �tes dans la salle 'R'.\n");
	
	entree->setDirections(couloir, salon, nullptr, nullptr);
	salon ->setDirections(nullptr, nullptr, nullptr, entree);
	couloir->setDirections(cuisine, petiteChambre, entree, nullptr);
	petiteChambre->setDirections(nullptr, nullptr, nullptr, couloir);
	cuisine->setDirections(nullptr, nullptr, couloir, nullptr);

	couloir->ajouterObjet(std::make_shared<ObjetInterractif>("Interrupteur", "Vous voyez un interrupteur au mur", "Vous actionnez l'interrupteur, la lumi�re s'allume"));
	salon->ajouterObjet(std::make_shared<ObjetInterratifPourDeverouillerZone>("Bouton rouge", "Vous voyez un bouton rouge", "Vous appuyez sur le bouton, la salle 'R' est connect�e", salleR, 'E'));
	std::shared_ptr<ObjetInterractif> toucheVerte = std::make_shared<ObjetInterractif>("Touche Verte", "Une touche de couleur verte, elle � l'air cass�e");
	salon->ajouterObjet(std::make_shared<ObjetInterratifPourDeverouillerObjet>("Un piano electronique d'entr�e de gamme", "Un vieux piano d'entr�e de gamme Yamaha avec 61 touches, on dirait un objet des ann�e 90", "Une touche verte tombe pendant que vous jouez", toucheVerte));
	entree->ajouterObjet(std::make_shared<ObjetInterractif>("Une paire de chaussures pour homme", "Une paire de chaussures pour homme, elle sent particuli�rement mauvais", "Vous les rangez dans le placard"));
	
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
	return commandes_.contains(str);
}

void Game::execute() {
	commandes_[commande_]();
}