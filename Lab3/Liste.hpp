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
	//[DONE]
	//TODO: Constructeurs et surcharges d'op�rateurs
	Liste() = default;

	Liste(const unsigned capacite) {
		this->nElements_ = 0;
		this->capacite_ = capacite;
		this->elements_ = make_shared<std::shared_ptr<T>[capacite]>();
	}

	Liste(const Liste& l) {
		this->nElements_ = l.nElements_;
		this->capacite_ = l.capacite_;

		this->elements_ = std::make_shared<std::shared_ptr<T>[l.capacite_]>();

		for (unsigned i = 0; i < l.nElements_; i++) {
			this->elements_[i] = std::make_shared<T>(l.elements_[i]);
		}
	}

	//[DONE] mais � tester
	std::shared_ptr<T> operator[](const unsigned i) const{
		return this->elements_[i];
	}

	//[DONE]
	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouter(std::shared_ptr<T> element) {
		if (this->nElements_ == this->capacite_) {
			changerTaille(std::max(1U, this->capacite_ * 2));
			this->elements_[this->nElements_++] = element;
		}
	}

	//[DONE]
	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const { return nElements_; }
	unsigned getCapacite() const { return capacite_; }
	std::shared_ptr<std::shared_ptr<T>[]> getElements() const { return elements_; }

	//[DONE]
	//TODO: M�thode pour changer la capacit� de la liste
	void changerTaille(const unsigned nouvelleCapacite) {
		assert(nouvelleCapacite >= this->nElements_);
		std::shared_ptr<std::shared_ptr<T>[]> nouvelleListe = std::make_shared<std::shared_ptr<T>[nouvelleCapacite]>();

		for (unsigned i = 0; i < this->nElements_; i++) {
			nouvelleListe[i] = std::make_shared<T>(this->elements_[i]);
		}

		this->elements_ = nouvelleListe;
		this->capacite_ = nouvelleCapacite;
	}
	//[DONE]
	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).

	std::shared_ptr<T> trouverSi(const std::function<bool(const T&)> critere) {

		for (int i : iter::range(this->nElements_)) {
			if (critere(elements_[i]))
				return std::make_shared<T>(elements_[i]);
		}
		return nullptr;
	}

private:
	unsigned nElements_;
	unsigned capacite_;
	//[DONE]
	//TODO: Attribut contenant les �l�ments de la liste.
	std::shared_ptr<std::shared_ptr<T>[]> elements_;
};