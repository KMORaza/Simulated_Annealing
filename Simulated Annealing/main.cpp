// Created: September 2022
#include "SimulatedAnnealing.h"
#include "SphereObjective.h"
#include <iostream>
int main() {
    SphereObjective sphereObjective;
    SimulatedAnnealing sa(100.0, 0.95, 0.01, 1000, &sphereObjective);
    Solution result = sa.run();
    std::cout << "Optimal Solution: ";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Optimal Value: " << sphereObjective.evaluate(&result[0], result.size()) << std::endl;
    return 0;
}
