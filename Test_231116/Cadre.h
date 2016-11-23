#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct AnchorPunkt
{
	int x;
	int y;
}AnchorPunkt;

class Cadre
{
private:
	int width; //largeur du cadre
	int height; //hauteur du cadre
	char motif; //motif de dessein du cadre
	AnchorPunkt ancre; //point d'ancrage du cadre

public:
	Cadre();
	Cadre(int w, int h, int x, int y, char c);
	Cadre(const Cadre &Source);
	~Cadre();

	void afficheCarac() const;
	int getSurface() const;
	int getPerimeter() const;
	bool isSquare() const;

	int getWidth() const;
	int getHeight() const;
	char getMotif() const;
	void setWidth(int nv);
	void setHeight(int nv);
	void setMotif(char nv);

};

