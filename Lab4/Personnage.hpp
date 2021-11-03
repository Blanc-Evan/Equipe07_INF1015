#pragma once
#include  "Afficheable.hpp"
#include <string>
#include <iostream>

class Personnage : public Afficheable {

public:
		Personnage() = default;

		Personnage(const std::string nom, const std::string parution) :
			nom_(nom),
			parution_(parution)
		{}

		void setNom(const std::string nom) {
			this->nom_ = nom;
		}

		const std::string getNom() {
			return this->nom_;
		}

		void setParution(const std::string parution) {
			this->parution_ = parution;
		}

		const std::string getParution() {
			return this->parution_;
		}

		void afficher() {
			std::cout << color_ << " nom: " << nom_ << std::endl << " Parution : " << parution_ << std::endl;
		}

		void changerCouleur(std::string couleur) {
			this->color_ = COLOR.find(couleur)->second;
		}

protected:
	std::string nom_;
	std::string parution_;
};

