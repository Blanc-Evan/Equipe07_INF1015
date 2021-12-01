// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "CaisseWindow.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <qlistwidget.h>
#include <QLabel>
#include <QString>
#include <QVariant>
#pragma pop()
#include <iostream>
#include <type_traits>
#include <cppitertools/range.hpp>

using iter::range;

CaisseWindow::CaisseWindow(QWidget* parent) :

	QMainWindow(parent)
{
	// Si on objet n'a pas encore de parent on lui met "this" comme parent en attendant, si possible, pour s'assurer que tous les pointeurs sont gérés par un delete automatique en tout temps sans utiliser de unique_ptr.
	auto widgetPrincipal = new QWidget(this);
	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);  // Donner un parent à un layout est comme un setLayout.
	
	auto layout = new QHBoxLayout(); // Pas possible de donner directement le parent au layout (le constructeur prend un QWidget* et un layout n'en est pas un; on ne peut pas mettre un parent qui a déjà un layout; si on met on parent temporaire, addLayout n'accepte pas de changer le parent).
	layoutPrincipal->addLayout(layout);

	layout->setSpacing(10);

	QLabel* descriptionLabel = new QLabel;
	descriptionLabel->setText("Description:");

	descriptionEdit = new QLineEdit(this);
	descriptionEdit->setPlaceholderText("Description");
	descriptionEdit->setFixedSize(400, 50);
	descriptionEdit->setFocus();

	QHBoxLayout* descriptionLayout = new QHBoxLayout;
	descriptionLayout->addWidget(descriptionLabel);
	descriptionLayout->addWidget(descriptionEdit);

	QLabel* prixLabel = new QLabel;
	prixLabel->setText("Prix:");

	prixEdit = new QLineEdit(this);
	prixEdit->setPlaceholderText("Prix");
	prixEdit->setFixedSize(400, 50);
	prixEdit->setFocus();

	QHBoxLayout* prixLayout = new QHBoxLayout;
	prixLayout->addWidget(prixLabel);
	prixLayout->addWidget(prixEdit);

	QObject::connect(descriptionEdit, SIGNAL(descriptionChanged(QString)), &caisse_, SLOT(setDescription(QString)));
	QObject::connect(prixEdit, SIGNAL(prixChanged(float)), &caisse_, SLOT(setPrix(float)));


	// @brief QPushButton for ajouter, retier et rest
	QPushButton* ajouterButton, * retirerButton, * resetButton;
	QHBoxLayout* buttonLayout = new QHBoxLayout;

	ajouterButton = new QPushButton(this);
	ajouterButton->setText("AJOUTER");
	connect(ajouterButton, SIGNAL(ajouterPressed), &caisse_, SLOT(ajouter()));

	retirerButton = new QPushButton(this);
	retirerButton->setText("RETIRER");
	retirerButton->setDisabled(true);
	connect(retirerButton, SIGNAL(retirerPressed), &caisse_, SLOT(retirer()));
	
	resetButton = new QPushButton(this);
	resetButton->setText("RESET");
	resetButton->setDisabled(true);
	connect(resetButton, SIGNAL(resetPressed), &caisse_, SLOT(reset()));

	buttonLayout->addWidget(ajouterButton);
	buttonLayout->addWidget(retirerButton);
	buttonLayout->addWidget(resetButton);

	QVBoxLayout* listLayout = new QVBoxLayout;
	QLabel* listLabel = new QLabel;
	listLabel->setText("Liste des éléments");
	listLayout->addWidget(listLabel);
	listWidget = new QListWidget;
	listWidget->setSortingEnabled(true);
	connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(selectItem(QListWidgetItem*)));
	listLayout->addWidget(listWidget);
	listLayout->addLayout(buttonLayout);

	layoutPrincipal->addLayout(descriptionLayout);
	layoutPrincipal->addLayout(prixLayout);
	layoutPrincipal->addLayout(listLayout);

	
	QWidget* widget = new QWidget;
	widget->setLayout(layoutPrincipal);

	setFixedSize(600, 800);
	setCentralWidget(widget);
	setWindowTitle("Caisse Enregistreuse de Evan et Ahmed");
}

void CaisseWindow::setDescription(QString description) {
	if (description != description_) {
		description_ = description;
		emit descriptionChanged(description);
	}
}

void CaisseWindow::setPrix(float prix) {
	if (prix != prix_) {
		prix_ = prix;
		emit prixChanged(prix);
	}
}

void CaisseWindow::ajouter() {
	
}

void CaisseWindow::retirer() {

}

void CaisseWindow::reset() {

}

void CaisseWindow::selectItem(QListWidgetItem* item) {

}