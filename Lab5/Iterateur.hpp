#pragma once
#include "noeud.hpp"
#include "gsl/gsl_assert"
template<typename T>
class Iterateur
{
public:
	//TODO: Constructeur(s).
	Iterateur(Noeud<T>* position = Noeud<T>::past_end) : position_(position) {}

	void avancer()	{
		Expects(position_ != nullptr);
		position_ = position_->next_;
	}
	void reculer()	{
		//NOTE: On ne demande pas de supporter de reculer à partir de l'itérateur end().
		Expects(position_ != nullptr);
		position_ = position_->previous_;
	}

	T& operator*()	{
		return position_->donnee_;
	}
	//TODO: Ajouter ce qu'il manque pour que les boucles sur intervalles fonctionnent sur une ListeLiee.
	bool operator==(const Iterateur<T>& it) const = default;

private:
	Noeud<T>* position_;
	friend class ListeLiee<T>;
};
