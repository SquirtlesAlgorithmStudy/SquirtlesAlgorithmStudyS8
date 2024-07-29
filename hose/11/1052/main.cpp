#include <iostream>
#include <bitset>

int main() {
    int n, k;
    std::cin >> n >> k;

    long long result = 0;

    while (__builtin_popcount(n) > k) {
        int first_one_index = __builtin_ctz(n);
        result += (1LL << first_one_index);
        n += (1 << first_one_index);
    }

    std::cout << result << std::endl;

    return 0;
}