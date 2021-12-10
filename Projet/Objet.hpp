#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Objet.hpp"
class Objet
{
public:
	Objet() = default;
	Objet(const string& nom, const string& description) :nom_(nom), description_(description){};
	void look() const;
	void use() const;
private:
	string nom_;
	string description_;
};

