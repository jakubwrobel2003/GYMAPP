#include "../headers/exercise.h"
exercise::exercise(int id, const char* exerciseName, int series, double maxWeight, double weightInSeries, double oneRM) {
    ID = id;
    strncpy_s(name, exerciseName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0'; // Upewnienie siê, ¿e nazwa jest zakoñczona zerem
    serie = series;
    max = maxWeight;
    kgInSerie = weightInSeries;
    oneRepMax = oneRM;
}