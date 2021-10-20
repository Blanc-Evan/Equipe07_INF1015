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

	Liste(const unsigned capacite) {
		this->nElements_ = 0;
		this->capacite_ = capacite;
		this->elements_ = make_unique<std::shared_ptr>();
	}

	Liste(const Liste& l) {
		this->nElements_ = l.nElements_;
		this->capacite_ = l.capacite_;
		this->elements_ = std::move(l.elements_);
	}

	//TODO: Méthode pour ajouter un élément à la liste
	void ajouter(std::shared_ptr element) {
		if (this->nElements_ == this->capacite_) {
			changerTaille(max(1U, this->capacite * 2));
			this->elements_[this->nElements_++] = element;
		}
	}

	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const { return nElements_; }
	unsigned getCapacite() const { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste
	void changerTaille(const unsigned nouvelleCapacite) {
		assert(nouvelleCapacite >= this->nElements);
		std::unique_ptr<std::shared_ptr<T>> nouvelleListe = std::make_unique<std::shared_ptr[nouvelleCapacite]>();

		for (itn i : iter::range(this->nElements_)) {
			nouvelleListe[i] = this->elements_[i];
		}

		this->elements_ = nouvelleListe;
		this->capacite_ = nouvelleCapacite;
	}

	//TODO: Méthode pour trouver une élément selon un critère (lambda).
	template <typename U>
	std::shared_ptr trouverSi(const std::function<bool(U)> critere) const {
		for (const auto&& element : span<this->elements_, this->nElements_>)) {
			if (critere(element))
				return elements_
		}
		return nullptr;
	}

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les éléments de la liste.
	std::unique_ptr<std::shared_ptr<T>[]> elements_;
};