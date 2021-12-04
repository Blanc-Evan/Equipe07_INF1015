#pragma once
//La classe qui represente les produits que l'on manipule
#include <string>

using namespace std;
class Item {

public:
	Item() = default;
	Item(string desc, float prix) {
		this->description_ = desc;
		this->prix_ = prix;
	}

	string getDescprition();
	float getPrix();

private:
	string description_;
	float prix_;
};
