#pragma once
#include<SFML/Graphics.hpp>
#include<vector>

class Pencere
{
public:
	Pencere();
	void ayarla(unsigned int genislik,
		unsigned int yukseklik,
		sf::String baslik);
	void cizimeBasla();
	void cizimiBitir();
	bool kapandimi();
	void olayKontrol();
	void ciz(sf::Drawable& sekil);
	sf::RenderWindow& pencereGetir();

private:
	sf::RenderWindow m_window;
};