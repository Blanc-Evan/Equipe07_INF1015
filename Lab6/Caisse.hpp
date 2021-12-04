// La Vue-Controlleur pour la caisse enregistreuse.
// Par evan.blanc@polymtl.ca & ahmed.zghal@polymtml.ca
#pragma once

#pragma warning(push, 0)
#pragma pop()
#include <QObject>
#include <functional>
#include <vector>
#include "Item.hpp"
#include <iostream>


using namespace std;

class Caisse : public QObject {
public:
	void addItem(Item* item);
	std::list<Item*>& getList();
	void removeItem(Item* item);
	void resetList();

private:
	std::list<Item*> list;

};