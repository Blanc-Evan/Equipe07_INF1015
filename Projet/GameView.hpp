#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Salle.hpp"
#include <iostream>
#include "Objet.hpp"
#include <functional>
#include "GameController.hpp"

class GameView
{
public:
	GameView(std::unique_ptr<GameController> controller) : controller_(move(controller)) { initialize(); };
	void initialize();
	std::string commande = "";
	std::string play();
	void execute();

private:
	bool verification(const std::string& str);
	std::vector<std::shared_ptr<Salle>> salles_;
	std::string commande_ = "";
	std::unique_ptr<GameController> controller_;

};


