#include "Oyun.hpp"

#include<iostream>

Oyun::Oyun()
{
	/*m_raket.ilkKonum(m_pencere.pencereGetir());
	m_top.ilkKonum(m_pencere.pencereGetir());*/
	m_kullaniciAraci.ilkKonum();
	m_kapalimi = false;
	m_cerceveSuresi = 1.0f / 180.0f;
	m_hucreBoyutu = 20.0f;
	auto boyut = m_pencere.pencereGetir().getSize();
	m_sahne.olustur(boyut.x, boyut.y, m_hucreBoyutu);
	//acidegeri=m_top.aciBelirle();
	//acidegeri=m_top.aciBelirle();
	//m_topHareketBoyutux = 1;
	//m_topHareketBoyutuy = 1;
	m_oyunBasladiMi = false;
	int blokgenislik = ceil((boyut.x - 80) / 5);
	/*m_blok.boyutBelirle(blokgenislik, 40);
	m_blok.bloklaraEkle();*/
}

Oyun::~Oyun()
{
}
void Oyun::girisKontrol()
{
	m_pencere.olayKontrol();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_siradakiYon = YON::SAG;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_siradakiYon = YON::SOL;
	else 
		m_siradakiYon = YON::BOS;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_atesHakki) {
		m_kullaniciAraci.atesEt();
		m_atesHakki = false;
	}
}
bool Oyun::raketSahneIcindemi()
{
	return true;
}
void Oyun::sahneGuncelle()
{
	dusmanMermiCarptimi();
	m_kullaniciAraci.mermiSahneDisindaMi();
	carpismaKontrol();
	m_dusman.sahneDisinaCiktimi();
	
	if (m_islemlerSure.getElapsedTime().asSeconds() >= 3) {
		m_dusman.dusmanEkle();
		m_dusman.atesEt();
		m_islemlerSure.restart();
	}
	//5 çerçeve güzel olmadığı için saniye tabanlı sisteme aldım.
	if (m_kullaniciAtesSure.getElapsedTime().asMilliseconds() >=500 ) {
		m_atesHakki = true;
		m_kullaniciAtesSure.restart();
	}
	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		m_gecenSure -= m_gecenSure;
		m_kullaniciAraci.yon(m_siradakiYon);
		m_kullaniciAraci.hareket(1);
		if (m_cerceveSayisi >= 5)
		{
			m_kullaniciAraci.animasyonGuncelle();
			m_kullaniciAraci.mermiHareket(5);
			m_dusman.animasyonDegis();
			m_dusman.hareket(1);
			m_dusman.dusmanMermiHareket(5);
			m_cerceveSayisi = 0;
		}
		m_cerceveSayisi++;
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	m_sahne.ciz(m_pencere.pencereGetir());
	m_dusman.ciz(m_pencere.pencereGetir());
	m_kullaniciAraci.ciz(m_pencere.pencereGetir());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	m_oyunBasladiMi = true;
	
	m_pencere.cizimiBitir();
	
}

void Oyun::saatiYenidenBaslat()
{
	m_gecenSure += m_saat.restart();
}

bool Oyun::bittimi()
{
	if (m_kapalimi)
		return true;

	return m_pencere.kapandimi();
}


void Oyun::carpismaKontrol() {
	auto dusmanBoyut=m_dusman.boyutGetir();
	auto mermiBoyut = m_kullaniciAraci.mermiBoyuGetir();
	int mermi_sayac = 0;
	int dusman_sayac = 0;
	
	for (auto mermi : m_kullaniciAraci.mermiListeGetir()) {
		auto mermiKonum = mermi.konumGetir();
		for (auto dusman : m_dusman.dusmanlariGetir()) {
			auto dusmanKonum = dusman.konumGetir();
			if (mermiKonum.y<= dusmanKonum.y&&mermiKonum.y>=dusmanKonum.y-5) {
				if ((dusmanKonum.x<=mermiKonum.x&& mermiKonum.x<=dusmanKonum.x + dusmanBoyut.x) 
					|| (dusmanKonum.x <= mermiKonum.x+ mermiBoyut.x && mermiKonum.x + mermiBoyut.x <= dusmanKonum.x + dusmanBoyut.x)) {
					m_kullaniciAraci.mermiSil(mermi_sayac);
					m_dusman.dusmanSil(dusman_sayac);
				}
			}
			dusman_sayac++;
		}
		dusman_sayac = 0;
		mermi_sayac++;
	}
}

void Oyun::dusmanMermiCarptimi()
{
	auto kullaniciAraciKonumu = m_kullaniciAraci.konumGetir();
	auto kullaniciAraciBoyutu = m_kullaniciAraci.boyutGetir();
	auto mermiBoyutu = m_dusman.dusmanMermiBoyuGetir();
	for (auto dusmanMermi : m_dusman.dusmanmermiListeGetir()) {
		auto dusmanMermiKonum = dusmanMermi.konumGetir();
			if (dusmanMermiKonum.y >= kullaniciAraciKonumu.y && dusmanMermiKonum.y <= kullaniciAraciKonumu.y+5) {
				if ((kullaniciAraciKonumu.x <= dusmanMermiKonum.x && dusmanMermiKonum.x <= kullaniciAraciKonumu.x + kullaniciAraciBoyutu.x)
					|| (kullaniciAraciKonumu.x <= dusmanMermiKonum.x + mermiBoyutu.x && dusmanMermiKonum.x + mermiBoyutu.x <= kullaniciAraciKonumu.x + kullaniciAraciBoyutu.x)) {
					m_kapalimi = true;
					std::cout << m_kapalimi;
				}
			}
	
	
	}
}
