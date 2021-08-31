#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mermi.hpp"
enum class YON { BOS, SOL, SAG };
class Uzay_Araci
{
public:
	Uzay_Araci();
	void ilkKonum();
	void olustur(sf::String dosyaIsmi);
	void ciz(sf::RenderWindow& pencere);
	void hareket(float boyut);
	bool sahneIcindemi(sf::Vector2f yeniKonum);
	void animasyonGuncelle();
	void yon(YON yon);
	void AnimasyonlariYukle(std::string dosyaAdi,int sayac);
	void mermiHareket(float boyut);
	void atesEt();
	void mermiSahneDisindaMi();
	void mermiResimYukle();
	sf::Vector2f mermiBoyuGetir();
	MermiListesi mermiListeGetir();
	void mermiSil(int sira);
	sf::Vector2f konumGetir();
	sf::Vector2f boyutGetir();
private:
	void				animasyonDegistir();
	sf::Vector2f		m_konum;
	sf::Texture			m_kaplamalar[8];
	sf::Texture			m_mermiKaplama;
	sf::Sprite			m_aktifAnimasyon;
	sf::Sprite			m_animasyon;
	sf::Sprite			m_mermiAnimasyon;
	sf::Vector2f		m_mermiBoyut = { 10.f,20.f };
	YON					m_yon;
	float				m_hareketMiktari;
	sf::Vector2f m_aracBoyutu;
	std::vector<sf::Sprite> spriteList;
	int secilianimasyon = -1;
	int artir = 1;
	MermiListesi m_mermiListe;
};