"""
URL:
http://www.glassdoor.com/Interview/There-is-a-museum-organized-as-NxN-room-Some-rooms-are-locked-and-inaccessible-Other-rooms-are-open-and-some-rooms-have-g-QTN_68236.htm

Problem

There is a museum organized as NxN room. Some rooms are locked and inaccessible.
Other rooms are open and some rooms have guards. Guards can only move north,
south, east and west, only through open rooms and only within the museum.

For each room, find the shortest distance to a guard. What is the time
complexity of your algorithm?
"""
import sys


def ParseInput():
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  number_of_rows = int(lines.pop(0))
  museum = []
  guards = set()
  for row_number, row in enumerate(lines):
    row = row.strip()
    output_row = []
    for column_number, cell in enumerate(list(row)):
      if cell == '#':
        value = -2
      elif cell == 'G':
        value = 0
        guards.add((row_number, column_number))
      else:
        value = -1
      output_row.append(value)
    museum.append(output_row)
  return number_of_rows, museum, guards


def UpdateGuardScore(museum, number_of_rows, row_number, column_number):
  #print museum, number_of_rows, row_number, column_number
  assert (row_number < number_of_rows and column_number < number_of_rows)
  cell_value = museum[row_number][column_number]
  if cell_value == -2:
    # Can't proceed past a locked room.
    return
  cell_left = (row_number, column_number - 1)
  cell_right = (row_number, column_number + 1)
  cell_top = (row_number - 1, column_number)
  cell_bottom = (row_number + 1, column_number)
  neighbors = [cell_left, cell_right, cell_top, cell_bottom]
  for neighbor in neighbors:
    neighbor_row = neighbor[0]
    neighbor_col = neighbor[1]
    if neighbor_row >= 0 and neighbor_row < number_of_rows and (
        neighbor_col >= 0 and neighbor_col < number_of_rows):
      neighbor_value = museum[neighbor_row][neighbor_col]
      if neighbor_value > (cell_value + 1) or neighbor_value == -1:
        museum[neighbor_row][neighbor_col] = cell_value + 1
        UpdateGuardScore(museum, number_of_rows, neighbor_row, neighbor_col)


def main():
  number_of_rows, museum, guards = ParseInput()
  print 'Input: \n%s' % (
      '\n'.join([''.join(['{:4}'.format(i) for i in r]) for r in museum]))
  for guard in guards:
    guard_row = guard[0]
    guard_col = guard[1]
    UpdateGuardScore(museum, number_of_rows, guard_row, guard_col)
  print 'Output: \n%s' % (
      '\n'.join([''.join(['{:4}'.format(i) for i in r]) for r in museum]))


if __name__ == '__main__':
  main()
