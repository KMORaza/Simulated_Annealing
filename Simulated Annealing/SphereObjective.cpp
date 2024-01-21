// Create
#include "SphereObjective.h"

double SphereObjective::evaluate(const double* solution, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += solution[i] * solution[i];
    }
    return sum;
}
