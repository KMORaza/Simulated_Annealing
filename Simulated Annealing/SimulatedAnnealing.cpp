// Created: September 2022
#include "SimulatedAnnealing.h"
#include <cmath>
#include <cstdlib>
SimulatedAnnealing::SimulatedAnnealing(double initialTemp, double coolingRate, double minTemp, int maxIter, ObjectiveFunction* objFunc)
    : initialTemperature(initialTemp), coolingRate(coolingRate), minTemperature(minTemp), maxIterations(maxIter), objectiveFunction(objFunc) {}
Solution SimulatedAnnealing::run() {
    currentSolution.randomize();
    double currentEnergy = objectiveFunction->evaluate(&currentSolution[0], currentSolution.size());
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        double temperature = initialTemperature * std::pow(coolingRate, iteration);
        Solution newSolution = currentSolution;
        int randomIndex = rand() % newSolution.size();
        newSolution[randomIndex] += (rand() % 2000 - 1000) / 1000.0; 
        double newEnergy = objectiveFunction->evaluate(&newSolution[0], newSolution.size());
        if (newEnergy < currentEnergy || acceptanceProbability(currentEnergy, newEnergy, temperature) > (rand() % 1000) / 1000.0) {
            currentSolution = newSolution;
            currentEnergy = newEnergy;
        }
    }
    return currentSolution;
}
double SimulatedAnnealing::acceptanceProbability(double energy, double newEnergy, double temperature) {
    if (newEnergy < energy) {
        return 1.0;
    }
    return exp((energy - newEnergy) / temperature);
}
