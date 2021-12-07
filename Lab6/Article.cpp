#include "Article.hpp"

Article::Article(string desc, string prix) {
	this->description_ = desc;
	this->prix_ = prix;
}

string Article::getDescprition() {
	return this->description_;
}

string Article::getPrix() {
	return this->prix_;
}
