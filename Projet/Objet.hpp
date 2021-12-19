#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <iostream>

class ObjetInterractif
{
public:
	ObjetInterractif(const std::string& nom, const std::string& description, const std::string& action) : nom_(nom), description_(description), action_(action) {};
	void look() const;
	void use() const;
	
	std::string nom_;
	std::string description_;
	std::string action_;

};

class ObjetInterratifPourDeverouillerZone : public ObjetInterractif {
public:
	ObjetInterratifPourDeverouillerZone(const std::string& nom, const std::string& description, const char& direction) : ObjetInterractif(nom, description, ""), direction_(direction) {}

	void use();


private:
	char direction_;
	bool used_ = false;
};

class ObjetInterratifPourDeverouillerObjet : public ObjetInterractif {
	ObjetInterratifPourDeverouillerObjet(const std::string& nom, const std::string& description, const std::shared_ptr<ObjetInterractif> objetADeverouiller) : ObjetInterractif(nom, description, ""), objetADeverouiller_(objetADeverouiller) {}

	void use();

private:
	std::shared_ptr<ObjetInterractif> objetADeverouiller_;
	bool used_ = false;
};