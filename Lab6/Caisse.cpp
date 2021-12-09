#include "Caisse.hpp"

void Caisse::addArticle(shared_ptr<Article> item) {
	list.push_back(item);
	cout << "item added :" + item->getDescprition() << endl;
}

std::list<shared_ptr<Article>>& Caisse::getList(){
	return list;
}

void Caisse::removeArticle(shared_ptr<Article> item) {
	for (auto&& i : list) {
		if (item->getDescprition() == i->getDescprition()) {
			list.remove(i);
			return;
		}
	}
}

void Caisse::resetList() {
	list.clear();
}

void Caisse::calculerPrix() {
	tablePrix[0] = 0.00;
	tablePrix[1] = 0.00;
	tablePrix[2] = 0.00;

	for (auto&& i : list) {
		float prix = stof(i->getPrix());
		if (i->isTaxable()) {
			tablePrix[1] += 14.975 * 0.01 * prix;
		}
		tablePrix[0] += prix;
		tablePrix[2] = tablePrix[0] + tablePrix[1];
	}
	
}

string Caisse::getPrix(const int i) const {
	return to_string(tablePrix[i]);
}