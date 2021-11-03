#pragma once
#include "Heros.hpp"
#include "Vilain.hpp"
#include <string>

class VilainHeros :  Vilain, Heros
{

public:
	VilainHeros() = default;

	VilainHeros(const std::string nomV, const std::string premiereApparitionV,
				const std::string nomH, const std::string premiereApparitionH,
				const std::string objectif, const std::string ennemi
	) : Vilain(nomV, premiereApparitionV, objectif), Heros(nomH, premiereApparitionH, ennemi) {}

	VilainHeros(const VilainHeros& vh) : Personnage(vh.Personnage::nom_, vh.Personnage::titrePremiereApparition_),
		Vilain(vh.Vilain::nom_, vh.Vilain::titrePremiereApparition_, vh.Vilain::objectif_),
		Heros(vh.Heros::nom_, vh.Heros::titrePremiereApparition_, vh.Heros::ennemi_),
		nom_(vh.Vilain::nom_ + "-" + vh.Heros::nom_),
		titrePremiereAppartition_(vh.Vilain::titrePremiereApparition_ + "-" + vh.Heros::titrePremiereApparition_),
		missionSpeciale_(vh.Vilain::objectif_ + " dans le monde de " + vh.Heros::titrePremiereApparition_) {}


	void afficher() {
		std::cout << color_ << " nom: " << nom_ << std::endl << "titre premiere appartition : " << titrePremiereApparition_ << std::endl << "Ennemi : " << ennemi_ << std::endl;

		for (auto allie : allies_) {
			std::cout << color_ << allie << std::endl;
		}
	}

	void changerCouleur(std::string couleur) {
		Vilain::changerCouleur(couleur);
		Heros::changerCouleur(couleur);
	}

private:
	std::string nom_;
	std::string titrePremiereAppartition_;
	std::string missionSpeciale_;

};

