"""
Problem

Given a list of space separated words, reverse the order of the words. Each line
of text contains L letters and W words. A line will only consist of letters and
space characters. There will be exactly one space character between each pair of
consecutive words.

Input

The first line of input gives the number of cases, N.
N test cases follow. For each test case there will a line of letters and space
characters indicating a list of space separated words. Spaces will not appear at
the start or end of a line.

Output

For each test case, output one line containing "Case #x: " followed by the list
of words in reverse order.
"""
import logging
import sys


def GetInputAndCalculate(logger):
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  number_of_cases = int(lines.pop(0))
  case_number = 1
  for line in lines:
    answer = " ".join(reversed(line.split()))
    print "Case #%d: %s" % (case_number, answer)
    case_number += 1


def main():
  logging.basicConfig(level=logging.INFO)
  logger = logging.getLogger(__name__)
  GetInputAndCalculate(logger)


if __name__ == "__main__":
  main()
