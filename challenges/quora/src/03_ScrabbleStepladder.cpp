/*
Scrabble Stepladder
A word ladder is a sequence of words in which each subsequent word is formed by replacing exactly one
letter from the previous word with a different letter. Words may not be repeated in a word ladder.
For example the following sequence is a valid word ladder:
CAT
COT
DOT
DOG

The Scrabble score of a word is the sum of the Scrabble values of each letter in the word.
The Scrabble score of a word ladder is the sum of the Scrabble scores of its words.
The values are taken from the official English edition of Scrabble.

1 points: A, E, I, L, N, O, R, S, T, U
2 points: D, G
3 points: B, C, M, P
4 points: F, H, V, W, Y
5 points: K
8 points: J, X
10 points: Q, Z

For example, CAT has a scrabble score of 5. The word ladder CAT, COT, DOT, DOG has a Scrabble score of 19.

A Scrabble stepladder is a word ladder with some additional constraints. It must contain an odd number of words.
From the first word to the central word each subsequent word must have a strictly greater Scrabble score than the previous word.
From the central word to the last word each subsequent word must have a strictly lesser Scrabble score than the previous word.
Stepladders that only contain 1 word are valid. All the rules of a general word ladder still apply.
For example, the following sequence is a valid Scrabble stepladder:

SOUR (4)
SPUR (6)
SPUD (7)
STUD (5)
STUN (4)

but the following sequence is not:

APES (6)
APED (7)
AXED (12)
AXES (11)
EXES (11)

nor is the following sequence:

SORES (5)
PORES (7)
POXES (14)
LOXES (12)

--------------------------------------------------------------------------

You are provided a dictionary of words from which all words in a Scrabble stepladder must be drawn, and number of letters that each word in the stepladder must contain. Your task is to determine the Scrabble stepladder with the highest possible score - over all valid Scrabble stepladders given the dictionary and the word length.

Input format (read from STDIN):
The first line of the input is a positive integer K: the length of a word in the Scrabble stepladders to consider.

The second line of input is a positive integer N: the number of dictionary words that will follow.

The remaining input is N lines, each containing a word whose characters must be in [A-Z]. This set of N words constitutes the dictionary.

Output format (write to STDOUT):
Output a single integer corresponding to the highest Scrabble stepladder over all valid Scrabble stepladders given the dictionary and word length. If there is no valid Scrabble stepladder, output 0.
*/