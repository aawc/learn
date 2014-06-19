"""Solution for the house coloring question some companies ask.

Details:
There are N houses in a row. Each house can be painted in either Red, Green or
Blue color. The cost of coloring each house in each of the colors is different.

Find the color of each house such that no two adjacent house have the same color
and the total cost of coloring all the houses is minimum.
"""

import random
import sys

def assign_color(
    costs, colors, current_state="", current_cost=0, house_num=0,
    lowest_cost=sys.maxint, lowest_state=None):
  """
  This method computes the state that would lead to the lowest cost for house N,
  given a configuration of houses 0:N-1.

  For each possible color house N can be in, it computes all its child nodes as
  long as the cost of painting is lower than a known lowest value.

  If at any point, the total cost of painting house N with a color goes over the
  lowest known cost, it completely abandons that color for that house (and
  therefore, all houses down the line).
  """
  # If it's the last house on the street, we have found a new lowest cost
  # sequence.
  if house_num == len(costs):
    return current_cost, current_state
  # Iterate over all the colors for this house.
  for color in colors:
    # Ignore the color of the previous house.
    if house_num == 0 or color != current_state[house_num - 1]:
      # Get the cost of coloring this house in this color.
      unit_color_cost = costs[house_num][color]
      # If the cost of coloring this house in this color is higher than
      # known lowest value, don't go further down.
      new_cost = current_cost + unit_color_cost
      if new_cost < lowest_cost:
        new_state = current_state + color
        tree_lowest_cost, tree_lowest_state = assign_color(
            costs, colors, new_state, new_cost, house_num+1, lowest_cost,
            lowest_state)
        if tree_lowest_cost < lowest_cost:
          lowest_cost = tree_lowest_cost
          lowest_state = tree_lowest_state
  return lowest_cost, lowest_state


def main():
  """
  The main method.
  """
  colors = ["R", "G", "B"]
  number_of_houses = 5
  max_value = 10
  costs = {}
  for house_num in range(number_of_houses):
    costs[house_num] = {}
    for color in enumerate(colors):
      costs[house_num][color] = random.randint(1, max_value)
  print costs
  print assign_color(costs, colors)


if __name__ == "__main__":
  main()
