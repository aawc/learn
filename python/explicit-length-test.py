"""
Checks the if not test on various empty values to see their behavior.
"""

import logging

def main():
  logging.basicConfig(level=logging.DEBUG)
  values = [[], None, ""]
  for value in values:
    logging.debug(value)
    logging.debug(not value)


if __name__ == '__main__':
  main()
