#pragma once
#include <cstring>
#include <iostream>
using namespace std;
class exercise
{
private:
    int ID;
    char name[50];
    int series;
    double maxWeight;
    double weightInSeries;
    double oneRepMax;

public:
    exercise(int id, const char* exerciseName, int series, double maxWeight, double weightInSeries, double oneRM);

    int getID();
    void setID(int ID);
    const char* getName();
    void setName(const char* name);
    int getSeries();
    void setSeries(int series);
    double getMaxWeight();
    void setMaxWeight(double maxWeight);
    double getWeightInSeries();
    void setWeightInSeries(double weightInSeries);
    double getOneRepMax();
    void setOneRepMax(double oneRepMax);
    void print() const;
};
