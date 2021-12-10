#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Salle.hpp"
#include <iostream>
using namespace std;
class Game
{
public:
	Game() = default;
	void initialize();
	void start();
	string play();
private:
	shared_ptr<Salle> salleActuelle;
	bool verification(const string& str);
	vector<shared_ptr<Salle>> salles;
};

