#pragma once
// La Vue-Controlleur pour la caisse enregistreuse.
// Par evan.blanc@polymtl.ca & ahmed.zghal@polymtml.ca
// PS, on a rajouté quelques vérifications supplémentaires afin qu'il y est le moins de bug possible.

#include "Caisse.hpp"
#include "Article.hpp";
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

signals:
	void descriptionChanged(QString);
	void prixChanged(QString);
	void taxableChanged(bool);
	void ajouterPressed();
	void retirerPressed();
	void resetPressed();
	void itemClicked(QList<QListWidgetItem*>);

private:
	void actualiserVue();

	QString description_;
	QString prix_;
	bool taxable_ = true;

	QListWidget* listWidget;
	QLineEdit* descriptionEdit, * prixEdit, * totalAvanTaxeEdit, *  totalTaxeEdit, * totalEdit;

	QCheckBox* taxableCheck;

	QPushButton* ajouterButton, * retirerButton, * resetButton;

	QLabel* descriptionLabel;
	QLabel* prixLabel;
	QLabel* taxableLabel;
	QLabel* totalAvanTaxeLabel;
	QLabel* totalTaxeLabel;
	QLabel* totalLabel;

	shared_ptr<Article> selectedArticle;
	Caisse caisse_;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
};

class NotCorrectlyFilledField : public logic_error {
public:
	using logic_error::logic_error;
};

class ArticleNotSelected : public logic_error {
public:
	using logic_error::logic_error;
};