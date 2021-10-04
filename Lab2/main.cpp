#include "Jeu.hpp"
#include <iostream>
#include <fstream>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.

using namespace std;
using namespace iter;
using namespace gsl;

#pragma region "Fonctions de base pour vous aider"
typedef uint8_t UInt8;
typedef uint16_t UInt16;
UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read((char*)&texte[0], streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
gsl::span<Jeu*> spanListeJeux(const ListeJeux& liste)
{
	return gsl::span(liste.elements, liste.nElements);
}
gsl::span<Designer*> spanListeDesigners(const ListeDesigners& liste)
{
	return gsl::span(liste.elements, liste.nElements);
}
#pragma endregion

//TODO: Fonction qui cherche un designer par son nom dans une ListeJeux.
// Cette fonction renvoie le pointeur vers le designer si elle le trouve dans
// un des jeux de la ListeJeux. En cas contraire, elle renvoie un pointeur nul.
Designer* trouverDesigner(ListeJeux* list, string name) {

	for (int i : range(list->nElements)) {
		for (auto j : range(list->elements[i]->designers.nElements)) {	
			if (list->elements[i]->designers.elements[j]->nom == name){
				return list->elements[i]->designers.elements[j];
			}
		}
	}
	return nullptr;
}

Designer* lireDesigner(istream& fichier, ListeJeux* list)
{
	Designer designer = {}; // On initialise une structure vide de type Designer.
	designer.nom = lireString(fichier);
	designer.anneeNaissance = lireUint16(fichier);
	designer.pays = lireString(fichier);
	// Rendu ici, les champs précédents de la structure designer sont remplis
	// avec la bonne information.

	//TODO: Ajouter en mémoire le designer lu. Il faut revoyer le pointeur créé.
	// Attention, valider si le designer existe déjà avant de le créer, sinon
	// on va avoir des doublons car plusieurs jeux ont des designers en commun
	// dans le fichier binaire. Pour ce faire, cette fonction aura besoin de
	// la liste de jeux principale en paramètre.
	// Afficher un message lorsque l'allocation du designer est réussie.

	Designer* ptr_designer = trouverDesigner(list, designer.nom);

	if (ptr_designer == nullptr) {
		Designer* d = new Designer();
		d->nom = designer.nom;
		d->anneeNaissance = designer.anneeNaissance;
		d->pays = designer.pays;

		ListeJeux listParticipe = {};
		listParticipe.nElements = 0;
		listParticipe.capacite = 1;
		listParticipe.elements = new Jeu*;

		d->listeJeuxParticipes.nElements = listParticipe.nElements;
		d->listeJeuxParticipes.capacite = listParticipe.capacite;
		d->listeJeuxParticipes.elements = listParticipe.elements;

		cout << "Allocation réussie ! \n";
		return d;
	}
	return nullptr;
}

//TODO: Fonction qui change la taille du tableau de jeux de ListeJeux.
// Cette fonction doit recevoir en paramètre la nouvelle capacité du nouveau
// tableau. Il faut allouer un nouveau tableau assez grand, copier ce qu'il y
// avait dans l'ancien, et éliminer l'ancien trop petit. N'oubliez pas, on copie
// des pointeurs de jeux. Il n'y a donc aucune nouvelle allocation de jeu ici !
void augmenterTaille(ListeJeux& list) {

	list.capacite *= 2;
	Jeu** temp = new Jeu*[list.capacite];
	for (auto i : range(list.nElements)) {
		temp[i] = list.elements[i];
		delete[] list.elements[i];
	}
	list.elements = temp;
}

//TODO: Fonction pour ajouter un Jeu à ListeJeux.
// Le jeu existant déjà en mémoire, on veut uniquement ajouter le pointeur vers
// le jeu existant. De plus, en cas de saturation du tableau elements, cette
// fonction doit doubler la taille du tableau elements de ListeJeux.
// Utilisez la fonction pour changer la taille du tableau écrite plus haut.
void ajouterJeu(ListeJeux& list, Jeu* game) {

	if ((list.capacite - list.nElements) <= 1) { 
		augmenterTaille(list);
	}
	list.elements[list.nElements] = game;
}

//TODO: Fonction qui enlève un jeu de ListeJeux.
// Attention, ici il n'a pas de désallocation de mémoire. Elle enlève le
// pointeur de la ListeJeux, mais le jeu pointé existe encore en mémoire.
// Puisque l'ordre de la ListeJeux n'a pas être conservé, on peut remplacer le
// jeu à être retiré par celui présent en fin de liste et décrémenter la taille
// de celle-ci.
void enleverJeu(ListeJeux& list, Jeu* game) {

	for (auto j : range(list.nElements)) {
		if (list.elements[j] == game) {
			list.elements[j] = list.elements[list.nElements];
			list.elements[list.nElements] = nullptr; // on evite qu'il y ait un trous dans le tableau en le comblant avec le dernier element
			list.nElements--;
		}
	}
}

Jeu* lireJeu(istream& fichier)
{
	Jeu jeu = {}; // On initialise une structure vide de type Jeu
	jeu.titre = lireString(fichier);
	jeu.anneeSortie = lireUint16(fichier);
	jeu.developpeur = lireString(fichier);
	jeu.designers.nElements = lireUint8(fichier);
	// Rendu ici, les champs précédents de la structure jeu sont remplis avec la
	// bonne information.

	//TODO: Ajouter en mémoire le jeu lu. Il faut revoyer le pointeur créé.
	// Attention, il faut aussi créer un tableau dynamique pour les designers
	// que contient un jeu. Servez-vous de votre fonction d'ajout de jeu car la
	// liste de jeux participé est une ListeJeu. Afficher un message lorsque
	// l'allocation du jeu est réussie.

	ListeJeux* list = new ListeJeux();

	Jeu* jeuToReturn = new Jeu();
	jeuToReturn->titre = jeu.titre;
	jeuToReturn->anneeSortie = jeu.anneeSortie;
	jeuToReturn->developpeur = jeu.developpeur;
	jeuToReturn->designers.nElements = jeu.designers.nElements;
	jeuToReturn->designers.capacite = jeu.designers.nElements +1 ;
	
	jeuToReturn->designers.elements = new Designer*;

	cout << jeu.titre << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.

	for (int i : iter::range(jeu.designers.nElements)) {
		//TODO: Mettre le designer dans la liste des designer du jeu.
		jeuToReturn->designers.elements[i] = lireDesigner(fichier, list);
		//TODO: Ajouter le jeu à la liste des jeux auquel a participé le designer.

		ajouterJeu(jeuToReturn->designers.elements[i]->listeJeuxParticipes, jeuToReturn);
	}
	return jeuToReturn; //TODO: Retourner le pointeur vers le nouveau jeu.
}

ListeJeux* creerListeJeux(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	int nElements = lireUint16(fichier);
	ListeJeux listeJeux = {};

	ListeJeux* listToReturn = new ListeJeux();

	listToReturn->nElements = nElements;
	listToReturn->capacite = nElements + 1;
	listToReturn->elements = new Jeu*;

	for(int n : iter::range(nElements))
	{
		listToReturn->elements[n] = lireJeu(fichier); //TODO: Ajouter le jeu à la ListeJeux.
	}

	return listToReturn; //TODO: Renvoyer la ListeJeux.
}

//TODO: Fonction qui détermine si un designer participe encore à un jeu.
bool isParticipatingToAGame(Designer* designer) {

	return designer->listeJeuxParticipes.nElements != 0;
}


//TODO: Fonction pour détruire un designer (libération de mémoire allouée).
// Lorsqu'on détruit un designer, on affiche son nom pour fins de débogage.
void deleteDesigner(Designer* designeur) {

	if (! isParticipatingToAGame(designeur)) {
		cout << designeur->nom;
		delete& designeur->listeJeuxParticipes.elements;
		delete& designeur->listeJeuxParticipes;
		delete& designeur;
	}
}


//TODO: Fonction pour détruire un jeu (libération de mémoire allouée).
// Attention, ici il faut relâcher toute les cases mémoires occupées par un jeu.
// Par conséquent, il va falloir gérer le cas des designers (un jeu contenant
// une ListeDesigners). On doit commencer par enlever le jeu à détruire des jeux
// qu'un designer a participé (listeJeuxParticipes). Si le designer n'a plus de
// jeux présents dans sa liste de jeux participés, il faut le supprimer.  Pour
// fins de débogage, affichez le nom du jeu lors de sa destruction.
void deleteGame(Jeu* game) {

	for (int i : iter::range(game->designers.nElements)) { // Tous les designeurs de ce jeu
		enleverJeu(game->designers.elements[i]->listeJeuxParticipes, game);
		deleteDesigner(game->designers.elements[i]);
	}

	cout << game->titre;
	delete& game->designers;
	delete& game;
}

//TODO: Fonction pour détruire une ListeJeux et tous ses jeux.
void deleteCollection(ListeJeux& list) {

	for (int i : iter::range(list.nElements)) {
		deleteGame(list.elements[i]);
	}

	delete& list.elements;
}

void afficherDesigner(const Designer* d)
{
	cout << "\t" << d->nom << ", " << d->anneeNaissance << ", " << d->pays
			  << endl;
}

//TODO: Fonction pour afficher les infos d'un jeu ainsi que ses designers.
// Servez-vous de la fonction afficherDesigner ci-dessus.
void afficherJeu(Jeu* jeu) {

	cout << "\t" << jeu->titre << ", " << jeu->anneeSortie << ", " << jeu->developpeur;

	for (int i : iter::range(jeu->designers.nElements)) {
		afficherDesigner(jeu->designers.elements[i]);
	}
}

//TODO: Fonction pour afficher tous les jeux de ListeJeux, séparés par un ligne.
// Servez-vous de la fonction d'affichage d'un jeu crée ci-dessus. Votre ligne
// de séparation doit être différent de celle utilisée dans le main.
void afficherJeux(ListeJeux& list) {

	for (int i : iter::range(list.nElements)) {
		afficherJeu(list.elements[i]);
	}
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion

	int* fuite = new int;  // Pour vérifier que la détection de fuites fonctionne; un message devrait dire qu'il y a une fuite à cette ligne.

	ListeJeux* list = creerListeJeux("jeux.bin"); //TODO: Appeler correctement votre fonction de création de la liste de jeux.

	static const string ligneSeparation = "\n\033[35m════════════════════════════════════════\033[0m\n";
	cout << ligneSeparation << endl;
	cout << "Premier jeu de la liste :" << endl;
	//TODO: Afficher le premier jeu de la liste (en utilisant la fonction).  Devrait être Chrono Trigger.
	afficherJeu(list->elements[0]);
	cout << ligneSeparation << endl;

	//TODO: Appel à votre fonction d'affichage de votre liste de jeux.
	
	//TODO: Faire les appels à toutes vos fonctions/méthodes pour voir qu'elles fonctionnent et avoir 0% de lignes non exécutées dans le programme (aucune ligne rouge dans la couverture de code; c'est normal que les lignes de "new" et "delete" soient jaunes).  Vous avez aussi le droit d'effacer les lignes du programmes qui ne sont pas exécutée, si finalement vous pensez qu'elle ne sont pas utiles.

	//TODO: Détruire tout avant de terminer le programme.  Devrait afficher "Aucune fuite detectee." a la sortie du programme; il affichera "Fuite detectee:" avec la liste des blocs, s'il manque des delete.
}
