#pragma once
#include <vector>

namespace lab::data {

// Dataset "sensor temperature" in Celsius.
// Nota: il massimo è intenzionalmente il PRIMO elemento per stressare il bug di pointer.
std::vector<double> sampleTemperaturesC();

// Dataset per median (n dispari).
std::vector<int> sampleValuesForMedian();

} // namespace lab::data
