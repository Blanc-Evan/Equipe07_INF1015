#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <ranges>
#include <string_view>

class ObjetInterractif
{
public:
	ObjetInterractif(const std::string& nom, const std::string& description, const std::string& action, const std::string& salleOuSeDerouleLaction) :
		nom_(nom),
		description_(description),
		action_(action),
		salleOuSeDerouleLaction_(salleOuSeDerouleLaction)
	{};

	virtual std::string look() const;
	virtual std::pair < std::string, std::pair<std::string, char>> use() const;
	void setMotCles(const std::string& motsCles);
	
	std::string getNom() const { return nom_; }
	std::string getDescription() const { return description_; }
	std::string getAction() const { return action_; }
	std::vector<std::string>& getMotCles() { return motsCles_ ;}
	std::string getSalleOuSeDerouleLaction() const { return salleOuSeDerouleLaction_; }

private:
	std::string nom_;
	std::string description_;
	std::string action_;
	std::string salleOuSeDerouleLaction_;
	std::vector<std::string> motsCles_;
};

class ObjetInterractifPourDeverouillerZone : public ObjetInterractif {
public:
	ObjetInterractifPourDeverouillerZone(const std::string& nom, const std::string& description, const std::string& action, const std::pair<std::string, char>& salleADeverouiller, const std::string& salleOuSeDerouleLaction) :
		ObjetInterractif(nom, description, action, salleOuSeDerouleLaction),
		salleADeverouiller_(salleADeverouiller)
	{}
	std::pair < std::string, std::pair<std::string, char>> use() const;
private:
	std::pair<std::string, char> salleADeverouiller_;
	bool used_ = false;
};

class ObjetInterractifPourDeverouillerObjet : public ObjetInterractif {
public:
	ObjetInterractifPourDeverouillerObjet(const std::string& nom, const std::string& description, const std::string& action, const std::shared_ptr<ObjetInterractif> objetADeverouiller, const std::string& salleOuSeDerouleLaction) :
		ObjetInterractif(nom, description, action, salleOuSeDerouleLaction),
		objetADeverouiller_(objetADeverouiller)
	{}
	std::pair < std::string, std::pair<std::string, char>> use() const;
private:
	std::shared_ptr<ObjetInterractif> objetADeverouiller_;
	bool used_ = false;
};