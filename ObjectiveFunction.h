// Created: September 2022
#pragma once
class ObjectiveFunction {
public:
    virtual double evaluate(const double* solution, int size) = 0;
    virtual ~ObjectiveFunction() {}
};
