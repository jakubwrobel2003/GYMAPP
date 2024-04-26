#pragma once
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include "exercise.h"
using namespace std;
class user
{private:
    int ID;
	char imie[50];
    char nazwisko[50];
    int wiek;
    int height;
	double weight;
    bool deleted = false;
    vector <exercise> favExercise;

public:
    user(const char* imie, const char* nazwisko, int wiek, int height, double weight);
   

    const char* getImie() const { return imie; }
    const char* getNazwisko() const { return nazwisko; }
    int getID()const { return ID; }
    int getWiek() const { return wiek; }
    int getWzrost() const { return height; }
    double getWaga() const { return weight; }
    void setImie(char* imie);
    void setNazwisko(char* nazwisko);
    void setAge(int wiek);
    void setHeight(int height);
    void setWeight(double weight);
    void hidenInDataBase();
    void print() const;
   

   
};




