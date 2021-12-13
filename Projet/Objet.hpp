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
	Objet(const std::string& nom, const std::string& description) :nom_(nom), description_(description){};
	void look() const;
	void use() const;
private:
	std::string nom_;
	std::string description_;
};

