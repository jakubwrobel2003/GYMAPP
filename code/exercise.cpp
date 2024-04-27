#include "../headers/exercise.h"
exercise::exercise(int id, const char* exerciseName, int series, double maxWeight, double weightInSeries, double oneRM) {
    ID = id;
    strncpy_s(name, exerciseName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0'; 
    series = series;
    maxWeight = maxWeight;
    weightInSeries = weightInSeries;
    oneRepMax = oneRM;
}

void exercise::print() const {
    cout << "ID: " << ID << ", Name: " << name
        << ", Series: " << series
        << ", Max: " << maxWeight
        << ", kg in Series: " << weightInSeries
        << ", OneRepMax: " << oneRepMax << endl;
}
