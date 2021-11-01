#pragma once
#include  "Personnage.hpp"
#include <string>
#include <iostream>
#include <vector>

class Hero : virtual public Personnage
{
public:
	Hero() = default;

	Hero(const std::string nom, const std::string premiereApparition, const std::string ennemi) : Personnage(nom, premiereApparition), ennemi_(ennemi) {}

	Hero(const Hero& h) : Personnage(h.nom_, h.titrePremiereApparition_), ennemi_(h.ennemi_), allies_(h.allies_) {}

	void afficher() {
		std::cout << color_ << " nom: " << nom_ << std::endl << "titre premiere appartition : " << titrePremiereApparition_ << std::endl << "Ennemi : " << ennemi_ << std::endl;

		for (auto allie : allies_) {
			std::cout << color_ << allie << std::endl;
		}
	}

	void changerCouleur(std::string couleur) {
		this->color_ = COLOR.find(couleur)->second;
	}

protected:
	std::string ennemi_;
	std::vector<std::string> allies_;
};

