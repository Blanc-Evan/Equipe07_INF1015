#include "Article.hpp"
#include <iostream>

Article::Article(const string desc, const string prix, const bool taxable) {
	this->description_ = desc;
	this->prix_ = prix;
	this->taxable_ = taxable;
}

bool Article::operator==(Article& a) {
	return this->description_ == a.description_;
}

string Article::getDescprition() const {
	return this->description_;
}

string Article::getPrix() const {
	return this->prix_;
}

bool Article::isTaxable() const {
	return this->taxable_;
}