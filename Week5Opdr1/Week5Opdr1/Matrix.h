#ifndef MATRIX
#define MATRIX

#include "ImageV2.h"

#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Matrix{
private:
	/**
	Het aanmaken van de afbeeldingen waar later naar de berekenen de waardes naar toe worden geschreven.
	*/
	Image image;
	Image tempImage;
	Image editedImage;
	Image iksloophetImage;
	Image ikhebhetalgeslooptImage;

public:
	/**
	De constructor van de klasse Matrix met als parameter de afbeedling waar de bewerkingen op uitgevoerd gaan worden.
	*/
	Matrix(Image image);

	/**
	In deze functie kunnen alle waardes van een matix worden ingevuld.
	Op de plekken waarde afbeelding geen waardes meer heeft komen zwarte pixels.
	*/
	void Transformatie(float a0, float a1, int a2, float b0, float b1, int b2);

	/**
	Geef twee waarde hoeveel x en y op hoeveel de afbeelding moet opschuiven.
	Op de plekken waarde afbeelding geen waardes meer heeft komen zwarte pixels.
	*/
	void Translatie(int dx, int dy);

	/**
	Deze functie is voor het draaien van een afbeelding.
	float f is voor de hoeveelheid graden.
	In de afbeedling zelf komen zwarte stippen door de rotatie.
	Op de plekken waarde afbeelding geen waardes meer heeft komen zwarte pixels.
	*/
	void Rotatie(float f);

	/**
	Deze functie is voor het schalen van de afbeelding.
	float s is voor de hoeveelheid dat de afbeelding geschaalt moet worden.
	als de waarde s tussen de 0 en de 0.9 licht is het een verkleining van de afbeelding.
	als de waarde s groter is dan 1 is het een vergroting vanuit de linkerbovenhoek.
	Op de plekken waarde afbeelding geen waardes meer heeft komen zwarte pixels.
	*/
	void Scaling(float s);

	/**
	Deze functie is voor het shearen van de afbeelding.
	float s is voor de hoeveeleid dat de afbeelding gesheard moet worden.
	De shearing is op de x as en begint boven in de linkerbovenhoek.
	*/
	void Shear(float s);

	/**
	Deze functie is voor het draaien van een afbeelding + First-order.
	Door de First-order horen de randen in de afbeelding er beter uit te zien.
	float f is voor de hoeveelheid graden.
	In de afbeedling zelf komen zwarte stippen door de rotatie.
	Op de plekken waarde afbeelding geen waardes meer heeft komen zwarte pixels.
	*/
	void RotatieAA(float f);

	/**
	voor het opslaan van de aangepaste afbeelding.
	de parameter zorgt dat de file naam aangepast wordt.
	*/
	void SaveImg(const char* filename);

	/**
	Deze functie is voor het draaien van een afbeelding door 3 keer een shear toe te passen + First-order.
	Door de First-order horen de randen in de afbeelding er beter uit te zien.
	float f is voor de hoeveelheid graden.
	In de afbeedling bevat geen zwarte stippen door een andere manier van rotatie.
	Op de plekken waarde afbeelding geen waardes meer heeft komen zwarte pixels.
	*/
	void Three_Way_Shear(float s);

	void Scaling_And_Rotation(float s, float r);
};
#endif