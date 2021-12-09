#include "CaisseWindow.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <qlistwidget.h>
#include <QLabel>
#include <QString>
#include <qframe.h>
#include <qmessagebox.h>
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

	descriptionLabel = new QLabel;
	descriptionLabel->setText("Description:");
	
	descriptionEdit = new QLineEdit(this);
	descriptionEdit->setPlaceholderText("Description");
	descriptionEdit->setFixedSize(400, 50);
	descriptionEdit->setFocus();

	QHBoxLayout* descriptionLayout = new QHBoxLayout;
	descriptionLayout->addWidget(descriptionLabel);
	descriptionLayout->addWidget(descriptionEdit);

	prixLabel = new QLabel;
	prixLabel->setText("Prix:");

	prixEdit = new QLineEdit(this);
	prixEdit->setPlaceholderText("Prix");
	prixEdit->setFixedSize(400, 50);
	prixEdit->setFocus();

	QHBoxLayout* prixLayout = new QHBoxLayout;
	prixLayout->addWidget(prixLabel);
	prixLayout->addWidget(prixEdit);

	QLabel* taxableLabel = new QLabel;
	taxableLabel->setText("Taxable");

	taxableCheck = new QCheckBox;
	taxableCheck->setChecked(true);

	QHBoxLayout* taxableLayout = new QHBoxLayout;
	taxableLayout->addWidget(taxableLabel);
	taxableLayout->addWidget(taxableCheck);

	QObject::connect(descriptionEdit, &QLineEdit::textChanged, this, [&]() {setDescription(descriptionEdit->text()); });
	QObject::connect(prixEdit, &QLineEdit::textChanged, this, [&]() {setPrix(prixEdit->text()); });
	QObject::connect(taxableCheck, &QCheckBox::clicked, this, [&]() {setTaxable(taxableCheck->isChecked()); });


	QHBoxLayout* buttonLayout = new QHBoxLayout;

	ajouterButton = new QPushButton(this);
	ajouterButton->setText("AJOUTER");
	QObject::connect(ajouterButton, &QPushButton::released, this, [&]() {
			try {
				ajouter();
			}
			catch (NotCorrectlyFilledField& e) {
				QMessageBox box;
				box.critical(0, "Erreur en ajoutant un article", e.what());
			}
			catch (invalid_argument& e) {
				QMessageBox box;
				box.critical(0, "Erreur en ajoutant un article", "Le prix n'est pas correct");
			}
		});

	retirerButton = new QPushButton(this);
	retirerButton->setText("RETIRER");
	retirerButton->setDisabled(true);
	QObject::connect(retirerButton, &QPushButton::released, this, [&]() {		
		try {
			retirer();
		}
		catch (ArticleNotSelected& e) {
			QMessageBox box;
			box.critical(0, "Erreur en retirant un article", e.what());
		}
	});

	resetButton = new QPushButton(this);
	resetButton->setText("RESET");
	resetButton->setDisabled(true);
	QObject::connect(resetButton, &QPushButton::released, this, [&]() {reset(); });

	buttonLayout->addWidget(ajouterButton);
	buttonLayout->addWidget(retirerButton);
	buttonLayout->addWidget(resetButton);

	QVBoxLayout* listLayout = new QVBoxLayout;
	QLabel* listLabel = new QLabel;
	listLabel->setText("Liste des éléments");
	listLayout->addWidget(listLabel);
	listWidget = new QListWidget;
	listWidget->setSortingEnabled(true);
	QObject::connect(listWidget, &QListWidget::itemClicked, this, [&]() { selectedArticle = make_shared<Article>(Article(listWidget->selectedItems()[0]->text().split("-")[0].toStdString(), "", false)); cout << selectedArticle; });

	listLayout->addWidget(listWidget);
	listLayout->addLayout(buttonLayout);

	QFrame* horizontalLine = new QFrame;
	horizontalLine->setFrameShape(QFrame::HLine);

	QVBoxLayout* affichageLayout = new QVBoxLayout;

	totalAvanTaxeLabel = new QLabel;
	totalAvanTaxeLabel->setText("Total avant taxe");

	totalAvanTaxeEdit = new QLineEdit(this);
	totalAvanTaxeEdit->setText("0.00");
	totalAvanTaxeEdit->setFixedSize(200, 30);
	totalAvanTaxeEdit->setFocus();
	totalAvanTaxeEdit->setDisabled(true);

	QHBoxLayout* totalAvanTaxeLayout = new QHBoxLayout;
	totalAvanTaxeLayout->addWidget(totalAvanTaxeLabel);
	totalAvanTaxeLayout->addWidget(totalAvanTaxeEdit);
	
	totalTaxeLabel = new QLabel;
	totalTaxeLabel->setText("Total des taxes");

	totalTaxeEdit = new QLineEdit(this);
	totalTaxeEdit->setText("0.00");
	totalTaxeEdit->setFixedSize(200, 30);
	totalTaxeEdit->setFocus();
	totalTaxeEdit->setDisabled(true);

	QHBoxLayout* totalTaxeLayout = new QHBoxLayout;
	totalTaxeLayout->addWidget(totalTaxeLabel);
	totalTaxeLayout->addWidget(totalTaxeEdit);

	totalLabel = new QLabel;
	totalLabel->setText("Total à payer");
	totalEdit = new QLineEdit(this);
	totalEdit->setText("0.00");
	totalEdit->setFixedSize(200, 30);
	totalEdit->setFocus();
	totalEdit->setDisabled(true);

	QHBoxLayout* totalLayout = new QHBoxLayout;
	totalLayout->addWidget(totalLabel);
	totalLayout->addWidget(totalEdit);

	affichageLayout->addLayout(totalAvanTaxeLayout);
	affichageLayout->addLayout(totalTaxeLayout);
	affichageLayout->addLayout(totalLayout);

	layoutPrincipal->addLayout(descriptionLayout);
	layoutPrincipal->addLayout(prixLayout);
	layoutPrincipal->addLayout(taxableLayout);
	layoutPrincipal->addWidget(horizontalLine);
	layoutPrincipal->addLayout(listLayout);
	layoutPrincipal->addLayout(affichageLayout);
	layoutPrincipal->addLayout(buttonLayout);




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

void CaisseWindow::setPrix(QString prix) {
	if (prix != prix_) {
		prix_ = prix;
		emit prixChanged(prix);
	}
}

void CaisseWindow::ajouter() {
	if (description_ == "" || prix_ == "" || prix_ == "0.00") throw NotCorrectlyFilledField("Certains champs sont mal remplis");
	cout << "ajouter du controller called";
	auto test = stof(prix_.toStdString());
	
	shared_ptr<Article> newArticle = make_shared<Article>(Article(description_.toStdString(), prix_.toStdString(), taxable_)); // TODO: mettre dans le model
	caisse_.addArticle(newArticle);
	actualiserVue();
}

void CaisseWindow::retirer() {
	if (selectedArticle == nullptr) throw ArticleNotSelected("Aucun article selectionné");
	caisse_.removeArticle(selectedArticle);
	emit retirerPressed();
	actualiserVue();
}

void CaisseWindow::reset() {

	caisse_.resetList();

	descriptionEdit->setText("");
	prixEdit->setText("");
	taxableCheck->setChecked(true);
	retirerButton->setDisabled(true);
	resetButton->setDisabled(true);
	emit resetPressed();
	actualiserVue();
}

void CaisseWindow::setTaxable(bool value) {
	if (taxable_ != value) {
		taxable_ = value;
		emit taxableChanged(value);
	}
}

void CaisseWindow::actualiserVue() {
	listWidget->clear();
	descriptionEdit->setText("");
	prixEdit->setText("");
	taxableCheck->setChecked(true);
	for (auto&& i : caisse_.getList()) {
		listWidget->addItem(
			QString::fromStdString(
				i->getDescprition() + "-" + i->getPrix()
			)
		);
	}
	caisse_.calculerPrix();
	totalAvanTaxeEdit->setText(QString::fromStdString(caisse_.getPrix(0)));
	totalTaxeEdit->setText(QString::fromStdString(caisse_.getPrix(1)));
	totalEdit->setText(QString::fromStdString(caisse_.getPrix(2)));
	if (caisse_.getList().size() != 0) {
		retirerButton->setEnabled(true);
		resetButton->setEnabled(true);
	}
	else {
		retirerButton->setDisabled(true);
		resetButton->setDisabled(true);
	}

}
