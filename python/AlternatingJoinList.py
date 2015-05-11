# Combine two lists by alternatingly taking elements. For example: given the
# two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c,
# 3].


import random


def JoinLists(list_a, list_b):
  value = []
  for a, b in zip(list_a, list_b):
    value.append(a)
    value.append(b)
  return value


def main():
  number_of_numbers = 10
  number_range_upto = 1000
  numbers = [int(number_range_upto * random.random()) for _ in range(
      number_of_numbers)]
  character_range_upto = 26
  characters = [chr(int(character_range_upto * random.random(
      ) + 65)) for _ in range(number_of_numbers)]
  print numbers, characters, JoinLists(numbers, characters)


if __name__ == "__main__":
  main()
