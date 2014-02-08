#!/bin/python

import math

def SumOfFactors(f_1, f_2):
  for key in f_2.keys():
    if (key in f_1):
      f_1[key] += f_2[key]
    else:
      f_1[key] = f_2[key]
  return f_1;

def PrimeFactorsOfNumber(n):
  sqrt_n = int(math.sqrt(n))
  if (n == sqrt_n * sqrt_n):
  # Perfect square
    return SumOfFactors(
        PrimeFactorsOfNumber(sqrt_n),
        PrimeFactorsOfNumber(sqrt_n))

  for i in range (2, sqrt_n+1):
    if (n % i == 0):
    # n isn't prime
      return SumOfFactors(
          PrimeFactorsOfNumber(i),
          PrimeFactorsOfNumber(n/i))

  # n is prime
  factors = {}
  factors[n] = 1
  return factors

def EvenlyDivisible(largest):
  prime_factors = {};
  for i in range (largest, 2, -1):
    prime_factors_i = PrimeFactorsOfNumber(i)
    print i, prime_factors_i
    for prime_factor in prime_factors_i.keys():
      value = prime_factors_i[prime_factor]
      if prime_factor in prime_factors:
        if value > prime_factors[prime_factor]:
          prime_factors[prime_factor] = value
          print prime_factor, value, prime_factors
      else:
        prime_factors[prime_factor] = value
        print prime_factor, value, prime_factors

  product = 1
  for prime_factor in prime_factors:
    value = prime_factors[prime_factor]
    product *= math.pow(prime_factor, value)

  return product

def main():
  print EvenlyDivisible(20);

if __name__ == '__main__':
  main()
