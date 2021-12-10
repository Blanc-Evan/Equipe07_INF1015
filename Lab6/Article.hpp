#pragma once
//La classe qui represente les produits que l'on manipule
#include <string>
#include <memory>
using namespace std;
class Article {

public:
	Article() = default;
	Article(const string desc, const string prix, const bool taxable);
	string getDescprition() const;
	string getPrix() const;
	bool isTaxable() const;
	bool operator==(Article& a);
private:
	string description_;
	string prix_;
	bool taxable_;
};
