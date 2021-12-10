#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Objet.hpp"

using namespace std;

class Salle
{
public:
	Salle() = default;
	Salle(const string& nom, const string& description) : 
		nom_(nom),
		description_(description)
	{};
	void setDirections(const shared_ptr<Salle> nord, const shared_ptr<Salle> est, const shared_ptr<Salle> sud, const shared_ptr<Salle> ouest);
	
	string getNom() const;
	string getDescription() const;
	shared_ptr<Salle> getDirection(const char& direction) const;
	string look() const;

private:
	string nom_;
	string description_;
	map<char, shared_ptr<Salle>> directions;
	vector <shared_ptr<Objet>>objets;
};