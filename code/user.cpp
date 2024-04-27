#include "../headers/user.h"
user::user(const char* firstName, const char* lastName, int age, int height, double weight) {
    static int i = 0;

    strncpy_s(this->firstName, firstName, sizeof(this->firstName));
    strncpy_s(this->lastName, lastName, sizeof(this->lastName));
    this->age = age;
    this->height = height;
    this->weight = weight;
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
void user::setFirstName(char* firstName) {
    this->firstName;
}
void user::setLastName(char* lastName) {
    this-> lastName;
};
void user::setAge(int age) {
    this->age = age;
};
void user::setHeight(int height) {
    this->height = height;
};
void user::setWeight(double weight) {
    this->weight = weight;
};
void user::hideInDatabase() {
    this->deleted = true;
};
