# Length of the longest substring without repeating characters
# http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

# Given a string, find the length of the longest substring without repeating
# characters. For example, the longest substrings without repeating characters
# for "ABDEFGABEF" are "BDEFGA" and "DEFGAB", with length 6. For "BBBB" the
# longest substring is "B", with length 1.

import logging
import sys


def FindLongestNonRepeatingSubstring(line):
  if not line:
    return ""
  last_nr_position = {}
  current_start = 0
  longest_min = 0
  longest_max = 0
  current_position = 0
  for current_position in xrange(len(line)):
    char = line[current_position]
    last_position = last_nr_position.get(char, None)
    if last_position is not None and last_position >= current_start:
      longest_min, longest_max = GetLongestMinMax(
          current_position, current_start, longest_min, longest_max)
      current_start = last_position + 1
    last_nr_position[char] = current_position
  longest_min, longest_max = GetLongestMinMax(
      current_position, current_start, longest_min, longest_max)
  return line[longest_min : longest_max+1]


def GetLongestMinMax(current_position, current_start, longest_min, longest_max):
  current_seq_length = (current_position - 1) - current_start
  if current_seq_length > (longest_max-longest_min):
    longest_min = current_start
    longest_max = current_position -1
  return longest_min, longest_max


def GetInputAndCalculate(logger):
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  for line in lines:
    line = line.strip()
    if line:
      logging.debug('line: %s' % line)
      longest_nr_sub = FindLongestNonRepeatingSubstring(line)
      print 'Longest non-repeating substring in %s: %s' % (line, longest_nr_sub)

def main():
  logging.basicConfig(level=logging.INFO)
  logger = logging.getLogger(__name__)
  GetInputAndCalculate(logger)

if __name__ == "__main__":
  main()
