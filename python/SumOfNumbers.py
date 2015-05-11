# Write three functions that compute the sum of the numbers in a given list
# using a for-loop, a while-loop, and recursion.

import random


def SumUsingFor(numbers):
  return sum([n for n in numbers])


def SumUsingWhile(numbers):
  count = 0
  total = 0
  while count < len(numbers):
    total += numbers[count]
    count += 1
  return total


def SumUsingRecursion(numbers):
  if numbers:
    return numbers[0] + SumUsingRecursion(numbers[1:])
  else:
    return 0


def main():
  number_of_numbers = 10
  number_range_upto = 1000
  numbers = [int(number_range_upto * random.random()) for _ in range(
      number_of_numbers)]
  sum_for = SumUsingFor(numbers)
  sum_while = SumUsingWhile(numbers)
  sum_recursive = SumUsingRecursion(numbers)
  print sum_for, sum_while, sum_recursive
  assert sum_for == sum_while
  assert sum_for == sum_recursive


if __name__ == "__main__":
  main()
