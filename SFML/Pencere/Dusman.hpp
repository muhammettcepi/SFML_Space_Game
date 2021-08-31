#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include"Dusmanlar.hpp"
#include "DusmanMermi.hpp"
class Dusman
{
public:
	Dusman();
	void ilkKonum();
	void olustur(sf::String dosyaIsmi);
	void ciz(sf::RenderWindow& pencere);
	void hareket(float boyut);
	bool sahneIcindemi(sf::Vector2f yeniKonum);
	void AnimasyonlariYukle(std::string dosyaAdi, sf::IntRect boyutlar, sf::Texture& kaplama, std::vector<sf::Sprite>& spriteList);
	void mermiEkle();
	void atesEt();
	void dusmanResimYukle();
	void dusmanEkle();
	void sahneDisinaCiktimi();
	DusmanListesi dusmanlariGetir();
	sf::Vector2f boyutGetir();
	void dusmanSil(int sira);
	void dusmanMermiHareket(float boyut);
	void mermiResimYukle();
	sf::Vector2f dusmanMermiBoyuGetir();
	dusmanMermiListesi dusmanmermiListeGetir();
	void animasyonDegis();
private:
	void				animasyonDegistir();
	sf::Vector2f		m_konum;
	sf::Texture			m_kaplamalar[17];
	sf::Texture			m_comm[3];
	sf::Texture			m_smallship[5];
	sf::Texture			m_spacebomb[3];
	sf::Texture			m_spacemine[2];
	sf::Texture			m_yarasaucak[4];
	sf::Texture			m_mermiKaplama;
	sf::Sprite			m_aktifAnimasyon;
	sf::Sprite			m_animasyon;
	sf::Sprite			m_mermiAnimasyon;
	float				m_hareketMiktari;
	sf::Vector2f m_mermiBoyut = { 10.f,20.f };
	sf::Vector2f m_aracBoyutu;
	std::vector<sf::Sprite> dusmanCommSpriteList;
	std::vector<sf::Sprite> dusmanSmallShipSpriteList;
	std::vector<sf::Sprite> dusmanSpaceBombSpriteList;
	std::vector<sf::Sprite> dusmanSpaceMineSpriteList;
	std::vector<sf::Sprite> dusmanYarasaUcakSpriteList;
	int secilianimasyon = -1;
	int artir = 1;
	DusmanListesi m_dusmanListesi;
	int bosAlanlar[8];
	dusmanMermiListesi m_dusmanMermileri;
	int sinifSpriteSayilari[5] = { 2, 4, 2, 1, 3 };
};