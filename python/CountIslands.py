# Find the number of islands
# Given a boolean 2D matrix, find the number of islands.
# http://www.geeksforgeeks.org/find-number-of-islands/

import random


def GetOneDIndex(columns, row, col):
    return row*columns + col


def IslandNumber(cell_to_island, columns, row, col):
    if row < 0 or col < 0:
        return 0
    cell_1d_index = GetOneDIndex(columns, row, col)
    return cell_to_island.get(cell_1d_index, 0)


def GetNumberOfIslands(data, columns):
    map_island_to_cells = {}
    cell_to_island = {}
    next_island = 1
    for row in range(len(data)):
        for col in range(len(data[row])):
            cell_1d_index = GetOneDIndex(columns, row, col)
            if not data[row][col]:
                continue
            left_island = IslandNumber(cell_to_island, columns, row, col-1)
            top_island = IslandNumber(cell_to_island, columns, row-1, col)
            if not left_island and not top_island:
                # First land in the island with no connection to left and top.
                map_island_to_cells[next_island] = set([cell_1d_index])
                cell_to_island[cell_1d_index] = next_island
                next_island += 1
                print map_island_to_cells, cell_to_island
            elif left_island == top_island:
                # Both left and top share the same island already.
                map_island_to_cells[left_island].add(cell_1d_index)
                cell_to_island[cell_1d_index] = left_island
                print map_island_to_cells, cell_to_island
            elif not left_island and top_island:
                # Top is island, but left is not. Join top.
                map_island_to_cells[top_island].add(cell_1d_index)
                cell_to_island[cell_1d_index] = top_island
                print map_island_to_cells, cell_to_island
            elif left_island and not top_island:
                # Left is island, but top is not. Join left.
                map_island_to_cells[left_island].add(cell_1d_index)
                cell_to_island[cell_1d_index] = left_island
                print map_island_to_cells, cell_to_island
            else:
                # Both left and top are islands. Join all of them into the lower
                # one.
                lower_island = min(left_island, top_island)
                upper_island = max(left_island, top_island)
                map_island_to_cells[lower_island].add(cell_1d_index)
                cell_to_island[cell_1d_index] = lower_island
                # For all the elements in the upper_island, move them to the
                # lower island.
                for cell_1d_index_upper in map_island_to_cells[upper_island]:
                    cell_to_island[cell_1d_index_upper] = lower_island
                map_island_to_cells[lower_island].update(
                    map_island_to_cells[upper_island])
                del map_island_to_cells[upper_island]
                print map_island_to_cells, cell_to_island
    return len(map_island_to_cells)


def main():
    rows = random.randint(1, 10)
    cols = random.randint(1, 10)
    data = [[random.randint(0, 1) for _ in range(cols)] for _ in range(rows)]
    print '\n'.join([''.join(['{:4}'.format(i) for i in r]) for r in data])
    print GetNumberOfIslands(data, cols)


if __name__ == '__main__':
    main()
