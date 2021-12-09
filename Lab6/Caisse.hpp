// La Vue-Controlleur pour la caisse enregistreuse.
// Par evan.blanc@polymtl.ca & ahmed.zghal@polymtml.ca
#pragma once

#pragma warning(push, 0)
#pragma pop()
#include <QObject>
#include <functional>
#include <vector>
#include "Article.hpp"
#include <iostream>


using namespace std;

class Caisse : public QObject {
public slots:
	void addArticle(shared_ptr<Article> item);
	std::list<shared_ptr<Article>>& getList();
	void removeArticle(shared_ptr<Article> item);
	void resetList();
	void calculerPrix();
	string getPrix(const int i) const;

private:
	//nous avons privilégié la list pour ca fonction remove_if (Q2 du modèle)
	std::list<shared_ptr<Article>> list;

	// 0:totalAvantTaxe 1:totalDesTaxes 2:totalAPayer
	float tablePrix[3] = { 0.00, 0.00, 0.00 };
};