#include <cmath>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "Vector.hpp"
#include "Tools.hpp"
#include "ThrowingDarts.hpp"




int ThrowingDarts::computeDartsInCircle(int numberOfDarts) {
    int dartsInCircle = 0;
    #pragma omp parallel for reduction(+:dartsInCircle)
    for (int i = 0; i < numberOfDarts; i++) {
        Vector tmp = Vector(generateRandom(0, 1), generateRandom(0, 1));
        if (tmp.computeDistance2(Vector(0.5, 0.5)) < (0.5 * 0.5))
            dartsInCircle++;
    }
    return dartsInCircle;
}

void ThrowingDarts::writeDataFile(int step, int numberTotalOfDarts) {
    int dartsInCircle = 0;
    int numberOfDarts = 0;
    std::ofstream dataFile("throwingData.dat");
    for (int i = step; i < numberTotalOfDarts; i += step) {
        numberOfDarts += step;
        dartsInCircle = computeDartsInCircle(numberOfDarts);
        dataFile << numberOfDarts << " " << 4 * (double) dartsInCircle / numberOfDarts << std::endl;
    }
    dataFile.close();

}

