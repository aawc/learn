def MapDigitToOutput(digit, base):
  if digit <= 9:
    return str(digit)
  return chr(digit - 10 + ord('a'))

def answer(number, base):
  if not number:
    return MapDigitToOutput(number, base)

  if number < 0:
    prefix = '-'
    number *= -1
  else:
    prefix = ''

  quotient = number / base
  remainder = number % base
  if quotient:
    q_a = answer(quotient, base)
  else:
    q_a = ''
  return prefix + q_a + MapDigitToOutput(remainder, base)

print answer(10, 2) == "1010"
print answer(30, 8) == "36"
print answer(15, 3) == "120"
print answer(166010539, 25) == "google"
print answer(0, 25) == "0"
print answer(0, 2) == "0"
print answer(30, 36) == "u"
print answer(37, 36) == "11"
print answer(-15, 3) == "-120"
