"""
Problem
You are given two vectors v1=(x1,x2,...,xn) and v2=(y1,y2,...,yn). The scalar
product of these vectors is a single number, calculated as x1y1+x2y2+...+xnyn.

Suppose you are allowed to permute the coordinates of each vector as you wish.
Choose two permutations such that the scalar product of your two new vectors is
the smallest possible, and output that minimum scalar product.

Input
The first line of the input file contains integer number T - the number of test
cases. For each test case, the first line contains integer number n. The next
two lines contain n integers each, giving the coordinates of v1 and v2
respectively.


Output
For each test case, output a line
Case #X: Y
where X is the test case number, starting from 1, and Y is the minimum scalar
product of all permutations of the two given vectors.
"""

import logging
import sys


def CalculateMSP(logger, l1, l2, level=0):
  l1 = [int(x) for x in l1]
  l2 = [int(x) for x in l2]
  result = 0
  for a, b in zip(sorted(l1), reversed(sorted(l2))):
    result += a*b
  logger.debug('result: %s' % result)
  return result


def GetInputAndCalculate(logger):
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  number_of_cases = int(lines.pop(0))
  case_number = 1
  total = l1 = l2 = None
  for line in lines:
    line = line.strip()
    logging.debug('line: %s' % line)
    if total is None:
      total = int(line)
      logger.debug('total: %s' % total)
    elif l1 is None:
      l1 = line.split()
      logger.debug('l1: %s' % l1)
    else:
      l2 = line.split()
      logger.debug('l2: %s' % l2)
      print 'Case #%d: %d' % (case_number, CalculateMSP(logger, l1, l2))
      case_number += 1
      # Reset
      total = l1 = l2 = None


def main():
  logging.basicConfig(level=logging.INFO)
  logger = logging.getLogger(__name__)
  GetInputAndCalculate(logger)


if __name__ == '__main__':
  main()
