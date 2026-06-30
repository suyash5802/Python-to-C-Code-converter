#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    const int N = 200000000;
    const int P1 = 4;
    const int P2 = 1;

    double result = 1.0;
    int m = 0;

    auto t0 = std::chrono::high_resolution_clock::now();

    int i = 0;
    int limit = N - (N % 4);
    for (; i < limit; i += 4) {
        m += P1;
        result -= 1.0 / static_cast<double>(m - P2);
        result += 1.0 / static_cast<double>(m + P2);

        m += P1;
        result -= 1.0 / static_cast<double>(m - P2);
        result += 1.0 / static_cast<double>(m + P2);

        m += P1;
        result -= 1.0 / static_cast<double>(m - P2);
        result += 1.0 / static_cast<double>(m + P2);

        m += P1;
        result -= 1.0 / static_cast<double>(m - P2);
        result += 1.0 / static_cast<double>(m + P2);
    }
    for (; i < N; ++i) {
        m += P1;
        result -= 1.0 / static_cast<double>(m - P2);
        result += 1.0 / static_cast<double>(m + P2);
    }

    double final_result = result * 4.0;

    auto t1 = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double>(t1 - t0).count();

    std::cout.setf(std::ios::fixed);
    std::cout << "Result: " << std::setprecision(12) << final_result << "\n";
    std::cout << "Execution Time: " << std::setprecision(6) << elapsed << " seconds" << "\n";

    return 0;
}