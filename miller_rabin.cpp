#include "miller_rabin.hpp"
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>

using namespace boost::multiprecision;

namespace fudmottin {

    const int MILLERRABINITERATIONS = 40;

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

    bool millerRabinTest(const cpp_int& n) {
        if (n <= 1 || n == 4) return false;
        if (n <= 5) return true;

        cpp_int d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
        }

        boost::random::mt19937_64 rng(std::random_device{}());
        for (int i = 0; i < MILLERRABINITERATIONS; i++) {
            cpp_int a = boost::random::uniform_int_distribution<cpp_int>(2, n - 2)(rng);
            cpp_int x = powMod(a, d, n);
            if (x == 1 || x == n - 1) continue;

            bool isPrime = false;
            for (cpp_int r = 1; r < d; r *= 2) {
                x = powMod(x, 2, n);
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

