#pragma once
// La Vue-Controlleur pour la caisse enregistreuse.
// Par evan.blanc@polymtl.ca & ahmed.zghal@polymtml.ca

#include "Caisse.hpp"
#include "Item.hpp";
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <QString>
#include <qlistwidget.h>
#include <QLabel>
#include <qcheckbox.h>
#pragma pop()

class CaisseWindow : public QMainWindow {
	Q_OBJECT

public:
	CaisseWindow(QWidget* parent = nullptr);
	~CaisseWindow() override = default;

public slots:
	void setDescription(QString);
	void setPrix(QString);
	void setTaxable(bool);
	void ajouter();
	void retirer();
	void reset();
	void selectItem(QListWidgetItem*);

signals:
	void descriptionChanged(QString);
	void prixChanged(QString);
	void taxableChanged(bool);
	void ajouterPressed();
	void retirerPressed();
	void resetPressed();
	void itemClicked(QListWidgetItem*);

private:
	void actualiserListe();

	QString description_;
	QString prix_ = "0.0";
	bool taxable_ = true;

	QListWidget* listWidget;
	QLineEdit* descriptionEdit, * prixEdit;

	QCheckBox* taxableCheck;

	QPushButton* ajouterButton, * retirerButton, * resetButton;

	QLabel* descriptionLabel;
	QLabel* prixLabel;
	QLabel* taxableLabel;

	Item* selectedItem;
	Caisse caisse_;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
};