#pragma once
#include <cmath>

namespace lab::utils {

inline bool almostEqual(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) <= eps;
}

} // namespace lab::utils
