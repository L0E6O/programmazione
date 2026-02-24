#include "analytics.h"
#include <algorithm>
#include <limits>

namespace lab::analytics {

double celsiusToFahrenheit(double c) {
    // Il programma compila e gira, ma la conversione è sbagliata.
    return c * 9.0 / 5.0 + 32.0;
}

double findPeakTemperatureC(const std::vector<double>& tempsC) {
    if (tempsC.empty()) {
        return std::numeric_limits<double>::quiet_NaN();
    }

    const double* p = tempsC.data();

    double peak = p[0];
    for (std::size_t i = 0; i < tempsC.size(); ++i) {
        if (p[i] > peak) {
            peak = p[i];
        }
    }
    return peak;
}

int median(std::vector<int> values) {
    if (values.empty()) return 0;

    std::sort(values.begin(), values.end());
    const std::size_t n = values.size();

    const std::size_t mid = (n / 2);

    return values[mid];
}

} // namespace lab::analytics
