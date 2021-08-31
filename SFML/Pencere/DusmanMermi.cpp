#include "DusmanMermi.hpp"

dusmanMermi::dusmanMermi()
{
	resimYukle();
}

void dusmanMermi::konum(sf::Vector2f yeniKonum)
{
	m_konum = yeniKonum;
}

sf::Vector2f dusmanMermi::konumGetir() const
{
	return m_konum;
}

void dusmanMermi::ciz(sf::RenderWindow& pencere)
{
}

void dusmanMermi::resimYukle()
{
}

void dusmanMermi::hareketet(float boyut)
{
	m_konum.y += boyut;
}
