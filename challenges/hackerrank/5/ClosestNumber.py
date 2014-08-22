"""
A module to solve the problem specified at:
    https://www.hackerrank.com/contests/w5/challenges/closest-number

You are given 3 numbers a, b and x. You need to output the multiple of x which
is closest to a^b. If more than one answer exists , display the smallest one.

Input Format
The first line contains T, the number of testcases.
T lines follow, each line contains 3 space separated integers (a, b and x
respectively)

Output Format
For each test case , output the multiple of x which is closest to ab

Constraints
1 <= T <= 10^5
1 <= x <= 10^9
0 < ab <= 10^9
1 <= a <= 10^9
-10^9 <= b <= 10^9

Sample Input

3
349 1 4
395 1 7
4 -2 2

Sample Output

348
392
0

Explanation

The closest multiple of 4 to 349 is 348.
The closest multiple of 7 to 395 is 392.
The closest multiple of 2 to 1/16 is 0.
"""


# pylint: disable=bad-builtin
def main():
    """
    Ugh, pylint, this is for you!
    """
    num_tests = long(raw_input())
    if num_tests <= 0:
        return
    for _ in range(num_tests):
        base, exponent, divisor = map(long, raw_input().split(" "))
        print find_closest(base, exponent, divisor)


def find_closest(base, exponent, divisor):
    """
    Finds the solution for the given arguments.
    """
    out = base ** exponent
    remainder = out % divisor
    if remainder <= divisor/2:
        return divisor * int(out / divisor)
    else:
        return divisor * (1 + int(out / divisor))


if __name__ == "__main__":
    main()
