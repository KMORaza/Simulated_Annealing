// Created: September 2022
#pragma once
#include <vector>
class Solution {
private:
    std::vector<double> values;
public:
    Solution(int size);
    Solution(const Solution& other);
    Solution& operator=(const Solution& other);
    double& operator[](int index);
    int size() const;
    void randomize();
};
