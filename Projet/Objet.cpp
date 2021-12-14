#include "Objet.hpp"

void ObjetInterractif::look() const
{
	std::cout << description_ << std::endl;
}

void ObjetInterractif::use() const
{
	std::cout << action_ << std::endl;
}

void ObjetInterractif::setSalleDansLaquelleLObjetSeTrouve(std::shared_ptr<Salle> s)
{
	salleDansLaquelleLObjetSeTrouve_ = s;

}

void ObjetInterratifPourDeverouillerZone::use()
{
	salleDansLaquelleLObjetSeTrouve_->setDirection(std::toupper(direction_), salleADeverouiller_);
}

void ObjetInterratifPourDeverouillerObjet::use()
{
	if (!used_) {
		std::cout << objetADeverouiller_->nom_ + " est apparu " << std::endl;
		salleDansLaquelleLObjetSeTrouve_->ajouterObjet(objetADeverouiller_);
	}
	else {
		std::cout << action_ << std::endl;
	}
}
