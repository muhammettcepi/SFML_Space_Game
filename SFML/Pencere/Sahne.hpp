#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
class Sahne
{
public:
	Sahne();
	void olustur(float sahneGenislik,
		float sahneYukseklik,
		float hucreBoyut);
	void ciz(sf::RenderWindow& pencere);
	void duvarResimSayisi();
	sf::Vector2f boyutGetir();

	
private:
	void duvarResimYukle();
	float ucKonumY;
	float ucKonumX;
};
