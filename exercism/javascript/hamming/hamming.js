var hamming = function() {};

hamming.compute = function(strandOne, strandTwo) {
  if (strandOne.length !== strandTwo.length) {
    throw new Error('DNA strands must be of equal length.');
  }
  var differences = 0;
  for (var index in strandOne) {
    var n1 = strandOne[index];
    var n2 = strandTwo[index];
    if (n1 !== n2) {
      differences ++;
    }
  }
  return differences;
};

module.exports = hamming;
