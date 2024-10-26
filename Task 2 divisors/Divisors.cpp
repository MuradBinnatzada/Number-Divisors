#include <vector>
#include <iostream>
#include <cmath>
#include "Benchmark.h"
using namespace std;

std::vector<long long> divisors(long long number) {
    std::vector<long long> result;
    for (long long i = 1; i <= number; i++) {
        if (number % i == 0) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<long long> divisors2(long long number) {
    std::vector<long long> result;
    for (long long i = 1; i <= std::sqrt(number); i++) {
        if (number % i == 0) {
            result.push_back(i);
            if (i != number / i) result.push_back(number / i);
        }
    }
    return result;
}

void benchmarkDivisors(long long number) {
    cout << "Testing for number: " << number << endl;

    Benchmark<std::chrono::milliseconds> t1;
    divisors(number);
    auto duration1 = t1.elapsed();
    cout << "Execution time (divisors): " << duration1 << " ms" << endl;

    Benchmark<std::chrono::milliseconds> t2;
    divisors2(number);
    auto duration2 = t2.elapsed();
    cout << "Execution time (divisors2): " << duration2 << " ms" << endl;

    cout << "------------------------" << endl;
}

int main() {
    std::vector<long long> test_values = { 1000000, 10000000, 100000000, 1000000000, 10000000000 };

    for (const auto& value : test_values) {
        benchmarkDivisors(value);
    }
    return 0;
}