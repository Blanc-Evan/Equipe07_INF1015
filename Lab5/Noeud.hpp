#pragma once
#include <gsl/pointers>
template<typename T> class ListeLiee;
template<typename T> class Iterateur;
template<typename T>
class Noeud
{
public:
	//TODO: Constructeur(s).
	Noeud() = default;

	Noeud(const T& obj) {
		this->donnee_ = obj;
	}

private:
	//TODO: Attributs d'un noeud.
	Noeud* next_ = past_end;
	Noeud* previous_ = past_end;
	T donnee_ ;

	inline static constexpr Noeud* past_end = nullptr;
	friend class ListeLiee<T>;
	friend class Iterateur<T>;
};