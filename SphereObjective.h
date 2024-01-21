// Created: September 2022
#pragma once
#include "ObjectiveFunction.h"
class SphereObjective : public ObjectiveFunction {
public:
    double evaluate(const double* solution, int size) override;
};
