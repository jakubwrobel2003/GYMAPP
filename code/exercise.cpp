#include "../headers/exercise.h"

exercise::exercise(int id, const char* exerciseName, int series, double maxWeight, double weightInSeries, double oneRM) {
    this->setID(ID);
    this->setName(exerciseName);
    this->setSeries(series);
    this->setOneRepMax(maxWeight);
    this->setWeightInSeries(weightInSeries);
    this->setOneRepMax(oneRM);
   
}

const char* exercise::getName() {
    return this->name;
};
void exercise::setName(const char* exerciseName) {
    strncpy_s(name, exerciseName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
   
};

void exercise::print() const {
    cout << "ID: " << ID << ", Name: " << name
        << ", Series: " << series
        << ", Max: " << maxWeight
        << ", kg in Series: " << weightInSeries
        << ", OneRepMax: " << oneRepMax << endl;
}
void exercise::setID(int ID) {

    this->ID = ID;
};



int exercise::getID() {
    return this->ID;
};

int exercise::getSeries() {
    return this->series;
};
void exercise::setSeries(int series) {
    if (series > 0) {
        
    }
    else {
        do {
            cout << "Entry correct vaule:\n";
            cin >> series;
        } while (!(series>0));
      
    }
    this->series = series;
};
double exercise::getMaxWeight() {
    return this->maxWeight;
};
void exercise::setMaxWeight(double maxWeight) {
    if (maxWeight > 0) {

    }
    else
    {
        do {
            cout << "Entry correct vaule:\n";
            cin >> maxWeight;
        } while (!(maxWeight > 0));
    }
    this->maxWeight;
};
double exercise::getWeightInSeries() {
    return this->weightInSeries;
};
void exercise::setWeightInSeries(double weightInSeries) {
    if (weightInSeries > 0) {

    }
    else
    {
        do {
            cout << "Entry correct vaule:\n";
            cin >> weightInSeries;
        } while (!(weightInSeries > 0));
    }
    this->weightInSeries;
};
double exercise::getOneRepMax() {
    return this->oneRepMax;
};
void exercise::setOneRepMax(double oneRepMax) {
    if (oneRepMax > 0) {

    }
    else
    {
        do {
            cout << "Entry correct vaule:\n";
            cin >> oneRepMax;
        } while (!(oneRepMax > 0));
    }
    this->oneRepMax;
};
