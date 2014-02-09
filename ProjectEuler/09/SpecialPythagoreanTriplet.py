#!/bin/python

def IsPythagoreanTriplet(a, b, c):
  if (a*a == b*b + c*c) or (b*b == c*c + a*a) or (c*c == a*a + b*b):
    return True

def SpecialPythagoreanTriplet(limit):
  for a in range (1, limit+1):
    b_limit = limit - a
    for b in range(1, b_limit + 1):
      c = b_limit - b
      if IsPythagoreanTriplet(a, b, c):
          return a * b * c
  return -1

def main():
  LIMIT = 1000
  print SpecialPythagoreanTriplet(LIMIT);

if __name__ == '__main__':
  main()
