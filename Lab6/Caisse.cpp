#include "Caisse.hpp"

void Caisse::addArticle(Article* item) {
	list.push_back(item);
	cout << "item added :" + item->getDescprition() << endl;
}

std::list<Article*>& Caisse::getList() {
	return list;
}

void Caisse::removeArticle(Article* item) {
	for (auto&& i : list) {
		list.remove_if([&](bool b) {return item->getDescprition() == i->getDescprition(); });
	}
}

void Caisse::resetList() {
	list.clear();
}
