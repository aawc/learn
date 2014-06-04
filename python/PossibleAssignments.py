def factorial(n):
  if n < 0:
    raise Exception("Can't calculate the factorial of a negative number")
  elif n == 0:
    return 1
  else:
    return n * factorial(n-1)

def combination(m, n):
  return factorial(m)/(factorial(n) * factorial(m-n))

def main():
  n = 5
  print "Ways to assign 2n people in 2 sets of n each is: ", combination(2*n, n)

if __name__ == "__main__":
  main()
