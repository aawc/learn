#!/bin/python

def multipleOf3Or5(number):
  if (number % 3 == 0):
    return True
  elif (number % 5 == 0):
    return True
  return False

def findAllMultiplesOf3Or5Upto(number):
  sum = 0;
  for i in range(number):
    if multipleOf3Or5(i):
      sum += i;
  return sum

def main():
  print findAllMultiplesOf3Or5Upto(1000)

if '__main__' == __name__:
  main();
