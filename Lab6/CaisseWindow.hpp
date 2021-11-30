#pragma once
// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "Caisse.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <QString>
#include <QLabel>
#pragma pop()

class CaisseWindow : public QMainWindow {
	Q_OBJECT

public:
	CaisseWindow(QWidget* parent = nullptr);
	~CaisseWindow() override = default;

public slots:
	void setDescription(QString description);
	void setPrix(float prix);
	void ajouter();
	void retirer();
	void reset();

signals:
	void descriptionChanged(QString newDescription);
	void prixChanged(float newPrix);
	void ajouterPressed();
	void retirerPressed();
	void resetPressed();

private:
		QString description_;
		float prix_;
	
	Caisse caisse_;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
};
