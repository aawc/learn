#!/bin/python

def LargestPalindromeProduct(start, end):
  # start is exclusive, end is inclusive
  largest = 0;
  for i in range(end, start, -1):
    if (largest > i*i):
      break
    for j in range(i, start, -1):
      product = i * j
      if largest < product:
        sproduct = str(product)
        if sproduct == sproduct[::-1]:
          largest = product
      else:
        break
  return largest

def main():
  print LargestPalindromeProduct(99, 999);

if __name__ == '__main__':
  main()
