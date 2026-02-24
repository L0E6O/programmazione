#include <iostream>
#include <iomanip>

#include "data.h"
#include "analytics.h"
#include "utils.h"


void printHeader() {
    std::cout << "=== C++ Debugging Lab ===\n";
    std::cout << "Goal: trasformare i FAIL in PASS usando il debugger.\n\n";
}

void runConversionCheck() {
    const double c = 0.0;
    const double expectedF = 32.0;

    const double gotF = lab::analytics::celsiusToFahrenheit(c);

    if (lab::utils::almostEqual(gotF, expectedF)) {
        std::cout << "[PASS] [CelsiusToFahrenheit] 0C -> 32F\n";
    } else {
        std::cout << "[FAIL] [CelsiusToFahrenheit] 0C -> 32F"
                  << " (got=" << gotF << ", expected=" << expectedF << ")\n";
    }
}

void runPeakTemperatureCheck() {
    const auto temps = lab::data::sampleTemperaturesC();
    const double expectedPeak = 35.0;

    const double gotPeak = lab::analytics::findPeakTemperatureC(temps);

    std::cout << std::fixed << std::setprecision(1);
    if (lab::utils::almostEqual(gotPeak, expectedPeak, 1e-9)) {
        std::cout << "[PASS] [PeakTemperature] peak=35.0C\n";
    } else {
        std::cout << "[FAIL] [PeakTemperature] peak=35.0C"
                  << " (got=" << gotPeak << ", expected=" << expectedPeak << ")\n";
    }
}

void runMedianCheck() {
    const auto values = lab::data::sampleValuesForMedian();
    const int expectedMedian = 5;

    const int gotMedian = lab::analytics::median(values);

    if (gotMedian == expectedMedian) {
        std::cout << "[PASS] [Median] median=5\n";
    } else {
        std::cout << "[FAIL] [Median] median=5"
                  << " (got=" << gotMedian << ", expected=" << expectedMedian << ")\n";
    }
}


int main() {
    printHeader();

    runConversionCheck();
    runPeakTemperatureCheck();
    runMedianCheck();

    std::cout << "\nSuggerimento: apri `scripts/lab_script.md` e segui i passi.\n";
    return 0;
}
