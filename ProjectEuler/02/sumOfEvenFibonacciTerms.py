#!/bin/python

N = 4000000

def getNthFibonacciNumber(termNminus1, termN):
  return termNminus1 + termN

def sumEvenFibonacciTerms(n):
  term1 = 1
  term2 = 2
  term3 = getNthFibonacciNumber(term2, term1)
  total = term2;
  while term3 < n:
    if (term3 % 2 == 0):
      total += term3
    term1 = term2
    term2 = term3
    term3 = getNthFibonacciNumber(term1, term2)

  return total

def main():
  print sumEvenFibonacciTerms(N)

if __name__ == '__main__':
  main();
