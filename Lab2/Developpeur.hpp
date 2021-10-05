#pragma once
#include <string>
#include "ListeJeux.hpp"
#include "Jeu.hpp"
#include "cppitertools/range.hpp"
using namespace std;

class Developpeur
{
	//TODO: En faire une classe qui suit les principes OO.
	//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
	//TODO: Les méthodes à faire...

public:
	Developpeur(const string& nom);
	const string& getName();
	const int howManyGamesDidHeParticipatesToInList(const ListeJeux& l);

private:
	pair<std::string, ListeJeux> paireNomJeux_;



	Developpeur(const string& nom = "unknown") {

		this->paireNomJeux_.first = nom;
		
		ListeJeux* l = new ListeJeux();
		l->capacite = 1;
		l->nElements = 0;
		l->elements = new Jeu*;
		
		this->paireNomJeux_.second = *l;
	}

	const string& getName() const {

		return this->paireNomJeux_.first;
	}

	const int howManyGamesDidHeParticipatesToInList(const ListeJeux& l) const {

		int n = 0;
		for (int i : iter::range(l.nElements)) {
			if (l.elements[i]->developpeur == this->getName()) {
				n++;
			}
		}
		return n;
	}
};
