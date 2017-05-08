#pragma once
#include <SFML\System\Vector2.hpp>
#include <vector>
#include <cmath>
#include "ObiektWyswietlany.h"
class KolizyjneKolo;
class KolizyjnyProstokat;

class ObiektKolizyjny : public ObiektWyswietlany
{
public:
	virtual sf::Vector2f kolizja(sf::Vector2f, ObiektKolizyjny*)=0;
	virtual sf::Vector2f kolizja(sf::Vector2f, KolizyjneKolo*)=0;
	virtual sf::Vector2f kolizja(sf::Vector2f, KolizyjnyProstokat*)=0;
	virtual bool czyKolizja(sf::Vector2f, ObiektKolizyjny*) = 0;
	virtual bool czyKolizja(sf::Vector2f, KolizyjneKolo*) = 0;
	virtual bool czyKolizja(sf::Vector2f, KolizyjnyProstokat*) = 0;
	
	virtual void akcjaNaKolizji(ObiektKolizyjny*)=0;
	// konstruktory
	ObiektKolizyjny(int id, sf::Vector2f pozycja, float kat);
	virtual ~ObiektKolizyjny();
protected:
	static  float iloczynSkalarny(sf::Vector2f& a, sf::Vector2f& b, sf::Vector2f& srodek);
	static  sf::Vector2f kolizjaKolaZpunktem(sf::Vector2f& punkt, sf::Vector2f& srodek, float& promien);
	static float odlegloscPunktuOdLini(sf::Vector2f& linia1, sf::Vector2f linia2, sf::Vector2f punkt);
};