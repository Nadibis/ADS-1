// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;

    for (uint64_t i = 3; i <= value / i; i += 2) {
        if (value % i == 0) return false;
    }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t i = 0;
    uint64_t simple = 2;
    while (i <= n) {
        if (checkPrime(simple)) {
            i++;
            if (i == n) return simple;
        }
        simple++;
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
        while (true) {
            value++;
            if (checkPrime(value)) {
                return value;
            }
            break;
        }
    return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t simple = 2;
    uint64_t plus = 0;
    while (simple < hbound) {
        if (checkPrime(simple)) {
            plus+=simple;
        }
        simple++;
    }
    return plus;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t zapomni = lbound;
    uint64_t shet = 0;
    while (lbound < hbound) {
        if (checkPrime(lbound)) {
            if (lbound - zapomni == 2) {
                shet++;
            }
            zapomni = lbound;
        }
        lbound++;
    }
    return shet;
}
