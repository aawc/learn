def FindMostFrequentHashtag(filename, how_many):
  frequency = {}
  with open(filename, 'r') as f:
    for line in f:
      words = line.split()
      for word in words:
        if word[0] == "#":
          IncrementFrequency(frequency, word.lower())
  return ListMostFrequentHastagFromDict(frequency, how_many)


def IncrementFrequency(frequency, word):
  if word not in frequency:
    frequency[word] = 0
  frequency[word] += 1


def ListMostFrequentHastagFromDict(frequency_dict, how_many):
  frequency_dict = sorted(
          frequency_dict.items(), key=lambda x:x[1], reverse=True)
  return frequency_dict[:how_many]


def main():
  filename = "tweets.txt"
  print FindMostFrequentHashtag(filename, 3)


if __name__ == "__main__":
  main()
