#pragma once
// La Vue-Controlleur pour la caisse enregistreuse.
// Par evan.blanc@polymtl.ca & ahmed.zgahl@polymtml.ca

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
	void setPrix(float);
	void setTaxable(bool);
	void ajouter();
	void retirer();
	void reset();
	void selectItem(QListWidgetItem*);

signals:
	void descriptionChanged(QString);
	void prixChanged(float);
	void taxableChanged(bool);
	void ajouterPressed();
	void retirerPressed();
	void resetPressed();
	void itemClicked(QListWidgetItem*);

private:
		QString description_;
		float prix_ = 0.0;
		bool taxable_ = true;

		QListWidget* listWidget;
		QLineEdit* descriptionEdit, * prixEdit;
		
		QLabel* descriptionLabel;
		QLabel* prixLabel;
		QLabel* taxableLabel;

	Item* selectedItem;
	Caisse caisse_;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
};
