# Write a function that computes the list of the first 100 Fibonacci numbers. By
# definition, the first two numbers in the Fibonacci sequence are 0 and 1, and
# each subsequent number is the sum of the previous two. As an example, here are
# the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.


def GetFirstNFibonacciNumbers(number_of_numbers):
  if number_of_numbers < 0:
    raise ValueError()
  elif number_of_numbers == 1:
    return [0]
  elif number_of_numbers == 2:
    return [0, 1]
  else:
    previous = GetFirstNFibonacciNumbers(number_of_numbers - 1)
    length = len(previous)
    assert length >= 2
    return previous + [previous[length-1] + previous[length-2]]


def main():
  number_of_numbers = 0
  try:
    print GetFirstNFibonacciNumbers(number_of_numbers)
  except ValueError:
    pass
  else:
    assert False
  number_of_numbers = 1
  print GetFirstNFibonacciNumbers(number_of_numbers)
  number_of_numbers = 2
  print GetFirstNFibonacciNumbers(number_of_numbers)
  number_of_numbers = 10
  print GetFirstNFibonacciNumbers(number_of_numbers)


if __name__ == "__main__":
  main()
