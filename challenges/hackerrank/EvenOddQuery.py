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
def findIsOdd(array, x, y):
    """
    The crux function
    """
    if x > y:
        return True
    # We could call the following function, but I don't think we need to:
    # return isOdd(math.pow(array[x], find(array, x+1, y)))
    return isOdd(array[x])


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
    array = []
    n = input("Enter array size: ")
    if n <= 0:
        return
    print "Enter {0} positive integers:".format(n)
    for _ in range(n):
        array.append(input())
    n = input("Enter the number of pairs: ")
    if n <= 0:
        return
    pairs = []
    print "Enter {0} pairs:".format(n)
    for _ in range(n):
        x = input()
        y = input()
        pairs.append({'x': x, 'y': y})
    print pairs
    for pair in pairs:
        x = int(pair['x'] - 1)
        y = int(pair['y'] - 1)
        numberIsOdd = findIsOdd(array, x, y)
        print x, y, getOddOrEvenLabel(numberIsOdd)


if __name__ == "__main__":
    main()
