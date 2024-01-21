// Created: September 2022
#pragma once
#include "Solution.h"
#include "ObjectiveFunction.h"
class SimulatedAnnealing {
private:
    double initialTemperature;
    double coolingRate;
    double minTemperature;
    int maxIterations;
    Solution currentSolution;
    ObjectiveFunction* objectiveFunction;
public:
    SimulatedAnnealing(double initialTemp, double coolingRate, double minTemp, int maxIter, ObjectiveFunction* objFunc);
    Solution run();
    double acceptanceProbability(double energy, double newEnergy, double temperature);
};
