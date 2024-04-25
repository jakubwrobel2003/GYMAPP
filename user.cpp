#include "user.h"

user::user(const char* imie, const char* nazwisko, int wiek, int height, double weight) {
    static int i = 0;

    strncpy_s(this->imie, imie, sizeof(this->imie));
    strncpy_s(this->nazwisko, nazwisko, sizeof(this->nazwisko));
    this->wiek = wiek;
    this->height = height;
    this->weight = weight;
    this->ID = ++i;
}

void user::print() const {
    if (!deleted) {


        cout << "ID:" << ID << "Imiê: " << imie << ", Nazwisko: " << nazwisko
            << ", Wiek: " << wiek << ", Wzrost: " << weight
            << ", Waga: " << height << endl;
    }
    else {

        cout << "ID:" << NULL << "Imiê: " << NULL << ", Nazwisko: " << NULL
            << ", Wiek: " << NULL << ", Wzrost: " << NULL
            << ", Waga: " << NULL << endl;
    }
}
void user::setImie(char* imie) {
    this->imie;
}
void user::setNazwisko(char* nazwisko) {
    this->nazwisko;
};
void user::setAge(int wiek) {
    this->wiek;
};
void user::setHeight(int height) {
    this->height;
};
void user::setWeight(double weight) {
    this->weight;
};
void user::hidenInDataBase() {
    this->deleted = true;
};