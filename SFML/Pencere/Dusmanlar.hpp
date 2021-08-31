#pragma once
#pragma once
#include<SFML/Graphics.hpp>
class Dusmanlar
{
public:
	Dusmanlar();
	void konum(sf::Vector2f yeniKonum);
	sf::Vector2f konumGetir();
	sf::String seciliResim();
	void seciliResminNumarasý(int deger);
	int seciliResimGetir();
	void hareketet(float boyut);
	void atesEt();
	void secilenKonum(int deger);
	int secilenKonumGetir();
	void seciliSinif(int secilmisSinif);
	int seciliSinifGetir();
	void arttirveyaazalt(int artis);

private:
	sf::Vector2f boyut;
	sf::Vector2f m_konum;
	sf::Color m_renk;
	sf::Vector2f		m_boyut;
	int m_secilenResim=0;
	int m_secilenKonum;
	int m_carpismaSayisi;
	int m_seciliSinif;
	
	
};
typedef std::vector<Dusmanlar> DusmanListesi;