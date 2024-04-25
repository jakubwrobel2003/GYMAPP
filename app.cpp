#include "app.h"
#include <fstream>
#include <vector>
#include <sstream>
void appstatus::setStatus() {
	this->status = !this->status;
}
bool appstatus::getStatus() {
	return this->status;
};
void appstatus::method0() {
	int ster;
	cout << "0-Add user\n";
	cout << "1-Delete user\n";
	cout << "2-Edit user\n";
	cout << "3-Show one user\n";
	cout << "4-Show user all\n";
    cout << "5-To back\n";
	cin >> ster;
	

}

void appstatus::method1() {
    int ster;
	cout << "0-Add new exercise\n";
	cout << "1-Delete new exercise\n";
	cout << "2-Show information new exercise\n";
    cin >> ster;

}

void appstatus::method2() {
	cout << "Goodbay\n";
	this->setStatus();
}

void appstatus::callMethod(int index) {
	if (index >= 0 && index < 3) {
		(this->*methodTable[index])(); 
	}
	else {
		cout << "Invalid index\n";
	}
}
vector<user> appstatus::wczytajDaneZTXT(const char* nazwaPliku) {

    vector<user> users;

    ifstream file(nazwaPliku);

    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku TXT!" << std::endl;
        return users;
    }

    char line[100];

    while (file.getline(line, sizeof(line))) {
        std::istringstream iss(line);
        char imie[50], nazwisko[50];
        int wiek, wzrost;
        double waga;

        
        if (iss >> imie >> nazwisko >> wiek >> wzrost >> waga) {
            user u( imie, nazwisko, wiek, wzrost, waga);
            users.push_back(u);
        }

        
       
    }


    file.close();
    return users;
}
void appstatus::userMetod0() {
    char imie[50];
    char nazwisko[50];
    int wiek;
    int height;
    double weight;

   
    cout << "Podaj imie: ";
    cin.getline(imie, 50);

    cout << "Podaj nazwisko: ";
    cin.getline(nazwisko, 50);


    cout << "Podaj wiek: ";
    cin >> wiek;


    cout << "Podaj wzrost w cm: ";
    cin >> height;


    cout << "Podaj wage w kg: ";
    cin >> weight;

    user u= user( imie,  nazwisko,  wiek, height,  weight);
    this->users.push_back(u);
};
void appstatus::userMetod1() {
    int i;
    cout << "podaj id usera do usuniecia\n";
    cin >> i;
    this->users[i].hidenInDataBase();
};
void appstatus::userMetod2() {

    int i;
    char imie[50];
    char nazwisko[50];
    int wiek;
    int height;
    double weight;

    cout << "podaj id usera do edycji\n";
    cin >> i;
    cout << "Podaj imie: ";
    cin.getline(imie, 50);
    cout << "Podaj nazwisko: ";
    cin.getline(nazwisko, 50);
    cout << "Podaj wiek: ";
    cin >> wiek;
    cout << "Podaj wzrost w cm: ";
    cin >> height;
    cout << "Podaj wage w kg: ";
    cin >> weight;

    this->users[i].setImie(imie);
    this->users[i].setNazwisko(nazwisko);
    this->users[i].setAge(wiek);
    this->users[i].setHeight(height);
    this->users[i].setWeight(weight);


};
void appstatus::userMetod3() {
    int i;
    cout << "podaj id usera do Wiswietlenia\n";
    cin >> i;
    this->users[i].print();
};
void appstatus::userMetod4() {
    int i = 1;
    for (int i = 0; i < this->users.size(); i++) {
        this->users[i].print();
    }
};
void appstatus::userMetod5() {
//back
};