#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//TODO: un constructeur par d�faut et un constructeur param�tr�
	Jeu()=default;

	Jeu(const string titre, const unsigned anneeSortie, const string developpeur) {

		this->titre_ = titre;
		this->anneeSortie_ = anneeSortie;
		this->developpeur_ = developpeur;
	}

	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir acc�der � la liste de concepteurs.
	Liste<Concepteur> getListConcepteurs() const;
	//TODO: Votre m�thode pour trouver un concepteur selon un crit�re donn� par une lambda, en utilisant la m�thode de Liste.

private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> listeConcepteurs_;
};

Liste<Concepteur> Jeu::getListConcepteurs() const {
	return listeConcepteurs_;
}

