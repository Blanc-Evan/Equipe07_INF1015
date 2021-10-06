#pragma once
#include "Developpeur.hpp"
#include <string>
#include <iostream>
#include "cppitertools/range.hpp"

class ListeDeveloppeurs
{
	//TODO: En faire une classe qui suit les principes OO.
	//TODO: On veut pouvoir ajouter et enlever un Developpeur* de la liste, avec réallocation dynamique tel que faite pour ListeJeux.
	//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
public:
	ListeDeveloppeurs();
	~ListeDeveloppeurs();
	void print() const;
	void addDeveloppeur(Developpeur& d);
	void removeDeveloppeur(Developpeur& d);

private:
	unsigned nElements;
	unsigned capacite;
	Developpeur** elements;
	void augmenterTaille(int newCapacity);
};


ListeDeveloppeurs::ListeDeveloppeurs() {

	this->nElements = 0;
	this->capacite = 1;
	this->elements = new Developpeur*;
}


void ListeDeveloppeurs::augmenterTaille(int newCapacity) {

	if (newCapacity != 0) {
		this->capacite = newCapacity;
		Developpeur** temp = new Developpeur * [this->capacite];
		for (auto i : iter::range(this->nElements)) {
			temp[i] = this->elements[i];
			delete[] this->elements[i];
		}
		this->elements = temp;
	}
}


void ListeDeveloppeurs::print() const {

	for (int i : iter::range(this->nElements)) {
		cout << "nom: " <<  this->elements[i]->getName() << endl;
		this->elements[i]->print();
	}
}


void ListeDeveloppeurs::addDeveloppeur(Developpeur& d) {

	if (&d != nullptr) {
		if (this->nElements >= this->capacite) {
			this->augmenterTaille()
		}
		this->elements[nElements] = &d;
		this->nElements++;
	}
}


void ListeDeveloppeurs::removeDeveloppeur(Developpeur& d) {

	for (int i : iter::range(this->nElements)) {
		if (this->elements[i] == &d) {
			delete this->elements[i];
		}
	}
}