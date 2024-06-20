//
// Created by Admin on 09/06/2024.
//

#include "Cubic.h"
// Nearest Neighbor Interpolation
//class NearestNeighbor {
//public:
//    template <typename T>
//    static T interpolate(const std::vector<T>& data, double position) {
//        int index = static_cast<int>(std::round(position));
//        index = std::max(0, std::min(index, static_cast<int>(data.size() - 1)));
//        return data[index];
//    }
//};
//
//// Linear Interpolation
//class Linear {
//public:
//    template <typename T>
//    static T interpolate(const std::vector<T>& data, double position) {
//        int x1 = static_cast<int>(std::floor(position));
//        int x2 = x1 + 1;
//
//        x1 = std::max(0, std::min(x1, static_cast<int>(data.size() - 1)));
//        x2 = std::max(0, std::min(x2, static_cast<int>(data.size() - 1)));
//
//        if (x1 == x2) return data[x1];
//
//        double Q1 = data[x1];
//        double Q2 = data[x2];
//
//        return Q1 + (Q2 - Q1) * (position - x1) / (x2 - x1);
//    }
//};
//
//// Cubic Interpolation
//class Cubic {
//public:
//    template <typename T>
//    static T interpolate(const std::vector<T>& data, double position) {
//        int x = static_cast<int>(std::floor(position));
//        double dx = position - x;
//
//        // Helper function for cubic interpolation
//        auto cubicInterpolate = [](T v0, T v1, T v2, T v3, double x) -> T {
//            return v1 + 0.5 * x * (v2 - v0 + x * (2.0 * v0 - 5.0 * v1 + 4.0 * v2 - v3 + x * (3.0 * (v1 - v2) + v3 - v0)));
//        };
//
//        T p0 = data[std::max(0, x - 1)];
//        T p1 = data[std::max(0, std::min(x, static_cast<int>(data.size() - 1)))];
//        T p2 = data[std::max(0, std::min(x + 1, static_cast<int>(data.size() - 1)))];
//        T p3 = data[std::max(0, std::min(x + 2, static_cast<int>(data.size() - 1)))];
//
//        return cubicInterpolate(p0, p1, p2, p3, dx);
//    }
//};
//
//template <typename ColInterpolation, typename RowInterpolation>
//class Interpolator {
//public:
//    // Constructor
//    Interpolator(const std::vector<std::vector<double>>& data)
//            : data_(data), rows_(data.size()), cols_(data.empty() ? 0 : data[0].size()) {
//        if (rows_ == 0 || cols_ == 0) {
//            throw std::invalid_argument("Data grid cannot be empty");
//        }
//    }
//
//    // Interpolate method
//    double interpolate(double x, double y) const {
//        // Check bounds
//        if (x < 0 || x >= cols_ || y < 0 || y >= rows_) {
//            throw std::out_of_range("Interpolation point out of bounds");
//        }
//
//        // Column interpolation for each row
//        std::vector<double> rowResults(rows_);
//        for (size_t i = 0; i < rows_; ++i) {
//            rowResults[i] = ColInterpolation::template interpolate<double>(data_[i], x);
//        }
//
//        // Row interpolation
//        return RowInterpolation::template interpolate<double>(rowResults, y);
//    }
//
//private:
//    std::vector<std::vector<double>> data_;
//    size_t rows_;
//    size_t cols_;
//};

// Example data grid
//    std::vector<std::vector<double>> data = {
//            {1.0, 2.0, 3.0},
//            {4.0, 5.0, 6.0},
//            {7.0, 8.0, 9.0}
//    };
//
//    // Example usage with Nearest Neighbor for columns and Cubic for rows
//    Interpolator<NearestNeighbor, Cubic> interpolator(data);
//
//    double x = 1.6;
//    double y = 1.2;
//
//    try {
//        double value = interpolator.interpolate(x, y);
//        std::cout << "Interpolated value at (" << x << ", " << y << ") is " << value << std::endl;
//    } catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }