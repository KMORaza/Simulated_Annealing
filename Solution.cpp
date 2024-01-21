// Created: September 2022
#include "Solution.h"
#include <cstdlib>
Solution::Solution(int size) : values(size) {}
Solution::Solution(const Solution& other) : values(other.values) {}
Solution& Solution::operator=(const Solution& other) {
    values = other.values;
    return *this;
}
double& Solution::operator[](int index) {
    return values[index];
}
int Solution::size() const {
    return values.size();
}
void Solution::randomize() {
    for (double& value : values) {
        value = (rand() % 1000) / 1000.0; 
    }
}
