#include "GameController.hpp"

void GameController::initialize() {

	commandes_.insert(std::pair<std::string, std::function < void()>>("N", [&]() {
		if (auto salle = salleActuelle_->getDirection('N'); salle != nullptr) {
			std::cout << "Direction le Nord" << std::endl;
			salleActuelle_ = salle;
			std::cout << salleActuelle_->look() << std::endl;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
		}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("E", [&]() {
		if (auto salle = salleActuelle_->getDirection('E'); salle != nullptr) {
			std::cout << "Direction l'Est" << std::endl;
			salleActuelle_ = salle;
			std::cout << salleActuelle_->look() << std::endl;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
		}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("S", [&]() {
		if (auto salle = salleActuelle_->getDirection('S'); salle != nullptr) {
			std::cout << "Direction le Sud" << std::endl;
			salleActuelle_ = salle;
			std::cout << salleActuelle_->look() << std::endl;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
		}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("O", [&]() {
		if (auto salle = salleActuelle_->getDirection('O'); salle != nullptr) {
			std::cout << "Direction l'Ouest" << std::endl;
			salleActuelle_ = salle;
			std::cout << salleActuelle_->look() << std::endl;
		}
		else std::cout << "On ne pêut pas y aller !" << std::endl;
		}));
	commandes_.insert(std::pair<std::string, std::function < void()>>("look", [&]() {
		std::cout << salleActuelle_->look() << std::endl;
		}));
}

void GameController::execute(std::string commande) {
	if (commande.size() <= 4) // La commande est bonne puisque déjà vérifée dans GameView::verification, donc si c'est une commande pour salles, size <= 4
		commandes_[commande]();

	else { // c'est une commande pour objets
		bool found = false;
		std::string instruction = commande.substr(0, commande.find(' '));
		commande.replace(0, commande.find(' ') + 1, "");
		for (auto&& objet : salleActuelle_->getObjets()) {
			if (objet.second->getNom() == commande) {
				if (instruction == "use") {
					auto result = objet.second->use();
					if (result.second.second != ' ') { // c'est un objet qui deverouille une salle
						for (auto&& s : salles_) {
							if (s.first == result.first) {
								if (result.second.second != ' ') {
									s.second->setDirection(result.second.second, salles_[result.second.first]);
								}
								else { // c'est un objet qui deverouille un objet 
									s.second->ajouterObjet(objets_[result.second.first]);
								}
							}
						}
					}
				}
				else if (instruction == "look") {
					std::cout << objet.second->look() << std::endl;
				}
				else std::cout << "Je ne connais pas cette commande" << std::endl;
			}
		}
	}
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

void GameController::ajouterSalle(std::shared_ptr<Salle> salle) {
	salles_.insert(std::make_pair(salle->getNom(), salle));
}

void GameController::ajouterObjet(std::shared_ptr<ObjetInterractif> objet) {
	objets_.insert(std::make_pair(objet->getNom(), objet));
}