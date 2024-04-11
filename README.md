# Miller_Rabin
An implementation of the Miller-Rabin primality test in C++ using Boost libraries
# Miller_Rabin

This repository contains a C++ implementation of the Miller-Rabin primality test, leveraging the Boost libraries for extended precision arithmetic and random number generation. The Miller-Rabin test is a probabilistic test to determine if a number is a prime. It's an efficient algorithm suitable for large numbers, especially when used in cryptographic applications.

## Features

- Utilizes Boost's `multiprecision` library to handle very large integers.
- Implements a robust version of the Miller-Rabin primality test for high accuracy.

## Getting Started

### Prerequisites

- A modern C++ compiler supporting C++20 (e.g., GCC, Clang)
- The Boost libraries, specifically `boost/multiprecision` and `boost/random`

### Installation

1. **Clone the repository:**

```bash
git clone https://github.com/Fudmottin/Miller_Rabin.git
```

## Usage

```cpp
#include "miller_rabin.hpp"

int main() {
    boost::multiprecision::cpp_int n = "your_large_number_here";
    bool isPrime = fudmottin::millerRabinTest(n);

    if (isPrime) {
        std::cout << n << " is prime." << std::endl;
    } else {
        std::cout << n << " is not prime." << std::endl;
    }

    return 0;
}
```

##License

This project is licensed under the MIT License - see the LICENSE file for details.
