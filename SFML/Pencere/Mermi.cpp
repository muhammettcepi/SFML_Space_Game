#include "Mermi.hpp"
#include <iostream>
Mermi::Mermi()
{
	resimYukle();
}

void Mermi::konum(sf::Vector2f yeniKonum)
{
	m_konum = yeniKonum;
}

sf::Vector2f Mermi::konumGetir() const
{
	return m_konum;
}

void Mermi::ciz(sf::RenderWindow& pencere)
{
	m_sprite.setPosition(m_konum);
	pencere.draw(m_sprite);
}

void Mermi::resimYukle()
{
	sf::Image resim;
	if (!resim.loadFromFile("resimler/uzay/bullet.png"));
	{

	}
	m_kaplama.loadFromImage(resim);
	m_sprite.setTexture(m_kaplama);
	m_sprite.setTextureRect(sf::IntRect({ 45,30 }, { 40,70 }));
	float sx = 10.f / 40;
	float sy = 20.f / (70);
	m_sprite.setScale(sx, sy);
}

void Mermi::hareketet(float boyut)
{
	m_konum.y -= boyut;
}
