var anagram = require('./anagram');

describe('Anagram', function() {

  it("no matches",function() {
    var subject = new anagram("diaper");
    console.log(subject);
    var matches = subject.matches([ "hello", "world", "zombies", "pants"]);

    expect(matches).toEqual([]);
  });

  xit("detects simple anagram",function() {
    var subject = new anagram("ant");
    var matches = subject.matches(['tan', 'stand', 'at']);

    expect(matches).toEqual(['tan']);
  });

  xit("does not detect false posxitives",function() {
    var subject = new anagram("galea");
    var matches = subject.matches(["eagle"]);

    expect(matches).toEqual([]);
  });

  xit("detects multiple anagrams",function() {
    var subject = new anagram("master");
    var matches = subject.matches(['stream', 'pigeon', 'maters']);

    expect(matches).toEqual(['stream', 'maters']);
  });

  xit("does not detect anagram subsets",function() {
    var subject = new anagram("good");
    var matches = subject.matches(['dog', 'goody']);

    expect(matches).toEqual([]);
  });

  xit("detects anagram",function() {
    var subject = new anagram("listen");
    var matches = subject.matches(['enlists', 'google', 'inlets', 'banana']);

    expect(matches).toEqual(['inlets']);
  });

  xit("detects multiple anagrams",function() {
    var subject = new anagram("allergy");
    var matches = subject.matches(['gallery', 'ballerina', 'regally', 'clergy', 'largely', 'leading']);

    expect(matches).toEqual(['gallery', 'regally', 'largely']);
  });

  xit("detects anagrams case-insensxitively",function() {
    var subject = new anagram("Orchestra");
    var matches = subject.matches(['cashregister', 'Carthorse', 'radishes']);

    expect(matches).toEqual(['Carthorse']);
  });

  xit("does not detect a word as xits own anagram",function() {
    var subject = new anagram("banana");
    var matches = subject.matches(['Banana']);

    expect(matches).toEqual([]);
  });

  xit("matches() accepts string arguments",function() {
    var subject = new anagram("ant");
    console.log(subject);
    var matches = subject.matches("stand", "tan", "at");

    expect(matches).toEqual(["tan"]);
  });

  xit("matches() accepts single string argument",function() {
    var subject = new anagram("ant");
    var matches = subject.matches("tan");

    expect(matches).toEqual(["tan"]);
  });
});
