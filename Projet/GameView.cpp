#include "GameView.hpp"
//TODO refactor into fct
void GameView::initialize() {

	std::shared_ptr<Salle> entree = std::make_shared<Salle>("Entrée", "Vous êtes dans l'entrée. Il y a un tapis sur le sol.\n");
	std::shared_ptr<Salle> salon = std::make_shared<Salle>("Salon", "Vous êtes dans le salon.\n");
	std::shared_ptr<Salle> couloir = std::make_shared<Salle>("Couloir", "Vous êtes dans le couloir.\n");
	std::shared_ptr<Salle> petiteChambre = std::make_shared<Salle>("PetiteChambre", "Vous êtes dans une petite chambre. Elle n'a rien de spécial autre que d'être petite.\n");
	std::shared_ptr<Salle> cuisine = std::make_shared<Salle>("Cuisine", "Vous êtes dans la cuisine. Elle est très jaune 'beurre' comme la mode d'une certaine époque.\n");
	std::shared_ptr<Salle> salleR = std::make_shared<Salle>("Salle 'R'", "Vous êtes dans la salle 'R'.\n");

	entree->setDirections(couloir, salon, nullptr, nullptr);
	salon->setDirections(nullptr, nullptr, nullptr, entree);
	couloir->setDirections(cuisine, nullptr, entree, petiteChambre);
	petiteChambre->setDirections(nullptr, nullptr, nullptr, couloir);
	cuisine->setDirections(nullptr, nullptr, couloir, nullptr);
	salleR->setDirections(nullptr, nullptr, nullptr, couloir);

	std::shared_ptr<ObjetInterractif> interrupteur = std::make_shared<ObjetInterractif>("Interrupteur", "Vous voyez un interrupteur au mur", "Vous actionnez l'interrupteur, la lumière s'allume", "");
	std::shared_ptr<ObjetInterractif> boutonRouge = std::make_shared<ObjetInterractifPourDeverouillerZone>("Bouton rouge", "Vous voyez un bouton rouge", "Vous appuyez sur le bouton, la salle 'R' est connectée", std::make_pair(salleR->getNom(), 'E'), couloir->getNom());
	std::shared_ptr<ObjetInterractif> toucheVerte = std::make_shared<ObjetInterractif>("Touche Verte", "Une touche de couleur verte, elle à l'air cassée", "[action à ajouter]", "");
	std::shared_ptr<ObjetInterractif> piano = std::make_shared<ObjetInterractifPourDeverouillerObjet>("Piano", "Un vieux piano d'entrée de gamme Yamaha avec 61 touches, on dirait un objet des année 90", "Une touche verte tombe pendant que vous jouez", toucheVerte, salon->getNom());
	std::shared_ptr<ObjetInterractif> chaussures = std::make_shared<ObjetInterractif>("Chaussures", "Une paire de chaussures pour homme, elle sent particulièrement mauvais", "Vous les rangez dans le placard", "");
	
	couloir->ajouterObjet(interrupteur);
	salon->ajouterObjet(boutonRouge);
	salon->ajouterObjet(piano);
	entree->ajouterObjet(chaussures);

	controller_->ajouterSalle(entree);
	controller_->ajouterSalle(salon);
	controller_->ajouterSalle(couloir);
	controller_->ajouterSalle(petiteChambre);
	controller_->ajouterSalle(cuisine);
	controller_->ajouterSalle(salleR);

	controller_->ajouterObjet(interrupteur);
	controller_->ajouterObjet(boutonRouge);
	controller_->ajouterObjet(toucheVerte);
	controller_->ajouterObjet(piano);
	controller_->ajouterObjet(chaussures);

	controller_->setSalleActuelle(entree);

	std::cout << ">>>>>>>>>> INF1015 DUNGEON CRAWLER 2021 <<<<<<<<<<" << std::endl;
	std::cout << controller_->getSalleActuelle()->look() << std::endl;
}

void GameView::execute(std::string commande) {
	controller_->execute(commande);
}


std::string GameView::play() {
	bool correct = false;
	std::string commande;
	do {
		std::cout << ">";
	
		std::getline(std::cin, commande);

		if (commande == "exit") return commande;
		if (verification(commande)) correct = true;
		else std::cout << "Je ne connais pas cette commande" << std::endl;
	} while (!correct);

	execute(commande);
	return commande;
}


bool GameView::verification(const std::string& str) {
	std::string commande = str.substr(0, str.find(' '));
	if (controller_->getCommandes().contains(commande) || commande == "use") return true;
	return false;
}