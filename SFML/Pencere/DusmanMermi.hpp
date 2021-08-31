#pragma once
#pragma once
#include<SFML/Graphics.hpp>
class dusmanMermi
{
public:
	dusmanMermi();

	void konum(sf::Vector2f yeniKonum);
	sf::Vector2f konumGetir() const;
	void ciz(sf::RenderWindow& pencere);
	void resimYukle();
	void hareketet(float boyut);

private:
	sf::Vector2f boyut;
	sf::Vector2f m_konum;
	sf::Color m_renk;
	sf::Vector2f		m_boyut;
	sf::Texture m_kaplama;
	sf::Sprite m_sprite;
	sf::Vector2f mermiBoyut = { 10.f,20.f };
	int m_secilenResim;
	int m_carpismaSayisi;
};
typedef std::vector<dusmanMermi> dusmanMermiListesi;