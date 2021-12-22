#include "Objet.hpp"

std::string ObjetInterractif::look() const
{
	return description_;
}


std::pair<std::string, std::pair<std::string, char>> ObjetInterractif::use() const
{
	std::cout << action_ << std::endl;
	return std::make_pair("", std::make_pair("", ' ')); // dans ce cas, pas besoin de retour, mais pour automatiser, toutes les fct use doivent renvoyer la meme chose
}


std::pair <std::string, std::pair<std::string, char>> ObjetInterractifPourDeverouillerZone::use() const
{
	if (!used_) {
		std::cout << salleADeverouiller_.first + " est apparu " << std::endl;
		// Pair < nom de la salleOuSeDerouleLaction, Pair < nom de la salle a deverouiller, direction >
		return std::make_pair(getSalleOuSeDerouleLaction(), std::make_pair(salleADeverouiller_.first, salleADeverouiller_.second));

	}
	else {
		std::cout << getAction() << std::endl;
	}
	return std::make_pair("", std::make_pair("",' '));
}


std::pair <std::string, std::pair<std::string, char>> ObjetInterractifPourDeverouillerObjet::use() const
{
	if (!used_) {
		std::cout << objetADeverouiller_->getNom() + " est apparu " << std::endl;
	}
	else {
		std::cout << getAction() << std::endl;
	}
	return std::make_pair(getSalleOuSeDerouleLaction(), std::make_pair(objetADeverouiller_->getNom(), ' '));
}

void ObjetInterractif::setMotCles(const std::string& motsCles) {
	std::string mots = motsCles;
	do {
		std::string mot = mots.substr(0, mots.find(','));
		mots.replace(0, mots.find(',') + 1, "");
		this->motsCles_.push_back(mot);
	} while (mots.contains(','));

	this->motsCles_.push_back(motsCles);
}