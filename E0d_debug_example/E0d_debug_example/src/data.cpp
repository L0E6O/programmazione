#include "data.h"

namespace lab::data {

std::vector<double> sampleTemperaturesC() {
    // Il massimo qui è 35.0 (primo elemento).
    return {35.0, 22.0, 24.5, 28.1, 27.9, 21.2, 23.7, 20.0};
}

std::vector<int> sampleValuesForMedian() {
    // Dopo sorting: {1, 3, 5, 7, 9} → mediana = 5
    return {9, 1, 7, 5, 3};
}

} // namespace lab::data
