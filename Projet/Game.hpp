#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Salle.hpp"
#include <iostream>

class Game
{
public:
	Game() = default;
	void initialize();
	void start();
	std::string commande = "";
	std::string play();
	void execute();

private:
	std::shared_ptr<Salle> salleActuelle_;
	bool verification(const std::string& str);
	std::vector<std::shared_ptr<Salle>> salles_;
	std::string commande_ = "";
};

