#pragma once
// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "Caisse.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <QString>
#include <qlistwidget.h>
#include <QLabel>
#pragma pop()

class CaisseWindow : public QMainWindow {
	Q_OBJECT

public:
	CaisseWindow(QWidget* parent = nullptr);
	~CaisseWindow() override = default;
	 
public slots:
	void setDescription(QString);
	void setPrix(float);
	void ajouter();
	void retirer();
	void reset();
	void selectItem(QListWidgetItem*);

signals:
	void descriptionChanged(QString);
	void prixChanged(float);
	void ajouterPressed();
	void retirerPressed();
	void resetPressed();
	void itemClicked(QListWidgetItem*);

private:
		QString description_;
		float prix_;

		QListWidget* listWidget;
		QLineEdit* descriptionEdit, * prixEdit;
	
	Caisse caisse_;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
};
