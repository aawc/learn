import random

LIMIT_MIN = -1
LIMIT_MAX = 1
ETA = 0.5
MAX_TRIALS = 1000


class PointLimit:
  def __init__(self, _min, _max):
    self.min = _min
    self.max = _max


class Point:
  def __init__(self, vector):
    if not vector:
      raise Exception("A point with no dimensions is point-less!")
    self.vector = vector

  def multiply(self, weights):
    prependedPoint = [1] + self.vector
    if len(prependedPoint) != len(weights):
      raise Exception ("Number of weights do not match the dimension.")
    sum = 0
    for index in range(len(prependedPoint)):
      sum += weights[index]*prependedPoint[index]
    return sum

  @staticmethod
  def random(dimensions = 2, limit=None):
    if not limit:
      limit = PointLimit(LIMIT_MIN, LIMIT_MAX)
    vector = []
    for index in range(dimensions):
      vector.append(random.uniform(limit.min, limit.max))
    return Point(vector)

  def __repr__(self):
    return str(self.vector)


class Model:
  def __init__(self, vector):
    if not vector:
      raise Exception("A model with no dimensions is a bad model!")
    self.vector = vector

  @staticmethod
  def random(dimensions = 2, limit=None):
    vector = []
    for index in range(dimensions):
      vector.append(Point.random(dimensions, limit))
    return Model(vector)

  def asVector(self):
    return self.vector

  def __repr__(self):
    displayString = "<"
    displayString += str(self.vector)
    displayString += ">"
    return displayString


def signOfNumber(number):
  if number > 0:
    return 1
  else:
    return -1


class PLAEstimation:
  def __init__(self, number_of_points, iterations, dimensions):
    self.X = PointLimit(LIMIT_MIN, LIMIT_MAX)
    self.number_of_points = number_of_points;
    self.dimensions = dimensions
    number_of_solved = 0
    total_trials = 0
    for iteration in range(iterations):
      #print "\nIteration %u:" % iteration
      self.solved = False
      self.model = Model.random(dimensions, self.X)
      #print "Model: %s" % self.model
      self.GenerateInitialWeights()
      self.GenerateRandomPoints()
      trials = 0
      while not self.solved and trials <= MAX_TRIALS:
        trials += 1
        self.solved = True
        random.shuffle(self.points)
        #print "Points: %s" % self.points
        self.ClassifyPoints()
        for index in range(len(self.points)):
          point = self.points[index]
          u = point.multiply(self.w)
          #print "%s classified as: %s" % (point, signOfNumber(u))
          if signOfNumber(u) != self.truth[index]:
            self.solved = False
            self.UpdateWeights(index)
            break
      total_trials += trials
      #print "Trials: %s" % (trials if self.solved else "Max'd out")
      if self.solved:
        number_of_solved += 1
        #print "Solution: %s" % self.w
    print "Solved: %f%%" % (number_of_solved * 100.0 / iterations)
    print "Average trials (N=%u): %f" % (number_of_points,
        total_trials * 1. / iterations)

  def UpdateWeights(self, index):
    point = self.points[index]
    calculated = point.multiply(self.w)
    prependedPoint = [1] + point.vector
    for dimension in range(len(prependedPoint)):
      self.w[dimension] = self.w[dimension] + ETA * (self.truth[index] -
          signOfNumber(calculated)) * prependedPoint[dimension]
    #print "Weights: %s" % self.w

  def GenerateInitialWeights(self):
    self.w = [0 for i in range(self.dimensions + 1)]
    #print "Weights: %s" % self.w

  def GenerateRandomPoints(self):
    self.points = [Point.random(self.dimensions, self.X) for i in
        range(self.number_of_points)]
    #print "Points: %s" % self.points

  def ClassifyPoints(self):
    if self.dimensions > 2:
      raise Exception ("Don't know how to calculate sides with dimension > 2.")

    self.truth = []
    d = self.model.asVector()
    for point in self.points:
      u = (d[0].vector[1]-d[1].vector[1])*(point.vector[0]-d[0].vector[0]) + \
          (d[1].vector[0]-d[0].vector[0])*(point.vector[1]-d[0].vector[1])
      self.truth.append(signOfNumber(u))
    #print self.truth


if __name__ == "__main__":
  pla = PLAEstimation(number_of_points = 10, iterations = 1000, dimensions = 2)
  pla = PLAEstimation(number_of_points = 100, iterations = 1000, dimensions = 2)
