#!/bin/python

import math;

N = 600851475143
N = 137437904894

def isPrime(n):
  sqrt_n = int(math.sqrt(n))
  for i in range(2, sqrt_n+1):
    if (n % i == 0):
      return False
  return True

def largestPrimeFactorOfNumber(n):
  largest = -1
  sqrt_n = int(math.sqrt(n))
  for i in range(2, sqrt_n+1):
    if (n % i == 0):
      opposite = n/i
      if isPrime(opposite):
        return opposite
      if isPrime(i) and largest < i:
        largest = i;
  return largest;

def main():
  print largestPrimeFactorOfNumber(N);

if __name__ == '__main__':
  main()
