/*
Examen de programmation

1.Quel est le rôle d'un constructeur ? Quand est-il executé ?

reponse : Dans une classe, un constructeur est une fonction qui est automatiquement appelée lors de la déclaration
d'une instance de la classe et qui sert à initialiser ses données membres.

2.Quel est le rôle d'un destructeur ? Quand l'utilise-t-on et quand est-il indispensable ?

reponse : Dans une classe, un destructeur est une fonction qui est appelée en fin de programme, à la destruction d'une
instance de la classe. Il sert à "libérer" les données membres de leurs valeurs, libérer la mémoire, et est nécessaire
dans le cas, par exemple, où une des données membres seraient un char* (ce qui implique un "new" et un delete[] ).

3.Comment repère-t-on le constructeur d'une classe ? Peut-il y en avoir plusieurs, et pourquoi ?

reponse : Le constructeur d'une classe porte toujours le même nom que la classe. Dans ce programme par exemple, la classe s'appelle Cadre,
et donc toutes les fonctions qui portent le nom Cadre seront des constructeurs. On remarque aussi que les constructeurs n'ont pas
de type, ce ne sont pas des Void ou des Int ou des Char... Il peut y avoir plusieurs constructeurs, autant qu'il est nécessaire.
L'utilité d'avoir plusieurs constructeurs est de pouvoir initialiser une instance de la classe de plusieurs manière. Par exemple,
dans le cas d'un constructeur par copie, il faudra un constructeur de base, avec ou sans paramètres, et un constructeur qui prendra
en paramètre une autre instance de la classe.

4.Qu'est-ce que la surdéfinition de fonction ?

reponse : la surdfinition d'une fonction correspond à la définition de plusieurs fonction portant le même nom, mais avec des paramètres différents.
Typiquement, avoir plusieurs contructeurs correspond à une surdéfinition des constructeurs.

5.Qu'est-ce que la définition de public et de private dans une classe ?

reponse : Les définitions public et private servent à définir le niveau de sécurité de ce que contient la classe. Souvent, on met les données
membres en private, pour qu'elles ne soient accessibles que depuis l'intérieur de la classe, et on met les méthodes en public pour
pouvoir les utiliser dans le main, ou ailleurs. C'est d'ailleurs l'intérêt des fonctions "get" et "set" : faire le lien entre les
données membres en private et le reste du programme.
Pour résumer simplement : tout ce qui est en private ne sera accessible que à l'intérieur de la classe elle-même, et tout ce qui est
en public sera accessible partout dans le programme.
A noter qu'il existe un autre niveau de sécurité, le "protected". Tout ce qui est en protected n'est accessible que par la classe elle-même,
mais aussi par ses héritiers. C'est un private qui prend en compte les héritages en somme.

*/

#include "Cadre.h"

void editCadre(Cadre *Source);

int main(int argc, char** argv) {

	Cadre cadre_one;
	Cadre cadre_two(1,2,11,22,'+');
	Cadre cadre_three(cadre_one);
	char c1 = '0';
	char c2 = '0';

	cout << "Bien le bonjour et bienvenue dans notre gestionnaire de CADRE." << endl;
	do
	{
		cout << "Voulez-vous afficher(1) ou changer(2) les valeurs d'un Cadre ? Vous pouvez aussi quitter(0)" << endl;
		do
		{
			cin >> c1;
		} while (c1 != '1' && c1 != '2' && c1 != '0');

		if (c1 != '0') {
			cout << "Quel cadre ? 1,2 ou 3 ?" << endl;
			do
			{
				cin >> c2;
			} while (c2 != '1' && c2 != '2' && c2 != '3');
		}

		switch (c1)
		{
			case '1': 
				switch (c2)
				{
				case '1': cadre_one.afficheCarac(); break;
				case '2': cadre_two.afficheCarac(); break;
				case '3': cadre_three.afficheCarac(); break;
				default: cout << "Il semble y avoir un problème :/" << endl;
					break;
				}
				break;
			case '2': 
				switch (c2)
				{
				case '1': editCadre(&cadre_one); break;
				case '2': editCadre(&cadre_two); break;
				case '3': editCadre(&cadre_three); break;
				default: cout << "Il semble y avoir un problème :/" << endl;
					break;
				}
				break; 
			case '0' : break;
			default: cout << "Il semble y avoir un problème :/" << endl;
				break;
		}
		if (c1 != '0') {
			cout << "Operation effectuée. Voulez vous continuer ou quitter(0) ?" << endl;
			cin >> c1;
		}
	} while (c1 != '0');

	system("pause");
	return 0;
}

void editCadre(Cadre *Source) {

	int Uint = 0;
	char Uchar = 0;

	cout << "Entrez les nouvelles valeurs" << endl;
	cout << "Hauteur : " << endl;
	cin >> Uint;
	Source->setHeight(Uint);
	cout << "Largeur : " << endl;
	cin >> Uint;
	Source->setWidth(Uint);
	cout << "Motif : " << endl;
	cin >> Uchar;
	Source->setMotif(Uchar);

}