#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Salle.hpp"
#include <iostream>
#include "Objet.hpp"
#include <functional>
#include <ranges>
#include <algorithm>

class GameController
{
public:
	GameController() { initialize(); };

	void initialize();
	void execute(std::string commande);
	std::map<std::string, std::function<void()>>& getCommandes();

	std::shared_ptr<Salle> getSalleActuelle();
	void setSalleActuelle(std::shared_ptr<Salle> salle);
	void ajouterSalle(std::shared_ptr<Salle> salle);
	void ajouterObjet(std::shared_ptr<ObjetInterractif> objet);

private:
	std::shared_ptr<Salle> salleActuelle_;
	std::map<std::string, std::shared_ptr<Salle>> salles_;
	std::map<std::string, std::shared_ptr<ObjetInterractif>> objets_;
	std::map<std::string, std::function<void()>> commandes_;
};
