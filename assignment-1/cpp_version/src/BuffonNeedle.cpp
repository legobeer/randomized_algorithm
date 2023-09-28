#include <random>
#include <iostream>
#include <fstream>
#include <cmath>
#include <omp.h>
#include "Tools.hpp"
#include "BuffonNeedle.hpp"

int Buffon::isCrossed(int numberNeedles, int t, int l) {
    if (t < l) {
        std::cerr << "t must be superior or equal to l" << std::endl;
    }
    int crossTheLine = 0;
    #pragma omp parallel for reduction(+:crossTheLine)
    for (int i = 0; i < numberNeedles; i++) {
        double x = generateRandom(0, t / 2.0);
        double theta = generateRandom(0, M_PI / 2.0);
        if (x <= (l / 2.0) * sin(theta)) {
            crossTheLine++;
        }
    }
    return crossTheLine;
}

void Buffon::writeDataFile(int step, int numberTotalOfNeedles, int l, int t) {
    int numberNeedleCrossed = 0;
    int numberOfNeedles = 0;
    std::ofstream dataFile("buffonData.dat");
    for (int i = step; i < numberTotalOfNeedles; i += step) {
        numberOfNeedles += step;
        numberNeedleCrossed = isCrossed(numberOfNeedles, t, l);
        dataFile << numberOfNeedles << " " << 2.0 * l * numberOfNeedles / (t * numberNeedleCrossed)  << std::endl;
    }
    dataFile.close();

}
