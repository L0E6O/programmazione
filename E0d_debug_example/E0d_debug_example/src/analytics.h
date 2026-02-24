#pragma once
#include <vector>

namespace lab::analytics {

double celsiusToFahrenheit(double c);

double findPeakTemperatureC(const std::vector<double>& tempsC);

int median(std::vector<int> values);

} // namespace lab::analytics
