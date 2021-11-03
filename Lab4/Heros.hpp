#pragma once
#include  "Personnage.hpp"
#include <string>
#include <iostream>
#include <vector>

class Heros : virtual public Personnage
{
public:
	Heros() = default;

	Heros(const std::string nom, const std::string premiereApparition, const std::string ennemi) :
		Personnage(nom, premiereApparition),
		ennemi_(ennemi)
	{}

	Heros(const std::shared_ptr<Heros> h) :
		Personnage(h->nom_, h->titrePremiereApparition_),
		ennemi_(h->ennemi_),
		allies_(h->allies_)
	{}

	void afficher() {
		std::cout << color_ << " nom: " << nom_ << std::endl << "titre premiere appartition : " << titrePremiereApparition_ << std::endl << "Ennemi : " << ennemi_ << std::endl;

		for (auto allie : allies_) {
			std::cout << color_ << allie << std::endl;
		}
	}

	void changerCouleur(std::string couleur) {
		this->color_ = COLOR.find(couleur)->second;
	}

	void setEnnemi(const std::string ennemi) {
		this->ennemi_ = ennemi;
	}

	const std::string getEnnemi() {
		return this->ennemi_;
	}

	void aouterAllie(const std::string nomAllie) {
		this->allies_.push_back(nomAllie);
	}

	const std::vector<std::string> getAllies() {
		return this->allies_;
	}

protected:
	std::string ennemi_;
	std::vector<std::string> allies_;
};

