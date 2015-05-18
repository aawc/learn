"""
Problem
In this problem, you have to find the last three digits before the decimal point
for the number (3 + square_root(5))n.

  For example, when n = 5, (3 + square_root(5))5 = 3935.73982...
  The answer is 935.
  For n = 2, (3 + square_root(5))2 = 27.4164079...
  The answer is 027.

Input
The first line of input gives the number of cases, T. T test cases follow, each
on a separate line. Each test case contains one positive integer n.

Output
For each input case, you should output:

  Case #X: Y
  where X is the number of the test case and Y is the last three integer digits
  of the number (3 + square_root(5))n. In case that number has fewer than three
  integer digits, add leading zeros so that your output contains exactly three
  digits.
"""

import decimal
import logging
import sys


logging.basicConfig(level=logging.DEBUG)
_logger = logging.getLogger(__name__)


class Memoize:
  def __init__(self, f):
    self.f = f
    self.memo = {}
  def __call__(self, *args):
    if not args in self.memo:
      self.memo[args] = self.f(*args)
    return self.memo[args]


def Factorial(r):
  product = 1
  for i in range(2, r+1):
    product *= i
  return product
Factorial = Memoize(Factorial)


def Combination(n, r):
  n_r = n - r
  r, n_r = min(r, n_r), max(r, n_r)
  numerator = 1
  for i in range(n_r+1, n+1):
    numerator *= i
  denominator = Factorial(r)
  result = numerator / denominator
  return result
Combination = Memoize(Combination)


def CalculatePower(n, a, b, b_squared, last_digits):
  _logger.debug('n: %d, a: %d, b: %s, b_squared: %s, last_digits: %d',
      n, a, repr(b), repr(b_squared), last_digits)
  final_coefficient_of_b = 0
  partial_sum = 0
  for power_of_b in range(n+1):
    power_of_a = n - power_of_b
    _logger.debug('power_of_a: %d, power_of_b: %d', power_of_a, power_of_b)
    total_coefficient = Combination(n, power_of_b)
    total_coefficient *= a**power_of_a
    total_coefficient *= b_squared ** int(power_of_b/2)
    _logger.debug('total_coefficient: %d', total_coefficient)
    total_coefficient %= 10 ** (2*last_digits)
    _logger.debug('total_coefficient: %d', total_coefficient)
    if power_of_b % 2:
      final_coefficient_of_b += total_coefficient
      _logger.debug('final_coefficient_of_b: %d', final_coefficient_of_b)
    else:
      partial_sum += total_coefficient
      _logger.debug('partial_sum: %d', partial_sum)

  _logger.debug('partial_sum: %d, final_coefficient_of_b: %d, b_squared: %f',
      partial_sum, final_coefficient_of_b, b_squared)
  result = partial_sum + final_coefficient_of_b * b
  result %= 10**last_digits
  _logger.debug('result: %f', result)
  return str(int(result)).zfill(3)


def GetInputAndCalculate():
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  unused_number_of_cases = int(lines.pop(0))
  case_number = 1
  # Number of digits we care about before decimal
  last_digits = 3
  for line in lines:
    line = line.strip()
    _logger.debug('line: %s' % line)
    n = int(line)
    _logger.debug('n: %d' % n)
    a = 3
    b_squared = 5
    half = decimal.Decimal(1/2.0)
    b = decimal.Decimal(b_squared ** half)
    print 'Case #%d: %s' % (case_number, CalculatePower(
      n, a, b, b_squared, last_digits))
    case_number += 1


def main():
  GetInputAndCalculate()


if __name__ == '__main__':
  main()
