#pragma once
#include <string>
#include <map>
class Afficheable {

public:

	void afficher();

	void changerCouleur(std::string couleur);

protected:
	const std::map<std::string, std::string> COLOR{
	{"WHITE", "\033[30m"},
	{"RED", "\033[91m"},
	{"BLUE", "\033[94m"}
	};

	std::string color_ = "\033[0m";
};

