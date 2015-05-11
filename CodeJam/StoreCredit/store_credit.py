# https://code.google.com/codejam/contest/351101
# You receive a credit C at a local store and would like to buy two items. You
# first walk through the store and create a list L of all available items. From
# this list you would like to buy two items that add up to the entire value of
# the credit. The solution you provide will consist of the two integers
# indicating the positions of the items in your list (smaller number first).

import logging
import sys


def GetItemsForCredit(credit, values):
  sorted_values = sorted(values)
  i = 0
  j = len(sorted_values) - 1
  while i <= j:
    a = sorted_values[i]
    b = sorted_values[j]
    current_sum = a[0] + b[0]
    if current_sum == credit:
      return a[1], b[1]
    elif current_sum < credit:
      i += 1
    else:
      j -= 1
  raise ValueError()


def GetInputAndCalculate(logger):
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  number_of_cases = int(lines.pop(0))
  case_number = 0
  credit = None
  number_of_items = None
  items = []
  for line in lines:
    if credit is None:
      credit = int(line)
    elif number_of_items is None:
      number_of_items = int(line)
    else:
      case_number += 1
      items = [int(x) for x in line.split()]
      values = [(value, index) for (index, value) in enumerate(items)]
      logger.debug("credit: %s" % credit)
      logger.debug("number_of_items: %s" % number_of_items)
      logger.debug("items: %s" % items)
      logger.debug("values: %s" % values)
      index_1, index_2 = GetItemsForCredit(credit, values)
      index_1, index_2 = min(index_1, index_2) + 1, max(index_1, index_2) + 1
      print "Case #%d: %d %d" % (case_number, index_1, index_2)
      # Reset the values to be read for the next case.
      credit = None
      number_of_items = None
      items = []

def main():
  logging.basicConfig(level=logging.INFO)
  logger = logging.getLogger(__name__)
  GetInputAndCalculate(logger)


if __name__ == "__main__":
  main()
