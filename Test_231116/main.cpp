/*
Examen de programmation

1.Quel est le r�le d'un constructeur ? Quand est-il execut� ?

reponse : Dans une classe, un constructeur est une fonction qui est automatiquement appel�e lors de la d�claration
d'une instance de la classe et qui sert � initialiser ses donn�es membres.

2.Quel est le r�le d'un destructeur ? Quand l'utilise-t-on et quand est-il indispensable ?

reponse : Dans une classe, un destructeur est une fonction qui est appel�e en fin de programme, � la destruction d'une
instance de la classe. Il sert � "lib�rer" les donn�es membres de leurs valeurs, lib�rer la m�moire, et est n�cessaire
dans le cas, par exemple, o� une des donn�es membres seraient un char* (ce qui implique un "new" et un delete[] ).

3.Comment rep�re-t-on le constructeur d'une classe ? Peut-il y en avoir plusieurs, et pourquoi ?

reponse : Le constructeur d'une classe porte toujours le m�me nom que la classe. Dans ce programme par exemple, la classe s'appelle Cadre,
et donc toutes les fonctions qui portent le nom Cadre seront des constructeurs. On remarque aussi que les constructeurs n'ont pas
de type, ce ne sont pas des Void ou des Int ou des Char... Il peut y avoir plusieurs constructeurs, autant qu'il est n�cessaire.
L'utilit� d'avoir plusieurs constructeurs est de pouvoir initialiser une instance de la classe de plusieurs mani�re. Par exemple,
dans le cas d'un constructeur par copie, il faudra un constructeur de base, avec ou sans param�tres, et un constructeur qui prendra
en param�tre une autre instance de la classe.

4.Qu'est-ce que la surd�finition de fonction ?

reponse : la surdfinition d'une fonction correspond � la d�finition de plusieurs fonction portant le m�me nom, mais avec des param�tres diff�rents.
Typiquement, avoir plusieurs contructeurs correspond � une surd�finition des constructeurs.

5.Qu'est-ce que la d�finition de public et de private dans une classe ?

reponse : Les d�finitions public et private servent � d�finir le niveau de s�curit� de ce que contient la classe. Souvent, on met les donn�es
membres en private, pour qu'elles ne soient accessibles que depuis l'int�rieur de la classe, et on met les m�thodes en public pour
pouvoir les utiliser dans le main, ou ailleurs. C'est d'ailleurs l'int�r�t des fonctions "get" et "set" : faire le lien entre les
donn�es membres en private et le reste du programme.
Pour r�sumer simplement : tout ce qui est en private ne sera accessible que � l'int�rieur de la classe elle-m�me, et tout ce qui est
en public sera accessible partout dans le programme.
A noter qu'il existe un autre niveau de s�curit�, le "protected". Tout ce qui est en protected n'est accessible que par la classe elle-m�me,
mais aussi par ses h�ritiers. C'est un private qui prend en compte les h�ritages en somme.

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
				default: cout << "Il semble y avoir un probl�me :/" << endl;
					break;
				}
				break;
			case '2': 
				switch (c2)
				{
				case '1': editCadre(&cadre_one); break;
				case '2': editCadre(&cadre_two); break;
				case '3': editCadre(&cadre_three); break;
				default: cout << "Il semble y avoir un probl�me :/" << endl;
					break;
				}
				break; 
			case '0' : break;
			default: cout << "Il semble y avoir un probl�me :/" << endl;
				break;
		}
		if (c1 != '0') {
			cout << "Operation effectu�e. Voulez vous continuer ou quitter(0) ?" << endl;
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