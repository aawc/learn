var words = function(sentence) {
  var result = {};
  var words = sentence.trim().split(/\s+/);
  for (var index in words) {
    var word = words[index];
    if (result.hasOwnProperty(word)) {
      result[word] += 1;
    } else {
      result[word] = 1;
    }
  }
  return result;
};

module.exports = words;
