#pragma once
#include <string>
#include <map>
class Afficheable {

public:

	virtual void afficher();

	virtual void changerCouleur(std::string couleur);

protected:
	const std::map<std::string, std::string> COLOR{
	{"BLACK", "\033[30m"},
	{"RED", "\033[91m"},
	{"BLUE", "\033[94m"}
	};

	std::string color_ = "\033[30m";
};

