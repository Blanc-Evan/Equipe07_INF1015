#include "Objet.hpp"

void ObjetInterractif::look() const
{
	std::cout << description_ << std::endl;
}

void ObjetInterractif::use() const
{
	std::cout << action_ << std::endl;
}


void ObjetInterratifPourDeverouillerZone::use()
{
}

void ObjetInterratifPourDeverouillerObjet::use()
{
	if (!used_) {
		std::cout << objetADeverouiller_->nom_ + " est apparu " << std::endl;
			}
	else {
		std::cout << action_ << std::endl;
	}
}