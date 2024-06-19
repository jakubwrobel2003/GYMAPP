
#ifdef Zad_8_KOLCHAT
class Postac;
class Przedmiot : public Postac {
private:
	char nazwa[20];
	int moc;
public:
	void setMoc(int a) {
		if (moc <= 0) {
			throw invalid_argument("ZA MALA MOC")
		}
		moc = a;
	}
	int getMoc() {
		return moc;
	}
	Przedmiot(const char* nazwa, int moc) {
		strncpy_s(this->nazwa, sizeof(this->nazwa), nazwa, sizeof(this->nazwa) - 1);
		this->setMoc(moc);
	}
	virtual int dmg() override {
		return this->getMoc() * this->getsila();
	}
};
class Postac
{
private:
	char imie[20];
	int poziom;
	int doswiatczenie;
	Przedmiot* item;
	int sila;
public:
	int  getsila() { return  sila; }
	void setsila(int a) {
		sila = a;
	}
	int  getPoziom() { return poziom; }
	void setPoziom(int a) {
		poziom = a;
	}
	int getdoswiatczenie() { return doswiatczenie; }
	void  setdoswiatczenie(int a) {
		doswiatczenie = a;
	}

	void setPrzedmiot(Przedmiot* w) {
		this->item = w;
	}

	Przedmiot* getPrzedmiot() {
		return this->item;
	}
	virtual int dmg() const {
		return sila;
	}
};



int main()
{

}

#endif

#ifdef Zad_8_KOLGR6
class Wlasciciel {
private:
	char nazwa[14];

public:
	Wlasciciel() {
		nazwa[0] = '\0';
	}

	Wlasciciel(const char* nazwa) {
		setNazwa(nazwa);
	}

	void setNazwa(const char* nazwa) {
		if (strlen(nazwa) >= sizeof(this->nazwa)) {
			throw invalid_argument("Nazwa jest za dluga.");
		}
		strncpy_s(this->nazwa, sizeof(this->nazwa), nazwa, sizeof(this->nazwa) - 1);
	}

	char* getNazwa() { return nazwa; }
};

class Samochod {
private:
	char rejestracja[9];
	int licznik;
	bool dopuszczony;
	static int nr;
	Wlasciciel* w;

	void setNrrejestrcji(int nr) {
		if (nr >= 10000) {
			this->rejestracja[4] = nr / 10000;
		}
		else {
			this->rejestracja[4] = 0;
		}
		if (nr >= 1000) {
			this->rejestracja[5] = (nr / 1000) % 10;
		}
		else {
			this->rejestracja[5] = 0;
		}
		if (nr >= 100) {
			this->rejestracja[6] = (nr / 100) % 10;
		}
		else {
			this->rejestracja[6] = 0;
		}
		if (nr >= 10) {
			this->rejestracja[7] = (nr / 10) % 10;
		}
		else {
			this->rejestracja[7] = 0;
		}

		this->rejestracja[8] = nr % 10;
	}

public:
	Samochod(const char* rej, int l, bool d, Wlasciciel* w) {
		if (strlen(rej) != 3) {
			throw invalid_argument("Numer rejestracyjny powinien składać się z 3 liter.");
		}
		this->setDopuszczony(d);
		this->rejestracja[0] = rej[0];
		this->rejestracja[1] = rej[1];
		this->rejestracja[2] = rej[2];
		this->rejestracja[3] = '-';
		setNrrejestrcji(++nr);
		this->setWlasciciel(w);
		this->setLicznik(l);
	}

	void setWlasciciel(Wlasciciel* w) {
		this->w = w;
	}

	Wlasciciel* getWlasciciel() {
		return this->w;
	}

	void setLicznik(int l) {
		if (l < 0) {
			throw invalid_argument("Licznik nie moze byc ujemny");
		}
		licznik = l;
	}

	int getLicznik() const {
		return licznik;
	}

	void setDopuszczony(bool d) {
		dopuszczony = d;
	}

	bool isDopuszczony() const {
		return dopuszczony;
	}

	virtual double zasieg() const {
		return 800;
	}

	virtual double wartoscSamochodu(double WAR_POCZ) const {
		double WSP_SPARW = dopuszczony ? 1.0 : 0.2;
		double wartosc = (WAR_POCZ - 0.1 * licznik) * WSP_SPARW;
		if (wartosc < 400.0) {
			wartosc = 400.0;
		}
		return wartosc;
	}

	bool operator==(const Samochod& other) const {
		bool sameRejestracja = (strncmp(rejestracja, other.rejestracja, 3) == 0);
		bool similarLicznik = (licznik / 10 == other.licznik / 10);
		return sameRejestracja && similarLicznik;
	}
};

class SamochodElektryczny : public Samochod {
private:
	int stanBateri;

public:
	SamochodElektryczny(const char* rej, int l, bool d, Wlasciciel* w) : Samochod(rej, l, d, w) {
		// Dodatkowe inicjalizacje, jeśli potrzebne
	}

	void setStanBaterii(int s) {
		if (s < 0 || s > 100) {
			throw invalid_argument("Zla wartosc");
		}
		else {
			stanBateri = s;
		}
	}

	int getStanBateri() {
		return stanBateri;
	}

	double zasieg() const override {
		return stanBateri * 2.5;
	}
};

int Samochod::nr = 0;

int main() {
	// Tworzenie właścicieli
	Wlasciciel wlasciciel1("Kowalski");
	Wlasciciel wlasciciel2("Nowak");

	try {
		// Tworzenie samochodów
		Samochod samochod1("ABC", 50000, true, &wlasciciel1);
		Samochod samochod2("DEF", 30000, false, &wlasciciel2);

		// Tworzenie samochodów elektrycznych
		SamochodElektryczny elektryczny1("EFG", 40000, true, &wlasciciel1);
		elektryczny1.setStanBaterii(80);

		SamochodElektryczny elektryczny2("HIJ", 20000, true, &wlasciciel2);
		elektryczny2.setStanBaterii(50);

		// Testowanie operatora ==
		cout << "Samochod 1 == Samochod 2? " << (samochod1 == samochod2 ? "Tak" : "Nie") << endl;
		cout << "Elektryczny 1 == Elektryczny 2? " << (elektryczny1 == elektryczny2 ? "Tak" : "Nie") << endl;
	}
	catch (const invalid_argument& e) {
		cerr << "Blad: " << e.what() << endl;
	}

	return 0;
}
#endif

#ifdef Zad_8_KOL
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <ctime>

using namespace std;

class KontoBankowe;

class Klient {
private:
	char nazwa[50];

public:
	void setNazwa(const char* nazwa) {
		if (strlen(nazwa) >= sizeof(this->nazwa)) {
			throw invalid_argument("Nazwa jest za dluga.");
		}
		strncpy_s(this->nazwa, sizeof(this->nazwa), nazwa, 49);
	}

	// Getter dla nazwy
	const char* getNazwa() const {
		return nazwa;
	}

	Klient() {};
	Klient(const char* nazwa) {
		setNazwa(nazwa);
	}

	KontoBankowe* createKontoBankowe() const;
};

class KontoBankowe {
private:
	static int liczbaAktywnychKont;
	char numerKonta[27];
	double stanKonta;
	bool aktywne;
	const Klient* klient; // Użycie wskaźnika do stałego klienta

public:
	KontoBankowe(const char* numerKonta, double stanKonta, bool aktywne, const Klient* klient) {
		setNumerKonta(numerKonta);
		this->stanKonta = stanKonta;
		this->aktywne = aktywne;
		this->klient = klient;
		if (aktywne) {
			liczbaAktywnychKont++;
		}
	}

	~KontoBankowe() {
		if (aktywne) {
			liczbaAktywnychKont--;
		}
	}

	void setKlient(const Klient* klient) {
		this->klient = klient;
	}

	void setNumerKonta(const char* numerKonta) {
		if (strlen(numerKonta) != 26) {
			throw invalid_argument("Numer konta powinien mieć dokładnie 26 cyfr.");
		}
		strcpy_s(this->numerKonta, sizeof(this->numerKonta), numerKonta);
	}

	// Metoda zwracająca numer konta
	const char* getNumerKonta() const {
		return numerKonta;
	}

	// Metoda ustawiająca stan konta
	void setStanKonta(double stanKonta) {
		this->stanKonta = stanKonta;
	}

	// Metoda zwracająca stan konta
	double getStanKonta() const {
		return stanKonta;
	}

	// Metoda ustawiająca aktywność konta
	void setAktywne(bool aktywne) {
		if (this->aktywne != aktywne) {
			this->aktywne = aktywne;
			if (aktywne) {
				liczbaAktywnychKont++;
			}
			else {
				liczbaAktywnychKont--;
			}
		}
	}

	// Metoda sprawdzająca czy konto jest aktywne
	bool isAktywne() const {
		return aktywne;
	}

	// Metoda zwracająca wskaźnik do klienta
	const Klient* getKlient() const {
		return klient;
	}

	KontoBankowe& operator+=(double kwota) {
		if (kwota < 0) {
			throw invalid_argument("Kwota musi być dodatnia.");
		}
		stanKonta += kwota;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const KontoBankowe& konto) {
		os << "[" << konto.numerKonta << "] ";
		if (konto.aktywne) {
			os << konto.klient->getNazwa() << " : " << konto.stanKonta;
		}
		else {
			os << "NIEAKTYWNE";
		}
		return os;
	}

	virtual void obliczPrognozeStanuKonta() const {
		// Dla zwykłego konta bankowego nie ma oprocentowania, więc prognoza będzie brak zmiany
		cout << "Prognoza stanu konta za rok: " << stanKonta << endl;
	}

	operator double() const {
		return stanKonta;
	}
};

class KontoOszczednosciowe : public KontoBankowe {
private:
	int oprocentowanie;

public:
	KontoOszczednosciowe(const KontoBankowe& konto, int oprocentowanie)
		: KontoBankowe(konto.getNumerKonta(), konto.getStanKonta(), konto.isAktywne(), konto.getKlient()),
		oprocentowanie(oprocentowanie) {
		if (oprocentowanie < 0) {
			throw invalid_argument("Oprocentowanie nie może być ujemne.");
		}
	}

	void obliczPrognozeStanuKonta() const override {
		double nowyStan = getStanKonta() * (1 + oprocentowanie / 100.0);
		cout << "Prognoza stanu konta za rok z oprocentowaniem " << oprocentowanie << "%: " << nowyStan << endl;
	}
};

int KontoBankowe::liczbaAktywnychKont = 0;

KontoBankowe* Klient::createKontoBankowe() const {
	// Generowanie losowego numeru konta (na potrzeby przykładu)
	char numerKonta[27];
	srand(static_cast<unsigned int>(time(nullptr)));
	const char charset[] = "0123456789";
	for (size_t i = 0; i < 26; ++i) {
		numerKonta[i] = charset[rand() % (sizeof(charset) - 1)];
	}
	numerKonta[26] = '\0';

	// Tworzenie nowego konta bankowego
	return new KontoBankowe(numerKonta, 0.0, true, this); // Konto aktywne, zerowy stan
}

int main() {
	cout << "XD" << endl;
	Klient klient("Jan");
	KontoBankowe konto("12345678901234567890123456", 1000.0, true, &klient);

	cout << "Stan konta przed operacją: " << konto.getStanKonta() << endl;

	konto += 500.0;

	cout << "Stan konta po dodaniu 500.0: " << konto.getStanKonta() << endl;

	konto.setAktywne(false);

	cout << "Informacje o koncie: " << konto << endl;

	Klient klient2("Anna");
	KontoBankowe* konto1 = klient2.createKontoBankowe();

	cout << "Informacje o nowym koncie: " << *konto1 << endl;

	delete konto1; // Pamiętaj o usunięciu dynamicznie przydzielonej pamięci

	return 0;
}


#endif
#ifdef Zad_8_KOL1
#include <iostream>
#include <cstring>

using namespace std;

class Autor {
private:
	char nazwisko[16];

public:
	const char* getNazwisko() const {
		return nazwisko;
	}

	void setNazwisko(const char* nazwa) {
		strncpy_s(nazwisko, sizeof(nazwisko), nazwa, _TRUNCATE);
	}

	Autor(const char* n) {
		setNazwisko(n);
	}

	bool operator==(const Autor& other) const {
		return std::strcmp(nazwisko, other.nazwisko) == 0;
	}
};

class Ksiazka {
private:
	char tytul[30];
	int liczbaStron;
	bool dostep;
	Autor* autor; // Surowy wskaźnik do Autor

public:
	Ksiazka() : liczbaStron(0), dostep(false), autor(nullptr) {}

	Ksiazka(const char* _tytul, int _liczbaStron, bool _dostep, const char* _nazwiskoAutora)
		: liczbaStron(_liczbaStron), dostep(_dostep), autor(new Autor(_nazwiskoAutora)) {
		setTytul(_tytul);
	}

	~Ksiazka() {
		delete autor; // Zwolnienie pamięci za pomocą delete
	}

	// Konstruktor kopiujący
	Ksiazka(const Ksiazka& other)
		: liczbaStron(other.liczbaStron), dostep(other.dostep), autor(new Autor(other.autor->getNazwisko())) {
		setTytul(other.tytul);
	}

	// Operator przypisania
	Ksiazka& operator=(const Ksiazka& other) {
		if (this != &other) {
			liczbaStron = other.liczbaStron;
			dostep = other.dostep;
			delete autor; // Zwolnienie starego autor, jeśli istnieje
			autor = new Autor(other.autor->getNazwisko());
			setTytul(other.tytul);
		}
		return *this;
	}

	const char* getTytul() const {
		return tytul;
	}

	void setTytul(const char* nazwa) {
		strncpy_s(tytul, sizeof(tytul), nazwa, _TRUNCATE);
	}

	int getLiczbaStron() const {
		return liczbaStron;
	}

	void setLiczbaStron(int a) {
		liczbaStron = a;
	}

	bool isDostep() const {
		return dostep;
	}

	void setDostep(bool a) {
		dostep = a;
	}

	Autor* getAutor() const {
		return autor;
	}

	void setAutor(Autor* a) {
		autor = a;
	}

	// Przeciążenie operatora << dla strumienia wyjściowego
	friend std::ostream& operator<<(std::ostream& os, const Ksiazka& ksiazka) {
		os << "Książka:\n";
		os << "Tytuł: " << ksiazka.tytul << "\n";
		os << "Liczba stron: " << ksiazka.liczbaStron << "\n";
		os << "Dostępność: " << (ksiazka.dostep ? "dostępna" : "niedostępna") << "\n";
		os << "Autor: " << ksiazka.autor->getNazwisko() << "\n";
		return os;
	}

	bool operator==(const Ksiazka& other) const {
		return liczbaStron == other.liczbaStron &&
			dostep == other.dostep &&
			(*autor == *other.autor); // Porównanie Autorów
	}
};

class Ebook : public Ksiazka {
private:
	double rozmiar;

public:
	Ebook(const char* tytul, int liczbaStron, bool dostep, const char* nazwiskoAutora, double _rozmiar)
		: Ksiazka(tytul, liczbaStron, dostep, nazwiskoAutora), rozmiar(_rozmiar) {}

	double getRozmiar() const {
		return rozmiar;
	}

	void setRozmiar(double r) {
		rozmiar = r;
	}
};

int main() {
	Autor autor("Jan Kowalski");
	Ebook ebook("Programowanie w C++", 400, true, autor.getNazwisko(), 2.5);

	std::cout << "Ebook:\n";
	std::cout << ebook;

	return 0;
}
