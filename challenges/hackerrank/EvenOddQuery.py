"""
A module to solve the problem specified at:
    https://www.hackerrank.com/contests/w5/challenges/even-odd-query

You are given an array A of size N. You are also given an integer Q. Can you
figure out the answer to each of the Q queries?

Each query contains 2 integers x and y, and you need to find whether the value
find(x,y) is odd or even:

find(int x,int y)
{
    if(x>y) return 1;
    ans = pow(A[x],find(x+1,y))
    return ans
}

Sample Input
3
3 2 7
2
1 2
2 3

Sample Output
Odd
Even
"""


# pylint: disable=invalid-name
# pylint: disable=bad-builtin
def find(array, x, y):
    """
    The crux function
    """
    if x > y:
        return 1
    out = array[x] ** (1 if array[x+1] else 0)
    return out


def isOdd(number):
    """
    Returns whether the provided argument is an odd-number i.e. divisible by 2.
    """
    return number % 2 == 1


def getOddOrEvenLabel(numberIsOdd):
    """
    Returns "Odd" if numberIsOdd argument is True; "Even" otherwise.
    """
    return "Odd" if numberIsOdd else "Even"


def main():
    """
    Ugh, pylint, this is for you!
    """
    n = long(raw_input())
    if n <= 0:
        return
    array = map(long, raw_input().split(" "))
    n = long(raw_input())
    if n <= 0:
        return
    pairs = []
    for _ in range(n):
        x, y = raw_input().split(" ")
        pairs.append({'x': long(x), 'y': long(y)})
    for pair in pairs:
        x = pair['x']
        y = pair['y']
        numberIsOdd = isOdd(find(array, x-1, y-1))
        print getOddOrEvenLabel(numberIsOdd)


if __name__ == "__main__":
    main()
