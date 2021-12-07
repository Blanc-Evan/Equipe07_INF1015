#pragma once
//La classe qui represente les produits que l'on manipule
#include <string>

using namespace std;
class Article {

public:
	Article() = default;
	Article(string desc, string prix);
	string getDescprition();
	string getPrix();

private:
	string description_;
	string prix_;
};
