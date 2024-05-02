#include "../headers/user.h"
user::user(const char* firstName, const char* lastName, int age, int height, double weight) {
    static int i = 0;
    strncpy_s(this->firstName, firstName, sizeof(this->firstName));
    strncpy_s(this->lastName, lastName, sizeof(this->lastName));

    this->setAge(age);
    this->setHeight(height);
    this->setWeight(weight);
    this->ID = ++i;
}

void user::print() const {
    if (!deleted) {
        cout << "ID: " << ID << "First Name: " << firstName << ", Last Name: " << lastName
            << ", Age: " << age << ", Height: " << height
            << ", Weight: " << weight << endl;
    }
    else {
        cout << "ID: " << NULL << "First Name: " << NULL << ", Last Name: " << NULL
            << ", Age: " << NULL << ", Height: " << NULL
            << ", Weight: " << NULL << endl;
    }
}

void user::setAge(int age) {
    if (age > 0) {

    }
    else {
        do {
            cout << "Entry correct vaule:\n";
            cin >> age;
        } while (!(age > 0));

    }
    this->age = age;
};
void user::setHeight(int height) {
    if (height > 0) {

    }
    else {
        do {
            cout << "Entry correct vaule:\n";
            cin >> height;
        } while (!(height > 0));

    }
    this->height = height;
}
void user::setWeight(double weight) {
    if (weight > 0) {

    }
    else {
        do {
            cout << "Entry correct vaule:\n";
            cin >> weight;
        } while (!(weight > 0));

    }
    this->weight = weight;
};
void user::hideInDatabase() {
    this->deleted = true;
};
