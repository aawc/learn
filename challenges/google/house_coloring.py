import random

def AssignColor(current_state, current_cost, house_num, lowest_cost,
                lowest_state, colors, costs):
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
      if (new_cost < lowest_cost):
        new_state = current_state + color
        tree_lowest_cost, tree_lowest_state = AssignColor(
                new_state, new_cost, house_num+1, lowest_cost, lowest_state,
                colors, costs)
        if tree_lowest_cost < lowest_cost:
          lowest_cost = tree_lowest_cost
          lowest_state = tree_lowest_state
  return lowest_cost, lowest_state

def main():
  colors = ["R", "G", "B"]
  number_of_houses = 5
  max_value = 10
  costs = {}
  for house_num in range(number_of_houses):
    costs[house_num] = {}
    for index, color in enumerate(colors):
      costs[house_num][color] = random.randint(1, max_value)
      #costs[house_num][color] = index
  print costs
  print AssignColor("", 0, 0, 10000, "", colors, costs)


if __name__ == "__main__":
  main()
