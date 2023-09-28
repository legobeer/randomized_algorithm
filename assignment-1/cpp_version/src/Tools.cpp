#include <random>
#include "Tools.hpp"

std::random_device rd;
std::default_random_engine generator(rd());

double generateRandom(double x_min, double x_max) {
    std::uniform_real_distribution<double> x_distribution(x_min, x_max);
    return x_distribution(generator);
}