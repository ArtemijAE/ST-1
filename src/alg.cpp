// Copyright 2025 UNN-CS
#include <cstdint>
#include <cmath>
#include <limits>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value <= 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;

  uint64_t limit = static_cast<uint64_t>(std::sqrt(value)) + 1;
  for (uint64_t i = 5; i <= limit; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  uint64_t count = 0;
  uint64_t candidate = 1;
  while (count < n) {
    candidate++;
    if (checkPrime(candidate)) {
      count++;
    }
  }
  return candidate;
}

uint64_t nextPrime(uint64_t value) {
  if (value == UINT64_MAX) {
    return 0;
  }
  uint64_t candidate = value + 1;
  while (!checkPrime(candidate)) {
    candidate++;
    if (candidate == 0) {
      return 0;
    }
  }
  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}