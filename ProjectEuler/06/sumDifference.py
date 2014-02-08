#!/bin/python

def SumDifference(n):
  sum_to_n = n * (n + 1) / 2
  square_of_sum_to_n = sum_to_n * sum_to_n
  sum_of_squares = n * (n + 1) * (2*n + 1) / 6
  return square_of_sum_to_n - sum_of_squares

def main():
  N = 100
  print SumDifference(N)

if __name__ == '__main__':
  main()
