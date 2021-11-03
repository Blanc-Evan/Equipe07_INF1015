#pragma once
#include  "Personnage.hpp"
#include <string>
#include <iostream>
#include <vector>

class Vilain : virtual public Personnage
{
public:
	Vilain() = default;

	Vilain(const std::string nom, const std::string premiereApparition, const std::string objectif) : Personnage(nom, premiereApparition), objectif_(objectif) {}

	Vilain(const Vilain& v) : Personnage(v.nom_, v.titrePremiereApparition_), objectif_(v.objectif_) {}

	void afficher() {
		std::cout << color_ << " nom: " << nom_ << std::endl << "titre premiere appartition : " << titrePremiereApparition_ << std::endl << "Objectif : " << objectif_ << std::endl;
	}

	void changerCouleur(std::string couleur) {
		this->color_ = COLOR.find(couleur)->second;
	}

	void setEnnemi(const std::string objectif) {
		this->objectif_ = objectif;
	}

	const std::string getEnnemi() {
		return this->objectif_;
	}


protected:
	std::string objectif_;
};

