"""
Problem

You own a milkshake shop. There are N different flavors that you can prepare, and each flavor can be prepared "malted" or "unmalted". So, you can make 2N different types of milkshakes.

Each of your customers has a set of milkshake types that they like, and they will be satisfied if you have at least one of those types prepared. At most one of the types a customer likes will be a "malted" flavor.

You want to make N batches of milkshakes, so that:

There is exactly one batch for each flavor of milkshake, and it is either malted or unmalted.
For each customer, you make at least one milkshake type that they like.
The minimum possible number of batches are malted.
Find whether it is possible to satisfy all your customers given these constraints, and if it is, what milkshake types you should make.
If it is possible to satisfy all your customers, there will be only one answer which minimizes the number of malted batches.

Input

One line containing an integer C, the number of test cases in the input file.
For each test case, there will be:
One line containing the integer N, the number of milkshake flavors.
One line containing the integer M, the number of customers.
M lines, one for each customer, each containing:
An integer T >= 1, the number of milkshake types the customer likes, followed by
T pairs of integers "X Y", one for each type the customer likes, where X is the milkshake flavor between 1 and N inclusive, and Y is either 0 to indicate unmalted, or 1 to indicated malted. Note that:
No pair will occur more than once for a single customer.
Each customer will have at least one flavor that they like (T >= 1).
Each customer will like at most one malted flavor. (At most one pair for each customer has Y = 1).
All of these numbers are separated by single spaces.

Output

C lines, one for each test case in the order they occur in the input file, each containing the string "Case #X: " where X is the number of the test case, starting from 1, followed by:
The string "IMPOSSIBLE", if the customers' preferences cannot be satisfied; OR
N space-separated integers, one for each flavor from 1 to N, which are 0 if the corresponding flavor should be prepared unmalted, and 1 if it should be malted.
"""

import logging
import random
import sys

UNMALTED = 0
MALTED = 1


def UpdatePrefs(logger, customer_to_shake_to_type, customer, line):
  """
  logger.debug('customer_to_shake_to_type: %s', customer_to_shake_to_type)
  logger.debug('current_customer: %s', customer)
  logger.debug('line: %s', line)
  """
  customer_to_shake_to_type[customer] = {}
  number_of_milkshakes = int(line.pop(0))
  """
  logging.debug(
      'number_of_milkshakes: %d, line: %s', number_of_milkshakes, line)
  """
  for i in range(0, len(line), 2):
    shake_id = int(line[i])
    shake_type = int(line[i+1])
    customer_to_shake_to_type[customer][shake_id] = shake_type


def CalculateViability(logger, number_of_flavors, customer_to_shake_to_type):
  """
  From the problem description, here are the cases:
    A - If all customers request at least one UNMALTED shake, then the problem
        is solved simply by making all shakes unmalted.
    B - If there's any customer who doesn't like any UNMALTED shake, they can
        have only one preferred shake, and that is MALTED. In this case, we need
        to make this shake MALTED and then see if we can still satisfy other
        customers.
  """
  malted_shakes = set()
  keep_going = True
  trials = 9000
  while keep_going:
    trials -= 1
    if trials < 0:
      logger.debug('trials out!')
      return "IMPOSSIBLE"
    keep_going = False
    logger.debug('customer_to_shake_to_type: %s', customer_to_shake_to_type)
    logger.debug('malted_shakes: %s', malted_shakes)
    for customer in customer_to_shake_to_type:
      logger.debug('customer: %d', customer)
      pref = customer_to_shake_to_type[customer]
      if len(pref) == 1 and pref.values() == [MALTED]:
        shake_id = pref.keys()[0]
        logger.debug('shake_id: %d', shake_id)
        if shake_id not in malted_shakes:
          success = DropPrefsFor(logger, shake_id, customer_to_shake_to_type)
          if not success:
            return "IMPOSSIBLE"
          else:
            malted_shakes.add(shake_id)
            keep_going = True
            break

  return " ".join([str(MALTED) if shake_id+1 in malted_shakes else str(
    UNMALTED) for shake_id in range(number_of_flavors)])


def DropPrefsFor(logger, shake_id_to_drop, customer_to_shake_to_type):
  logger.debug('Dropping shake_id: %s', shake_id_to_drop)
  logger.debug('Before: customer_to_shake_to_type: %s',
      customer_to_shake_to_type)
  for customer in customer_to_shake_to_type:
    pref = customer_to_shake_to_type[customer]
    if shake_id_to_drop in pref and pref[shake_id_to_drop] == UNMALTED:
      if len(pref) == 1:
        logger.debug('Customer: %d wanted shake: %d UNMALTED. FAIL!',
            customer, shake_id_to_drop)
        return False
      else:
        logger.debug('Dropping shake_id: %d for customer: %d',
            shake_id_to_drop, customer)
        del pref[shake_id_to_drop]
  logger.debug('After: customer_to_shake_to_type: %s',
      customer_to_shake_to_type)
  return True


def GetInputAndCalculate(logger):
  lines = sys.stdin.readlines()
  assert len(lines) > 0
  number_of_cases = int(lines.pop(0))
  case_number = 1
  number_of_flavors = number_of_customers = None
  customer_to_shake_to_type = {}
  for line in lines:
    line = line.strip()
    if number_of_flavors is None:
      number_of_flavors = int(line)
      logger.debug('number_of_flavors: %s' % number_of_flavors)
    elif number_of_customers is None:
      number_of_customers = int(line)
      logger.debug('number_of_customers: %s' % number_of_customers)
      current_customer = 1
    else:
      line = line.split()
      UpdatePrefs(logger, customer_to_shake_to_type, current_customer, line)
      current_customer += 1
      if current_customer > number_of_customers:
        output = 'Case #%d: %s' % (case_number, CalculateViability(
          logger, number_of_flavors, customer_to_shake_to_type))
        print output
        logging.debug(output)
        # Reset
        customer_to_shake_to_type = {}
        current_customer = 1
        number_of_flavors = number_of_customers = None
        case_number += 1


def main():
  logging.basicConfig(level=logging.DEBUG)
  logger = logging.getLogger(__name__)
  GetInputAndCalculate(logger)


if __name__ == '__main__':
  main()
