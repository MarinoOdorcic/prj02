#include "InterpolationPolicies.h"

/* ---------------------------------------------------------------------------------------------------- */
double LinearInterpolation::interpolate(const std::vector<double>& heading,
                                        const std::vector<double>& data,
                                        double x) const {
    auto it = std::upper_bound(heading.begin(), heading.end(), x);
    size_t i = it - heading.begin();
    auto x0 = heading[i-1];
    auto x1 = heading[i];
    auto y0 = data[i-1];
    auto y1 = data[i];
    auto y = y0 + (x-x0) * (y1-y0) / (x1-x0);
    return y;
}
int LinearInterpolation::pointsRequired() {
    return 2;
}

/* ---------------------------------------------------------------------------------------------------- */
double NearestNeighborInterpolation::interpolate(const std::vector<double>& heading,
                                                 const std::vector<double>& data,
                                                 double x) const {
    auto it = std::upper_bound(heading.begin(), heading.end(), x);
    size_t i = it - heading.begin();
    auto y = data[i];
    if (heading[i]-x > x-heading[i-1]){
        y = data[i-1];
    }
    return y;
}
int NearestNeighborInterpolation::pointsRequired() {
    return 2;
}
/* ---------------------------------------------------------------------------------------------------- */
double CubicInterpolation::interpolate(const std::vector<double>& heading,
                                       const std::vector<double>& data,
                                       double val) const {
    auto it = std::upper_bound(heading.begin(), heading.end(), val);
    int index = static_cast<int>(std::distance(heading.begin(), it));

    std::vector<double> x(heading.begin() + index - 2,
                          heading.begin() + index + 1);
//    double x0 = heading[index - 2];
//    double x1 = heading[index - 1];
//    double x2 = heading[index];
//    double x3 = heading[index + 1];
//
//    double y0 = data[index - 2];
//    double y1 = data[index - 1];
//    double y2 = data[index];
//    double y3 = data[index + 1];


    Eigen::MatrixXd A;
    for (int i = 0; i < 4; ++i) {
        A(i, 0) = pow(x[i], 3);
        A(i, 1) = pow(x[i], 2);
        A(i, 2) = x[i];
        A(i, 3) = 1;
    }

    double B[4][1] = {{y0},{y1},{y2},{y3}};
//    fmt::print("\nInput Row:\t{:.5g}\n", fmt::join(matrix[0], " "));
//    fmt::print("Input Row:\t{:.5g}\n", fmt::join(matrix[1], " "));
//    fmt::print("Input Row:\t{:.5g}\n", fmt::join(matrix[2], " "));
//    fmt::print("Input Row:\t{:.5g}\n\n", fmt::join(matrix[3], " "));
//    fmt::print("Input Col:\t{:.5g}\n", x0);

    // Gaussian elimination
//    for (int i = 0; i < 4; ++i) {
//        // Partial pivoting
//        int maxRow = i;
//        for (int k = i + 1; k < 4; ++k) {
//            if (std::abs(matrix[k][i]) > std::abs(matrix[maxRow][i])) {
//                maxRow = k;
//            }
//        }
//        for (int k = i; k < 5; ++k) {
//            std::swap(matrix[maxRow][k], matrix[i][k]);
//        }
//
//        // Make the diagonal contain all ones
//        double divisor = matrix[i][i];
//        if (std::abs(divisor) < 1e-10) {
//            throw std::runtime_error("Matrix is singular or nearly singular.");
//        }
//        for (int j = 0; j < 5; ++j) {
//            matrix[i][j] /= divisor;
//        }
//
//        // Make the other rows have 0 in current column
//        for (int k = 0; k < 4; ++k) {
//            if (k != i) {
//                double factor = matrix[k][i];
//                for (int j = 0; j < 5; ++j) {
//                    matrix[k][j] -= factor * matrix[i][j];
//                }
//            }
//        }
//    }

//    for (int i = 0; i < 4; ++i) {
//        // Make the diagonal contain all ones
//        double divisor = matrix[i][i];
//        for (int j = 0; j < 5; ++j) {
//            matrix[i][j] /= divisor;
//        }
//        // Make the other rows have 0 in current column
//        for (int k = 0; k < 4; ++k) {
//            if (k != i) {
//                double factor = matrix[k][i];
//                for (int j = 0; j < 5; ++j) {
//                    matrix[k][j] -= factor * matrix[i][j];
//                }
//            }
//        }
//    }

    // The coefficients are now the last column of the matrix
//    double a = matrix[0][4];
//    double b = matrix[1][4];
//    double c = matrix[2][4];
//    double d = matrix[3][4];

    std::vector<double> coeffs = A.colPivHouseholderQr().solve(B);

    double a = coeffs[0];
    double b = coeffs[1];
    double c = coeffs[2];
    double d = coeffs[3];

    double y = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
    return y;
}
int CubicInterpolation::pointsRequired() {
    return 4;
}