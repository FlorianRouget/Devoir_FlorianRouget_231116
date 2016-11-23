#include "Cadre.h"

//constructeur
//initialisation de toutes les variables des données membres (défaut)
Cadre::Cadre()
{
	this->ancre.x = 10;
	this->ancre.y = 5;
	this->height = 5;
	this->width = 2 * height;
	this->motif = '*';
}

//constructeur
//initialisation de toutes les variables des données membres (valeurs custom)
Cadre::Cadre(int w, int h, int x, int y, char c)
{
	this->ancre.x = x;
	this->ancre.y = y;
	this->height = h;
	this->width = w;
	this->motif = c;
}

//constructeur
//constructeur par copie, à partir d'un autre cadre
Cadre::Cadre(const Cadre & Source)
{
	this->ancre.x = Source.ancre.x;
	this->ancre.y = Source.ancre.y;
	this->height = Source.getHeight();
	this->width = Source.getWidth();
	this->motif = Source.getMotif();
}

//destructeur
Cadre::~Cadre()
{
}


//ENTREE : rien.
//SORTIE : les données sont directement écrites dans le terminal
//BUT : Le but de cette fonction est d'afficher la Hauteur, la Largeur, le Motif, le Perimetre, la Surface et de s'il s'agit d'un carré ou non.
void Cadre::afficheCarac() const
{
	cout << "Les caractéristiques du cadre sont : " << endl;
	cout << "Hauteur : " << this->getHeight() << endl;
	cout << "Largeur : " << this->getWidth() << endl;
	cout << "Motif : " << this->getMotif() << endl;
	cout << "Perimetre : " << this->getPerimeter() << endl;
	cout << "Surface : " << this->getSurface() << endl;
	if (this->isSquare()) {
		cout << "Il s'agit d'un carré." << endl;
	} else {
		cout << "Il ne s'agit pas d'un carré." << endl;
	}
}

//ENTREE : rien.
//SORTIE : La Surface du cadre
//BUT : calculer et renvoyer la surface du cadre.
int Cadre::getSurface() const
{
	int surface = 0;

	surface = (this->width * this->height);

	return surface;
}

//ENTREE : rien.
//SORTIE : Le Perimetre du cadre
//BUT : calculer et renvoyer le perimetre du cadre.
int Cadre::getPerimeter() const
{
	int perimeter = 0;

	perimeter = (2*this->width) + (2*this->height);

	return perimeter;
}

//ENTREE : rien.
//SORTIE : booleen vrai si carré, sinon faux.
//BUT : Déterminer si le cadre est un carré ou non.
bool Cadre::isSquare() const
{
	if (this->width == this->height) {
		return true;
	}
	return false;
}

//ENTREE : rien.
//SORTIE : la Largeur du cadre.
//BUT : renvoie la largeur du cadre.
int Cadre::getWidth() const
{
	return this->width;
}

//ENTREE : rien.
//SORTIE : la Hauteur du cadre.
//BUT : renvoie la Hauteur du cadre.
int Cadre::getHeight() const
{
	return this->height;
}

//ENTREE : rien.
//SORTIE : le motif du cadre.
//BUT : renvoie le motif du cadre.
char Cadre::getMotif() const
{
	return this->motif;
}

//ENTREE : la nouvelle largeur du cadre.
//SORTIE : rien
//BUT : assigne une nouvelle valeur à la largeur du cadre.
void Cadre::setWidth(int nv)
{
	this->width = nv;
}

//ENTREE : la nouvelle hauteur du cadre.
//SORTIE : rien
//BUT : assigne une nouvelle valeur à la hauteur du cadre.
void Cadre::setHeight(int nv)
{
	this->height = nv;
}

//ENTREE : le nouveau motif du cadre.
//SORTIE : rien
//BUT : assigne un nouveau motif au cadre.
void Cadre::setMotif(char nv)
{
	this->motif = nv;
}
