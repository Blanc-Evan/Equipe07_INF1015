#pragma once
#include <string>
#include "ListeJeux.hpp"
#include "Jeu.hpp"
#include <iostream>
#include "cppitertools/range.hpp"
using namespace std;

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
	//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
	//TODO: Les méthodes à faire...

public:
	Developpeur(const string& nom);
	~Developpeur();
	const string& getName() const;
	const int howManyGamesDidHeParticipatesToInList(const ListeJeux& l) const;
	void updateListeJeux(ListeJeux& l);
	void printGames() const;

private:
	pair<std::string, ListeJeux> paireNomJeux_;
	void augmenterTaille(ListeJeux& l, int newCapacity) const;
};


Developpeur::Developpeur::Developpeur(const string& nom = "unknown") {

	this->paireNomJeux_.first = nom;

	ListeJeux* l = new ListeJeux();
	l->capacite = 1;
	l->nElements = 0;
	l->elements = new Jeu*;

	this->paireNomJeux_.second = *l;
}


const string& Developpeur::getName() const {

	return this->paireNomJeux_.first;
}


const int Developpeur::howManyGamesDidHeParticipatesToInList(const ListeJeux& l) const {

	int n = 0;
	for (int i : iter::range(l.nElements)) {
		if (l.elements[i]->developpeur == this->getName()) {
			n++;
		}
	}
	return n;
}


void Developpeur::updateListeJeux(ListeJeux& l) {

	const int i = this->howManyGamesDidHeParticipatesToInList(l);

	if (this->paireNomJeux_.second.capacite <= this->paireNomJeux_.second.capacite + i) {
		augmenterTaille(this->paireNomJeux_.second, i);
	}

	for (int j : iter::range(l.nElements)) {
		if (l.elements[j]->developpeur == this->getName()) {
			this->paireNomJeux_.second.elements[j] = l.elements[j];
		}
	}
}


void Developpeur::augmenterTaille(ListeJeux& l, int newCapacity) const {

	if (newCapacity > l.capacite) { // si la capacite choisie n'est pas correcte
		newCapacity = 1;
	}
	l.capacite = newCapacity;
	Jeu** temp = new Jeu * [l.capacite];
	for (auto i : iter::range(l.nElements)) {
		temp[i] = l.elements[i];
		delete[] l.elements[i];
	}
	delete l.elements;
	l.elements = temp;

}


void Developpeur::printGames() const {

	for (int i : iter::range(this->paireNomJeux_.second.nElements)) {
		cout << this->paireNomJeux_.second.elements[i]->titre + "\n";
	}
}


Developpeur::~Developpeur() {

	delete[] this->paireNomJeux_.second.elements;
	this->paireNomJeux_.second.elements = 0;
	delete& this->paireNomJeux_.second;
}