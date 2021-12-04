#include "Caisse.hpp"

void Caisse::addItem(Item* item) {
	list.push_back(item);
	cout << "item added :" + item->getDescprition();
}

std::list<Item*>& Caisse::getList() {
	return list;
}

void Caisse::removeItem(Item* item) {
	for (auto&& i : list) {
		list.remove_if([&]() {return item->getDescprition() == i->getDescprition(); });
	}
}

void Caisse::resetList() {
	list.clear();
}
