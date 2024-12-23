#include "miller_rabin.hpp"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

namespace fudmottin {

    cpp_int powMod(cpp_int base, cpp_int exp, const cpp_int& mod) {
        cpp_int result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    bool millerRabinTest(const cpp_int& n, int iterations) {
        if (n == 2 || n == 3) return true;
        if (n <= 1 || n % 2 == 0) return false;

        cpp_int d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
        }

        boost::random::random_device rd;
        boost::random::mt19937 rng(rd());
        boost::random::uniform_int_distribution<cpp_int> dist(2, n - 2);

        for (int i = 0; i < iterations; i++) {
            cpp_int a = dist(rng);
            cpp_int x = powMod(a, d, n);
            if (x == 1 || x == n - 1) continue;

            bool isPrime = false;
            cpp_int temp_d = d;
            while (temp_d != n - 1) {
                x = powMod(x, 2, n);
                temp_d <<= 1; // temp_d *= 2
                if (x == 1) return false;
                if (x == n - 1) {
                    isPrime = true;
                    break;
                }
            }

            if (!isPrime) return false;
        }

        return true;
    }
} // namespace fudmottin

