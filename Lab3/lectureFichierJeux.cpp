// Fonctions pour lire le fichier binaire.
#include "lectureFichierJeux.hpp"
#include <fstream>
#include "cppitertools/range.hpp"
#include "gsl/span"

using namespace std;

#pragma region "Fonctions de lecture de base"
UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion

shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& listeJeux, string nom)
{
	//TODO: Compléter la fonction (équivalent de trouverDesigner du TD2).
	return {};
}
template <typename U>
shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, istream& f)
{
	string nom              = lireString(f);
	unsigned anneeNaissance = lireUint16(f);
	string pays             = lireString(f);

	//[DONE]
	//TODO: Compléter la fonction (équivalent de lireDesigner du TD2).
	for (int i = 0; i < lj.size(); i++) {
		std::shared_ptr<Concepteur> c = lj.getElements()[i].get()->trouverConcepteur([](U v)  {return v->nom_ == nom});
		if (c != nullptr)
			return c;
	}

	std::shared_ptr<Concepteur> newConcepteur = make_shared<Concepteur>();
	newConcepteur->setNom(nom);
	newConcepteur->setAnneeNaissance(anneeNaissance);
	newConcepteur->setPays(pays);

	cout << "C: " << nom << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	return newConcepteur;
}

// [DONE]
shared_ptr<Jeu> lireJeu(istream& f, Liste<Jeu>& lj)
{
	string titre          = lireString(f);
	unsigned anneeSortie  = lireUint16(f);
	string developpeur    = lireString(f);
	unsigned nConcepteurs = lireUint8(f);
	//TODO: Compléter la fonction (équivalent de lireJeu du TD2).
	std::shared_ptr<Jeu> jeu = std::make_shared<Jeu>();
	for (unsigned int i = 0; i < nConcepteurs; i++)
		jeu->getListConcepteurs().ajouter(lireConcepteur(lj, f));

	std::shared_ptr<Jeu> newJeu = make_shared<Jeu>();
	newJeu->setTitre(titre);
	newJeu->setAnneeSortie(anneeSortie);
	newJeu->setDeveloppeur(developpeur);


	cout << "J: " << titre << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	return {};
}

//DONE]
Liste<Jeu> creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lireUint16(f);
	//[DONE]
	//TODO: Compléter la fonction.
	Liste<Jeu> listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements))
		listeJeux.ajouter(lireJeu(f, listeJeux));

	return listeJeux;
}
