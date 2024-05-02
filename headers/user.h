#pragma once
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include "exercise.h"
using namespace std;

class user
{
private:
    int ID;
    char firstName[50];
    char lastName[50];
    int age;
    int height;
    double weight;
    bool deleted = false;

public:
    vector <exercise> favExercise;


    user(const char* firstName, const char* lastName, int age, int height, double weight);

    const char* getFirstName() const { return firstName; }
    const char* getLastName() const { return lastName; }
    int getID() const { return ID; }
    int getAge() const { return age; }
    int getHeight() const { return height; }
    double getWeight() const { return weight; }
    void setAge(int age);
    void setHeight(int height);
    void setWeight(double weight);
    void hideInDatabase();
    void print() const;
};




