#include "Sahne.hpp"
#include <iostream>
Sahne::Sahne()
{
	std::srand(std::time(nullptr));
	
}
void Sahne::olustur(float sahneGenislik,
	float sahneYukseklik,
	float hucreBoyut)
{
	this->ucKonumX = sahneGenislik;
	this->ucKonumY = sahneYukseklik;
	duvarResimYukle();
	duvarResimSayisi();

}
void Sahne::ciz(sf::RenderWindow& pencere)
{
	
}
void Sahne::duvarResimSayisi()
{

}
sf::Vector2f Sahne::boyutGetir()
{
	sf::Vector2f boyut;
	boyut.x = this->ucKonumX;
	boyut.y = this->ucKonumY;
	return boyut;
}


void Sahne::duvarResimYukle()
{

}
