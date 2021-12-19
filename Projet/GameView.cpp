#include "GameView.hpp"

void GameView::initialize() {

	std::shared_ptr<Salle> entree = std::make_shared<Salle>("Entrée", "Vous êtes dans l'entrée. Il y a un tapis sur le sol.\n");
	std::shared_ptr<Salle> salon = std::make_shared<Salle>("Salon", "Vous êtes dans le salon.\n");
	std::shared_ptr<Salle> couloir = std::make_shared<Salle>("Couloir", "Vous êtes dans le couloir.\n");
	std::shared_ptr<Salle> petiteChambre = std::make_shared<Salle>("PetiteChambre", "Vous êtes dans une petite chambre. Elle n'a rien de spécial autre que d'être petite.\n");
	std::shared_ptr<Salle> cuisine = std::make_shared<Salle>("Cuisine", "Vous êtes dans la cuisine. Elle est très jaune 'beurre' comme la mode d'une certaine époque.\n");
	std::shared_ptr<Salle> salleR = std::make_shared<Salle>("Salle 'R'", "Vous êtes dans la salle 'R'.\n");

	entree->setDirections(couloir, salon, nullptr, nullptr);
	salon->setDirections(nullptr, nullptr, nullptr, entree);
	couloir->setDirections(cuisine, petiteChambre, entree, nullptr);
	petiteChambre->setDirections(nullptr, nullptr, nullptr, couloir);
	cuisine->setDirections(nullptr, nullptr, couloir, nullptr);

	//couloir->ajouterObjet(std::make_shared<ObjetInterractif>("Interrupteur", "Vous voyez un interrupteur au mur", "Vous actionnez l'interrupteur, la lumière s'allume"));
	//salon->ajouterObjet(std::make_shared<ObjetInterratifPourDeverouillerZone>("Bouton rouge", "Vous voyez un bouton rouge", "Vous appuyez sur le bouton, la salle 'R' est connectée", salleR, 'E'));
	//std::shared_ptr<ObjetInterractif> toucheVerte = std::make_shared<ObjetInterractif>("Touche Verte", "Une touche de couleur verte, elle à l'air cassée");
	//salon->ajouterObjet(std::make_shared<ObjetInterratifPourDeverouillerObjet>("Un piano electronique d'entrée de gamme", "Un vieux piano d'entrée de gamme Yamaha avec 61 touches, on dirait un objet des année 90", "Une touche verte tombe pendant que vous jouez", toucheVerte));
	//entree->ajouterObjet(std::make_shared<ObjetInterractif>("Une paire de chaussures pour homme", "Une paire de chaussures pour homme, elle sent particulièrement mauvais", "Vous les rangez dans le placard"));

	controller_->setSalleActuelle(entree);

	std::cout << ">>>>>>>>>> INF1015 DUNGEON CRAWLER 2021 <<<<<<<<<<" << std::endl;
	std::cout << controller_->getSalleActuelle()->look() << std::endl;
}

void GameView::execute() {
	controller_->execute(commande_);
}


std::string GameView::play() {
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


bool GameView::verification(const std::string& str) {
	return controller_->getCommandes().contains(str);
}