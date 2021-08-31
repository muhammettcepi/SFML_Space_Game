#include "Dusman.hpp"

Dusman::Dusman()
{
	srand(time(NULL));
	mermiResimYukle();
	int sayac = 0;
	m_aracBoyutu.x = 50.0f;
	m_aracBoyutu.y = 50.0f;
	std::string ana_yol = "resimler/uzay/";
	sf::IntRect boyut = sf::IntRect({ 225,255 }, { 590,570 });
	for (int i = 1; i < 4; i++) {
		std::string uzayyeni = ana_yol+"comm/";
		uzayyeni = uzayyeni + std::to_string(i) + ".png";
		AnimasyonlariYukle(uzayyeni,boyut,m_comm[i-1],dusmanCommSpriteList);
		sayac++;
	}
	boyut = sf::IntRect({ 70,30 }, { 590,480 });
	for (int i = 1; i < 6; i++) {
		std::string kucUcak = ana_yol + "smallship/";
		kucUcak = kucUcak + std::to_string(i) + ".png";
		AnimasyonlariYukle(kucUcak,boyut,m_smallship[i-1],dusmanSmallShipSpriteList);
		sayac++;
	}
	 boyut = sf::IntRect({ 55,65 }, { 155,110 });
	for (int i = 1; i < 4; i++) {
		std::string uzayBomba = ana_yol + "Spacebombs/";
		uzayBomba = uzayBomba + std::to_string(i) + ".png";
		AnimasyonlariYukle(uzayBomba,boyut,m_spacebomb[i-1],dusmanSpaceBombSpriteList);
		sayac++;
	}
	boyut = sf::IntRect({ 10,10 }, { 230,230 });
	for (int i = 1; i < 3; i++) {
		std::string uzayMayin = ana_yol + "Spacemines/";
		uzayMayin = uzayMayin + std::to_string(i) + ".png";
		AnimasyonlariYukle(uzayMayin,boyut,m_spacemine[i-1],dusmanSpaceMineSpriteList);
		sayac++;
	}
	boyut = sf::IntRect({ 65,60 }, { 375,440 });
	for (int i = 1; i < 5; i++) {
		std::string yarasaucak = ana_yol + "yarasaucak/";
		yarasaucak = yarasaucak + std::to_string(i) + ".png";
		AnimasyonlariYukle(yarasaucak,boyut,m_yarasaucak[i-1],dusmanYarasaUcakSpriteList);
		sayac++;
	}
}

void Dusman::ilkKonum()
{
}

void Dusman::olustur(sf::String dosyaIsmi)
{
}

void Dusman::ciz(sf::RenderWindow& pencere)
{
int dusman_sayac = 0;
	for (auto mermi : m_dusmanMermileri) {
		m_mermiAnimasyon.setPosition(mermi.konumGetir());
		pencere.draw(m_mermiAnimasyon);
	}
	for (auto dusman : m_dusmanListesi) {
		int seciliResim = dusman.seciliResimGetir();
		int seciliSinif = dusman.seciliSinifGetir();
		if (seciliSinif == 0) {
			m_aktifAnimasyon = dusmanCommSpriteList[seciliResim];
		}
		else if (seciliSinif == 1) {
			m_aktifAnimasyon = dusmanSmallShipSpriteList[seciliResim];
		}
		else if (seciliSinif == 2) {
			m_aktifAnimasyon = dusmanSpaceBombSpriteList[seciliResim];
		}
		else if (seciliSinif == 3) {
			m_aktifAnimasyon = dusmanSpaceMineSpriteList[seciliResim];
		}
		else if (seciliSinif == 4) {
			m_aktifAnimasyon = dusmanYarasaUcakSpriteList[seciliResim];
		}
		m_aktifAnimasyon.setPosition(dusman.konumGetir());
		pencere.draw(m_aktifAnimasyon);
	}
}

void Dusman::hareket(float boyut)
{
	int i = 0;
	for (auto dusman:m_dusmanListesi) {
		dusman.hareketet(boyut);
		m_dusmanListesi[i] = dusman;
		i++;
	}
	
}

bool Dusman::sahneIcindemi(sf::Vector2f yeniKonum)
{
	return false;
}

void Dusman::AnimasyonlariYukle(std::string dosyaAdi,sf::IntRect boyutlar, sf::Texture& kaplama, std::vector<sf::Sprite>& spriteList)
{
	if (!kaplama.loadFromFile(dosyaAdi));
	{

	}
	m_animasyon.setTexture(kaplama);
	m_animasyon.setTextureRect(boyutlar);
	float sx = m_aracBoyutu.x / boyutlar.width;
	float sy = m_aracBoyutu.y / (boyutlar.height);
	m_animasyon.setScale(sx, -sy);
	spriteList.push_back(m_animasyon);
}


void Dusman::atesEt()
{
	for (auto siradaki : m_dusmanListesi) {
		int seciliSinif = siradaki.seciliSinifGetir();
			if (seciliSinif==1||seciliSinif==4) {
				dusmanMermi dusmanMermi;
				dusmanMermi.konum({ siradaki.konumGetir().x + m_aracBoyutu.x / 2 - 5,siradaki.konumGetir().y });
				m_dusmanMermileri.push_back(dusmanMermi);
			}
	
	
	}
}

void Dusman::dusmanEkle()
{
	Dusmanlar dusmanlar;
	
	int secilenSinif = rand() % 5;
	int seciliAlan = rand() % 8;
	if (bosAlanlar[seciliAlan] == 0) {
		std::cout << secilenSinif;
		dusmanlar.seciliSinif(secilenSinif);
		dusmanlar.secilenKonum(seciliAlan);
		dusmanlar.seciliResminNumarasý(0);
		m_dusmanListesi.push_back(dusmanlar);
		bosAlanlar[seciliAlan] = 1;
	}
}

void Dusman::sahneDisinaCiktimi()
{
	int i = 0;
	for (auto dusman : m_dusmanListesi) {
		auto konum = dusman.konumGetir();
		if (konum.y > 700) {
			int konumSirasi= dusman.secilenKonumGetir();
			bosAlanlar[konumSirasi] = 0;
			m_dusmanListesi.erase(m_dusmanListesi.begin() + i);
		}
		i++;
	}
}

DusmanListesi Dusman::dusmanlariGetir()
{
	return m_dusmanListesi;
}

sf::Vector2f Dusman::boyutGetir()
{
	return m_aracBoyutu;
}

void Dusman::dusmanSil(int sira)
{
	int konumSirasi = m_dusmanListesi[sira].secilenKonumGetir();
	bosAlanlar[konumSirasi] = 0;
	m_dusmanListesi.erase(m_dusmanListesi.begin() + sira);
}

void Dusman::dusmanMermiHareket(float boyut)
{
	int i = 0;
	for (auto mermi : m_dusmanMermileri) {
		mermi.hareketet(boyut);
		m_dusmanMermileri[i] = mermi;
		i++;
	}
}

void Dusman::animasyonDegistir()
{
}
void Dusman::mermiResimYukle()
{
	sf::Image resim;
	if (!resim.loadFromFile("resimler/uzay/bullet_red.png"));
	{

	}
	m_mermiKaplama.loadFromImage(resim);
	m_mermiAnimasyon.setTexture(m_mermiKaplama);
	m_mermiAnimasyon.setTextureRect(sf::IntRect({ 45,30 }, { 40,70 }));
	float sx = m_mermiBoyut.x / 40;
	float sy = m_mermiBoyut.y / (70);
	m_mermiAnimasyon.setScale(sx, -sy);
}

sf::Vector2f Dusman::dusmanMermiBoyuGetir()
{
	return m_mermiBoyut;
}

dusmanMermiListesi Dusman::dusmanmermiListeGetir()
{
	return m_dusmanMermileri;
}

void Dusman::animasyonDegis()
{
	int dusman_sayac = 0;
	for (auto dusman : m_dusmanListesi) {
		int seciliResim = dusman.seciliResimGetir();
		int seciliSinif = dusman.seciliSinifGetir();
		if (seciliResim == 0 && artir == -1)
			artir = -artir;
		if (seciliResim == sinifSpriteSayilari[seciliSinif])
			artir = -artir;
		seciliResim += artir;
		artir = 1;
		dusman.seciliResminNumarasý(seciliResim);
		m_dusmanListesi[dusman_sayac] = dusman;
		dusman_sayac++;
	}
}
