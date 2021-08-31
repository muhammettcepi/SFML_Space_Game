#include "Uzay_Araci.hpp"
#include<string> 
Uzay_Araci::Uzay_Araci()
{
	m_aracBoyutu.x = 50.0f;
	m_aracBoyutu.y = 50.0f;
	yon(YON::SAG);
	mermiResimYukle();
	std::string dosyaYolu = "resimler/uzay/user/";
	for (int i = 0; i < 8; i++) {
		std::string dosyaYolu1 = dosyaYolu + std::to_string((i + 1))+".png";
		AnimasyonlariYukle(dosyaYolu1,i);
	}
	
}

void Uzay_Araci::ilkKonum()
{
	m_konum.x = 200;
	m_konum.y = 600;
}

void Uzay_Araci::animasyonGuncelle() {

	if (secilianimasyon == 0&&artir==-1)
		artir=-artir;
	if (secilianimasyon == 7)
		artir = -artir;
	secilianimasyon += artir;
	m_aktifAnimasyon = spriteList[secilianimasyon];
 
}

void Uzay_Araci::ciz(sf::RenderWindow& pencere)
{
	for (auto mermiSiradaki : m_mermiListe) {
		m_mermiAnimasyon.setPosition(mermiSiradaki.konumGetir());
		pencere.draw(m_mermiAnimasyon);
		//mermiSiradaki.ciz(pencere);
	}
	m_aktifAnimasyon.setPosition(m_konum);
	pencere.draw(m_aktifAnimasyon);
	
}

void Uzay_Araci::hareket(float boyut)
{
	sf::Vector2f konum;
	switch (m_yon)
	{
	case YON::SAG:
		konum = m_konum;
		konum += sf::Vector2f(boyut, 0);
		if (sahneIcindemi(konum))
			m_konum = konum;
		break;
	case YON::SOL:

		konum = m_konum;
		konum -= sf::Vector2f(boyut, 0);
		if (sahneIcindemi(konum))
			m_konum = konum;
		break;
	}
	}
bool Uzay_Araci::sahneIcindemi(sf::Vector2f yeniKonum)
{
	auto konum = yeniKonum;
	if (konum.x <= 0 ||
		konum.x + m_aracBoyutu.x >=400)
	{
		return false;
	}
	return true;
}


void Uzay_Araci::yon(YON yon)
{
	m_yon = yon;
}

void Uzay_Araci::AnimasyonlariYukle(std::string dosyaAdi, int sayac)
{
	if (!m_kaplamalar[sayac].loadFromFile(dosyaAdi));
	{

	}
	m_animasyon.setTexture(m_kaplamalar[sayac]);
	m_animasyon.setTextureRect(sf::IntRect({ 25,30 }, { 450,450 }));
	float sx = m_aracBoyutu.x / 450;
	float sy = m_aracBoyutu.y / (450);
	m_animasyon.setScale(sx, sy);
	spriteList.push_back(m_animasyon);
}

void Uzay_Araci::mermiHareket(float boyut)
{
	int i = 0;
	for (auto mermi : m_mermiListe) {
		mermi.hareketet(boyut);
		m_mermiListe[i] = mermi;
		i++;;
	}
}

void Uzay_Araci::atesEt()
{
	Mermi mermi;
	mermi.konum({ m_konum.x + m_aracBoyutu.x / 2-5,m_konum.y});
	m_mermiListe.push_back(mermi);
}

void Uzay_Araci::mermiSahneDisindaMi()
{
	int i = 0;
	for (auto mermi : m_mermiListe) {
		auto konum = mermi.konumGetir();
		if (konum.y <= 20) {
 			m_mermiListe.erase(m_mermiListe.begin());
		}
		i++;
	}
}

void Uzay_Araci::mermiResimYukle()
{
	sf::Image resim;
	if (!resim.loadFromFile("resimler/uzay/bullet.png"));
	{

	}
	m_mermiKaplama.loadFromImage(resim);
	m_mermiAnimasyon.setTexture(m_mermiKaplama);
	m_mermiAnimasyon.setTextureRect(sf::IntRect({ 45,30 }, { 40,70 }));
	float sx = m_mermiBoyut.x / 40;
	float sy = m_mermiBoyut.y / (70);
	m_mermiAnimasyon.setScale(sx, sy);
}

sf::Vector2f Uzay_Araci::mermiBoyuGetir()
{
	return m_mermiBoyut;
}

MermiListesi Uzay_Araci::mermiListeGetir()
{
	return m_mermiListe;
}

void Uzay_Araci::mermiSil(int sira)
{
	m_mermiListe.erase(m_mermiListe.begin() + sira);
}

sf::Vector2f Uzay_Araci::konumGetir()
{
	return m_konum;
}

sf::Vector2f Uzay_Araci::boyutGetir()
{
	return m_aracBoyutu;
}

void Uzay_Araci::animasyonDegistir()
{
}
