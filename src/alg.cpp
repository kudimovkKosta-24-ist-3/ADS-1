// Copyright 2023 Your Name
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t i = 2; i * i <= value; ++i) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t num = 2;
  while (count < n) {
    if (checkPrime(num)) {
      ++count;
    }
    ++num;
  }
  return num - 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
  while (true) {
    if (checkPrime(num)) {
      return num;
    }
    ++num;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  uint64_t prevPrime = 0;

  // Инициализируем prevPrime первым простым числом в диапазоне
  for (uint64_t i = lbound; i < hbound; ++i) {
    if (checkPrime(i)) {
      prevPrime = i;
      break;
    }
  }

  // Считаем пары близнецов
  for (uint64_t i = prevPrime + 1; i < hbound; ++i) {
    if (checkPrime(i)) {
      if (i - prevPrime == 2) {
        ++count;
      }
      prevPrime = i;
    }
  }

  return count;
}
