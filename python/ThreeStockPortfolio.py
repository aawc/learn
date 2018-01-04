A = "BND"
B = "VXUS"
C = "VTI"
D = "MM"

ratio_a = 0.3
ratio_b = 0.1
ratio_c = 0.6

def InputAsFloat(s):
  response = raw_input("Enter current value of %s: " % s)
  return float(response.replace(',', ''))

def GetMoneyToInvest(total, current_investment, ratio, ticker):
  total_target = total * ratio
  to_invest = total_target - current_investment
  current_ratio = current_investment / total
  print "Ticker: %s, Target: %f, Current Ratio: %f, To Invest: %f" % (
    ticker, total_target, current_ratio, to_invest)
  return "Invest %f in %s" % (to_invest, ticker)

def main():
  a = InputAsFloat(A)
  b = InputAsFloat(B)
  c = InputAsFloat(C)
  d = InputAsFloat(D)
  total = a + b + c + d
  print "Total: %f" % total
  print GetMoneyToInvest(total, a, ratio_a, A)
  print GetMoneyToInvest(total, b, ratio_b, B)
  print GetMoneyToInvest(total, c, ratio_c, C)

if __name__ == '__main__':
  main()
