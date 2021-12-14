#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Salle.hpp"
#include <iostream>

class ObjetInterractif
{
public:
	ObjetInterractif(const std::string& nom, const std::string& description, const std::string& action) : nom_(nom), description_(description), action_(action) {};
	void look() const;
	void use() const;
	void setSalleDansLaquelleLObjetSeTrouve(std::shared_ptr<Salle> s);

	std::string nom_;
	std::string description_;
	std::string action_;
	std::shared_ptr<Salle> salleDansLaquelleLObjetSeTrouve_;
};

class ObjetInterratifPourDeverouillerZone : public ObjetInterractif {
public:
	ObjetInterratifPourDeverouillerZone(const std::string & nom, const std::string & description, const std::shared_ptr<Salle> salleADeverouiller, const char& direction) : ObjetInterractif(nom, description, ""), salleADeverouiller_(salleADeverouiller), direction_(direction) {}

	void use();


private:
	std::shared_ptr<Salle> salleADeverouiller_;
	char direction_;
	bool used_ = false;
};

class ObjetInterratifPourDeverouillerObjet : public ObjetInterractif {
	ObjetInterratifPourDeverouillerObjet(const std::string & nom, const std::string & description, const std::shared_ptr<ObjetInterractif> objetADeverouiller) : ObjetInterractif(nom, description, ""), objetADeverouiller_(objetADeverouiller) {}

	void use();

private:
	std::shared_ptr<ObjetInterractif> objetADeverouiller_;
	bool used_ = false;
};