#ifndef MILLER_RABIN_HPP
#define MILLER_RABIN_HPP

#include <boost/multiprecision/cpp_int.hpp>

namespace fudmottin {
    const int MILLERRABINITERATIONS = 40;
    using boost::multiprecision::cpp_int;

    /**
     * Compute (base^exp) % mod using modular exponentiation.
     * @param base Base of the exponentiation.
     * @param exp Exponent.
     * @param mod Modulus.
     * @return Result of (base^exp) % mod.
     */
    cpp_int powMod(cpp_int base, cpp_int exp, const cpp_int& mod);

    /**
     * Perform the Miller-Rabin primality test on a given number.
     * @param n The number to test for primality.
     * @param iterations Number of test iterations to increase confidence.
     * @return True if n is probably prime, false otherwise.
     */
    bool millerRabinTest(const cpp_int& n, int iterations = MILLERRABINITERATIONS);

} // namespace fudmottin

#endif // MILLER_RABIN_HPP

