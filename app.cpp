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
	cout << "3-Show user all\n";
	cout << "4-Show one user\n";
	
	cin >> ster;
	

}

void appstatus::method1() {
	cout << "0-Add new exercise\n";
	cout << "1-Delete new exercise\n";
	cout << "2-Show information new exercise\n";


}

void appstatus::method2() {
	cout << "Goodbay\n";
	this->setStatus();
}

void appstatus::callMethod(int index) {
	if (index >= 0 && index < 3) {
		(this->*methodTable[index])(); // Wywo³anie metody
	}
	else {
		std::cout << "Invalid index\n";
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
      // Inicjalizacja zmiennej indeksu ID dla ka¿dego u¿ytkownika

    while (file.getline(line, sizeof(line))) {
        std::istringstream iss(line);
        char imie[50], nazwisko[50];
        int wiek, wzrost;
        double waga;

        // Upewnij siê, ¿e dane s¹ czytane poprawnie
        if (iss >> imie >> nazwisko >> wiek >> wzrost >> waga) {
            // Tworzymy obiekt user z odpowiednimi argumentami
            user u( imie, nazwisko, wiek, wzrost, waga);
            // Dodajemy u¿ytkownika do wektora
            users.push_back(u);
        }

        // Zwiêkszamy wartoœæ indeksu ID
       
    }

    // Zamykamy plik
    file.close();
    return users;
}