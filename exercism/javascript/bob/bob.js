//
// This is only a SKELETON file for the "Bob" exercise. It's been provided as a
// convenience to get you started writing code faster.
//

var Bob = function() {};

Bob.prototype.hey = function(input) {
  if (!input.trim()) {
    return "Fine. Be that way!";
  }
  if (input === input.toUpperCase() && input.match(/[A-Z]/i)) {
    return "Whoa, chill out!";
  }
  if (input.endsWith("?")) {
    return "Sure.";
  }
  return "Whatever.";
};

String.prototype.endsWith = function(suffix) {
  return this.indexOf(suffix, this.length - suffix.length) !== -1;
};

module.exports = Bob;
