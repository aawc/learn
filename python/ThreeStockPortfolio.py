BONDS = "VBTLX/BND"
INTERNATIONAL = "VTIAX/VXUS"
STOCK = "VTSAX/VTI"
MONEY_MARKET = "MM"

ratio_bonds = 0.3
ratio_international = 0.1
ratio_stock = 0.6

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
  bonds = InputAsFloat(BONDS)
  international = InputAsFloat(INTERNATIONAL)
  stock = InputAsFloat(STOCK)
  money_market = InputAsFloat(MONEY_MARKET)
  total = bonds + international + stock + money_market
  print "Total: %f" % total
  print GetMoneyToInvest(total, bonds, ratio_bonds, BONDS)
  print GetMoneyToInvest(total, international, ratio_international, INTERNATIONAL)
  print GetMoneyToInvest(total, stock, ratio_stock, STOCK)

if __name__ == '__main__':
  main()
