#pragma once

#include "Pencere.hpp"
#include "Sahne.hpp"
#include "Mermi.hpp"
#include "Uzay_Araci.hpp"
#include "Dusman.hpp"
class Oyun
{
public:
	Oyun();
	~Oyun();
	void girisKontrol();
	void sahneGuncelle();
	void sahneCiz();
	void saatiYenidenBaslat();
	bool bittimi();
	bool raketSahneIcindemi();
	Sahne m_sahne;
	float m_hucreBoyutu;
	void carpismaKontrol();
	void dusmanMermiCarptimi();
private:
	Pencere			m_pencere;
	sf::Clock		m_saat;
	sf::Time		m_gecenSure;
	sf::Clock		m_islemlerSure;
	sf::Clock		m_kullaniciAtesSure;
	bool			m_atesHakki=true;
	YON			m_siradakiYon;
	float m_cerceveSuresi;
	bool m_kapalimi;
	/*Raket m_raket;
	BlokListesi Bloklar;
	Top m_top;*/
	bool m_oyunBasladiMi;
	Uzay_Araci m_kullaniciAraci;
	int			m_cerceveSayisi;
	MermiListesi m__mermiListesi;
	Dusman m_dusman;
};