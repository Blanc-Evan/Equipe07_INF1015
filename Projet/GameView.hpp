#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Salle.hpp"
#include <iostream>
#include <functional>
#include "GameController.hpp"

class GameView
{
public:
	GameView(std::unique_ptr<GameController> controller) :
		controller_(move(controller)) 
	{ initialize(); };
	void initialize();
	std::string play();
	void execute(std::string str);

private:
	bool verification(const std::string& str);
	std::unique_ptr<GameController> controller_;

};


