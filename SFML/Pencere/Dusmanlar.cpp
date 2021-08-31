#include "Dusmanlar.hpp"
#include <iostream>

Dusmanlar::Dusmanlar()
{
	m_secilenResim = -1;
}

void Dusmanlar::konum(sf::Vector2f yeniKonum)
{
	m_konum = yeniKonum;
}

sf::Vector2f Dusmanlar::konumGetir() 
{
	return m_konum;
}

sf::String Dusmanlar::seciliResim()
{
	return sf::String();
}

void Dusmanlar::seciliResminNumarasý(int deger)
{
	m_secilenResim = deger;
	
}

int Dusmanlar::seciliResimGetir()
{
	return m_secilenResim;
}

void Dusmanlar::hareketet(float boyut)
{
	m_konum.y = m_konum.y + boyut;
}

void Dusmanlar::secilenKonum(int deger)
{
	m_secilenKonum = deger;
	m_konum.x = m_konum.x +50* deger;
}
int Dusmanlar::secilenKonumGetir()
{
	return m_secilenKonum;
}

void Dusmanlar::seciliSinif(int secilmisSinif)
{
	m_seciliSinif = secilmisSinif;
}

int Dusmanlar::seciliSinifGetir()
{
	return m_seciliSinif;
}

void Dusmanlar::arttirveyaazalt(int artis)
{
	m_secilenResim += artis;
}
