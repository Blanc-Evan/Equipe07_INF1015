#include "Article.hpp"

Article::Article(const string desc, const string prix, const bool taxable) {
	this->description_ = desc;
	this->prix_ = prix;
	this->taxable_ = taxable;
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