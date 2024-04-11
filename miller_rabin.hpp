#ifndef MILLER_RABIN_HPP
#define MILLER_RABIN_HPP

#include <boost/multiprecision/cpp_int.hpp>

namespace fudmottin {

    boost::multiprecision::cpp_int powMod(boost::multiprecision::cpp_int base,
                                          boost::multiprecision::cpp_int exp,
                                          const boost::multiprecision::cpp_int& mod);

    bool millerRabinTest(const boost::multiprecision::cpp_int& n);

} // namespace fudmottin

#endif // MILLER_RABIN_HPP

