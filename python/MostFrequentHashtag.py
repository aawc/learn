def FindMostFrequentHashtag(filename):
  frequency = {}
  with open(filename, 'r') as f:
    for line in f:
      words = line.split()
      for word in words:
        if word[0] == "#":
          IncrementFrequency(frequency, word.lower())
  return ListMostFrequentHastagFromDict(frequency)


def IncrementFrequency(frequency, word):
  if word not in frequency:
    frequency[word] = 0
  frequency[word] += 1


def ListMostFrequentHastagFromDict(frequency_dict):
  highest = 0
  hashtag = ''
  for key in frequency_dict:
    value = frequency_dict[key]
    if highest < value:
      highest = value
      hashtag = key
  return hashtag


def main():
  filename = "tweets.txt"
  print FindMostFrequentHashtag(filename)


if __name__ == "__main__":
  main()
