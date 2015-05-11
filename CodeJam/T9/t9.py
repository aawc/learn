"""
Problem

The Latin alphabet contains 26 characters and telephones only have ten digits on
the keypad. We would like to make it easier to write a message to your friend
using a sequence of keypresses to indicate the desired characters. The letters
are mapped onto the digits as shown below. To insert the character B for
instance, the program would press 22. In order to insert two characters in
sequence from the same key, the user must pause before pressing the key a second
time. The space character ' ' should be printed to indicate a pause. For
example, 2 2 indicates AA whereas 22 indicates B.


Input

The first line of input gives the number of cases, N. N test cases follow. Each
case is a line of text formatted as
desired_message
Each message will consist of only lowercase characters a-z and space characters
' '. Pressing zero emits a space.


Output

For each test case, output one line containing "Case #x: " followed by the
message translated into the sequence of keypresses.
"""

import logging
import sys

MAP = {
    'a': '2',
    'b': '22',
    'c': '222',
    'd': '3',
    'e': '33',
    'f': '333',
    'g': '4',
    'h': '44',
    'i': '444',
    'j': '5',
    'k': '55',
    'l': '555',
    'm': '6',
    'n': '66',
    'o': '666',
    'p': '7',
    'q': '77',
    'r': '777',
    's': '7777',
    't': '8',
    'u': '88',
    'v': '888',
    'w': '9',
    'x': '99',
    'y': '999',
    'z': '9999',
    ' ': '0'
}


def GetInputAndCalculate(logger):
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  number_of_cases = int(lines.pop(0))
  case_number = 1
  for line in lines:
    logging.debug('line: %s' % line)
    answer = ''
    previous = None
    for char in line:
      converted = MAP.get(char, '')
      if previous and converted and previous[0] == converted[0]:
        answer += ' '
      answer += converted
      previous = converted
    logging.debug(answer)
    print 'Case #%d: %s' % (case_number, answer)
    case_number += 1


def main():
  logging.basicConfig(level=logging.INFO)
  logger = logging.getLogger(__name__)
  GetInputAndCalculate(logger)


if __name__ == '__main__':
  main()
