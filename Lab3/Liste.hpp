#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"

using namespace std;

template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste() {
		this->nElements_ = 0;
		this->capacite_ = 0;
		this->elements_ = make_unique<make_shared<T>()>();
	}

	Liste(unsigned capacite) {
		this->nElements_ = 0;
		this->capacite_ = 0;
		this->elements_ = make_unique<make_shared<T>()>();
	}

	Liste(unsigned nElements, unsigned capacite, unique_ptr<shared_ptr<T>> elements) {
		this->nElements_ = nElements;
		this->capacite_ = capacite;
		this->elements_ = move(elements);
	}
	//TODO: Méthode pour ajouter un élément à la liste

	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste

	//TODO: Méthode pour trouver une élément selon un critère (lambda).

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les éléments de la liste.
	unique_ptr<shared_ptr<T>> elements_;
};
