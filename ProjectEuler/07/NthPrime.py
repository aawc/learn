#!/bin/python

import math

def isPrime(n):
  sqrt_n = int(math.sqrt(n))
  for i in range(2, sqrt_n+1):
    if (n % i == 0):
      return False
  return True

def NthPrime(n):
  found = False;
  count = 0;
  i = 1;
  while count < n:
    i += 1;
    if (isPrime(i)):
      count += 1
  return i

def main():
  N = 10001
  print NthPrime(N)

if __name__ == '__main__':
  main()
