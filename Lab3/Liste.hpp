#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"

template <typename T>
class Liste
{
public:
	
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste() = default;
	Liste(const unsigned capacite);
	Liste(const Liste& l);

	//TODO: Méthode pour ajouter un élément à la liste
	void ajouter(const T* element);

	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste
	void changerTaille(const unsigned nouvelleCapacite);
	//TODO: Méthode pour trouver une élément selon un critère (lambda).

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les éléments de la liste.

	std::unique_ptr<std::shared_ptr<T>[]> elements_;
};


template <typename T>
Liste<T>::Liste(const unsigned capacite) {
	this->nElements_ = 0;
	this->capacite_ = capacite;
	this->elements_ = make_unique<std::shared_ptr>();
}

template <typename T>
Liste<T>::Liste(const Liste& l) {
	this->nElements_ = l.nElements_;
	this->capacite_ = l.capacite_;
	this->elements_ = std::move(l.elements_);
}

template <typename T>
void Liste<T>::ajouter(const T* element) {
	if (this->nElements_ == this->capacite_) {
		changerTaille(max(1U, this->capacite * 2));
		this->elements_[this->nElements_++] = element;
	}
}

template <typename T>
void Liste<T>::changerTaille(const unsigned nouvelleCapacite) {
	assert(nouvelleCapacite >= this->nElements);
	std::unique_ptr<std::shared_ptr<T>> nouvelleListe = std::make_unique<std::shared_ptr[nouvelleCapacite]>();

	for (itn i : iter::range(this->nElements_)) {
		nouvelleListe[i] = this->elements_[i];
	}

	this->elements_ = nouvelleListe;
	this->capacite_ = nouvelleCapacite;
}