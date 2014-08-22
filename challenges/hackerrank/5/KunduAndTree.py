"""
A module to solve the problem specified at:
    https://www.hackerrank.com/contests/w5/challenges/kundu-and-tree

Kundu is true tree lover. Tree is a connected graph having N vertices and N-1
edges. Today when he got a tree, he colored each edge with one of either red(r)
or black(b) color. He is interested in knowing how many triplets(a,b,c) of
vertices are there , such that, there is atleast one edge having red color on
all the three paths i.e. from vertex a to b, vertex b to c and vertex c to a .
Note that (a,b,c), (b,a,c) and all such permutations will be considered as the
same triplet.

If the answer is greater than 10^9 + 7, print the answer modulo (%) 10^9 + 7.

Input Format
The first line contains an integer N, i.e., the number of vertices in tree.
The next N-1 lines represent edges: 2 space separated integers denoting an edge
followed by a color of the edge. A color of an edge is denoted by a small letter
of English alphabet, and it can be either red(r) or black(b).

Output Format
Print a single number i.e. the number of triplets.

Constraints
1 <= N <= 105
A node is numbered between 1 to N.

Sample Input

5
1 2 b
2 3 r
3 4 r
4 5 b

Sample Output

4

Explanation

Given tree is something like this:
    1 -- B -- 2 == R == 3 == R == 4 -- B -- 5

(2,3,4) is one such triplet because on all paths i.e 2 to 3, 3 to 4 and 2 to 4
there is atleast one edge having red color.
(2,3,5), (1,3,4) and (1,3,5) are other such triplets.
Note that (1,2,3) is NOT a triplet, because the path from 1 to 2 does not have
an edge with red color.

"""

import copy


# pylint: disable=bad-builtin
def main():
    """
    Ugh, pylint, this is for you!
    """
    num_vertices = long(raw_input())
    if num_vertices <= 1:
        return 0

    store = {}
    for i in range(num_vertices):
        store[i+1] = {}

    num_edges = num_vertices - 1
    for i in range(num_edges):
        first, second, color = raw_input().split(" ")
        first = int(first)
        second = int(second)
        if first > second:
            first, second = second, first
        elif first == second or color not in ['b', 'r']:
            print "Invalid input!"
        store[first][second] = color
    print "Here's the input:"
    print store

    print "Extending the store to include one-hop relations:"
    extend_color_connections(store)

    print "Here's the extended store (after combining one-hop relations):"
    print store

    print "Here are the triplets:"
    locate_triplets(store)

    print "Here's the store one final time:"
    print store


def extend_color_connections(store):
    """
    Extends the connections to beyond one hop.
    """
    # When creating the dictionary, we ensured that the smaller vertex was on
    # the left. This means that if we go from the largest vertex number to the
    # smallest, we'll always have all our connections evaluated already.
    # For vertices 1-5, look for all one hop relations starting with 5. There'll
    # be none. Then look at 4. It'll have an entry for 5, at most, if any, which
    # we have already solved for. Then 3, which can have 4 and 5 as siblings,
    # but we have solved for them already. And so on, it goes.
    # TL;DR: Start from the reverse of keys/vertices.
    for first in sorted(store.keys())[::-1]:
        connections = store[first]
        new_connections = copy.deepcopy(connections)
        # Iterate over all the vertices this node is connected to. These will
        # always be greater than the vertex itself.
        for second in new_connections:
            # Iterate over the connection's connections to see if we can find
            # any new paths.
            fs_color = store[first][second]
            for third in store[second]:
                # third is a vertex that second is connected to.
                # The color of the path between first and third is red if:
                # 1. first and second already have a red path, OR
                # 2. first and third already have a red path, OR
                # 3. second and third have a red path.
                ft_color = store[first].get(third, "b")
                st_color = store[second][third]
                print first, second, third, fs_color, ft_color, st_color
                is_new_color_red = (
                        fs_color == "r" or ft_color == "r" or st_color == "r")
                store[first][third] = "r" if is_new_color_red else "b"


def locate_triplets(store):
    """
    Locates the triplets in the store.
    """
    count = 0
    for first in sorted(store.keys()):
        for second in sorted(store[first].keys()):
            fs_color = store[first][second]
            if fs_color == "r":
                for third in sorted(store[second].keys()):
                    ft_color = store[first][third]
                    st_color = store[second][third]
                    print first, second, third, fs_color, ft_color, st_color
                    if st_color == "r" and ft_color == "r":
                        print "(", first, second, third, ")"
                        count += 1
    print count


if __name__ == "__main__":
    main()
