#pragma once
//La classe qui represente les produits que l'on manipule
#include <QString>

class Item {

public:
	Item() = default;
	Item(QString desc, float prix);
	QString getDescprition();
	float getPrix();

private:
	QString description_;
	float prix_;
};
