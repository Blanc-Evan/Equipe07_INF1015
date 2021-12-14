#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Objet.hpp"

class Salle
{
public:
	Salle() = default;
	Salle(const std::string& nom, const std::string& description) :
		nom_(nom),
		description_(description)
	{};
	void setDirections(const std::shared_ptr<Salle> nord, const std::shared_ptr<Salle> est, const std::shared_ptr<Salle> sud, const std::shared_ptr<Salle> ouest);
	void setDirection(const char& direction, const std::shared_ptr<Salle> s);
	void ajouterObjet(std::shared_ptr<ObjetInterractif> objet);
	
	std::string getNom() const;
	std::string getDescription() const;
	std::shared_ptr<Salle> getDirection(const char& direction) const;
	std::string look() const;

private:
	std::string nom_;
	std::string description_;
	std::map<char, std::shared_ptr<Salle>> directions_;
	std::vector <std::shared_ptr<ObjetInterractif>>objets_;
};