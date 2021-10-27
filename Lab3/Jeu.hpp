#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//TODO: un constructeur par défaut et un constructeur paramétré
	Jeu()=default;

	Jeu(const std::string titre, const unsigned anneeSortie, const std::string developpeur) {

		this->titre_ = titre;
		this->anneeSortie_ = anneeSortie;
		this->developpeur_ = developpeur;
	}

	Jeu(const Jeu& j) : Jeu(j.titre_, j.anneeSortie_, j.developpeur_) {};
	
	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	// [DONE]
	//TODO: Pouvoir accéder à la liste de concepteurs.
	Liste<Concepteur> getListConcepteurs() const {
		return listeConcepteurs_;
	}

	//[DONE]
	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	
	std::shared_ptr<Concepteur> trouverConcepteur(const std::function<bool(Concepteur)> critere) {
		return this->listeConcepteurs_.trouverSi(critere);
	}

private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//[DONE]
	//TODO: Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> listeConcepteurs_;
};