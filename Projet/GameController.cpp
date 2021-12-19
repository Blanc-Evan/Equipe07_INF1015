#include "GameController.hpp"

void GameController::initialize() {

	commandes_.insert(std::pair<std::string, std::function < void()>>("N", [&]() {
		if (auto salle = salleActuelle_->getDirection('N'); salle != nullptr) {
			std::cout << "Direction le Nord" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
	}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("E", [&]() {
		if (auto salle = salleActuelle_->getDirection('E'); salle != nullptr) {
			std::cout << "Direction l'Est" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
	}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("S", [&]() {
		if (auto salle = salleActuelle_->getDirection('S'); salle != nullptr) {
			std::cout << "Direction le Sud" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
	}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("O", [&]() {
		if (auto salle = salleActuelle_->getDirection('O'); salle != nullptr) {
			std::cout << "Direction l'Ouest" << std::endl;
			salleActuelle_ = salle;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
	}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("look", [&]() {
		std::cout << salleActuelle_->look() << std::endl;
	}));
}

void GameController::execute(std::string commande) {
	commandes_[commande]();
}

std::map<std::string, std::function<void()>>& GameController::getCommandes() {
	return commandes_;
}

std::shared_ptr<Salle> GameController::getSalleActuelle() {
	return salleActuelle_;
}

void GameController::setSalleActuelle(std::shared_ptr<Salle> salle) {
	salleActuelle_ = salle;
}