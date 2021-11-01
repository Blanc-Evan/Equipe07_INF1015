#pragma once
#include  "Afficheable.hpp"
#include <string>
#include <iostream>

class Personnage : public Afficheable {

public:
		Personnage() = default;

		Personnage(const std::string nom, const std::string premiereAppartion) : nom_(nom), titrePremiereApparition_(premiereAppartion) {}

		void setNom(const std::string nom) {
			this->nom_ = nom;
		}

		const std::string getNom() {
			return this->nom_;
		}

		void setTitrePremiereAppartition(const std::string premiereAppartion) {
			this->titrePremiereApparition_ = premiereAppartion;
		}

		const std::string getTitrePremiereApparition() {
			return this->titrePremiereApparition_;
		}

		void afficher() {
			std::cout << color_ << " nom: " << nom_ << std::endl << "titre premiere appartition : " << titrePremiereApparition_ << std::endl;
		}

		void changerCouleur(std::string couleur) {
			this->color_ = COLOR.find(couleur)->second;
		}

private:
	std::string nom_;
	std::string titrePremiereApparition_;
};

