// Card Constructor
var Card = function (suitArg, numberArg) {
	var suit = suitArg;
	var number = numberArg;
	
	this.getNumber = function () {
		return number;
	};
	
	this.getSuit = function () {
		return suit;
	};
	
	this.getSuitName = function () {
		switch (this.getSuit()) {
			case 1:
				return "hearts";
			case 2:
				return "spades";
			case 3:
				return "clubs";
			case 4:
				return "diamonds";
		}
	};
	
	this.getValue = function () {
		var n = this.getNumber();
		if (n <= 10 && n > 1) {
			return n;
		} else if (n === 1) {
			return 11;
		} else {
			return 10;
		}
	};
	
	this.getNumberName = function () {
		var n = this.getNumber();
		if (n <= 10 && n > 1) {
			return n;
		} else if (n === 1) {
			return "ace";
		} else if (n === 11) {
			return "jack";
		} else if (n === 12) {
			return "queen";
		} else if (n === 13) {
			return "king";
		} else {
			console.log(n + ": Whoa!");
		}
	};
	
};

var deal = function () {
	var newSuit = Math.floor(4 * Math.random()) + 1;
	var newNumber = Math.floor(13 * Math.random()) + 1;
	
	return new Card (newSuit, newNumber);
};

var Hand = function () {
	var cards = [];
	cards.push(deal());
	cards.push(deal());
	
	this.getHand = function () {
		return cards;
	};
	
	this.score = function () {
		var sum = 0;
		for (var i = 0; i < cards.length; i++) {
			sum += cards[i].getValue();
		}
		
		while (sum > 21) {
			sum -= 10;
		}
		
		return sum;
	};
	
	this.printHand = function () {
		var suffix = ", ";
		var result = "";
		for (var i = 0; i < cards.length; i++) {
			if (i === (cards.length-1)) {
				suffix = "";
			}

			result += (cards[i].getNumberName() + " of " + cards[i].getSuitName() + suffix);
		}
		return result;
	};
};

var playAsDealer = function () {
	var hand = new Hand();
	while (hand.score() < 17) {
		hand = new Hand();
	}
	
	return hand;
};

var playAsUser = function () {
	var hand;
	var wantsToHit = true;
	while (wantsToHit) {
		hand = new Hand();
		wantsToHit = confirm (hand.printHand());
	}
	
	return hand;
};

var declareWinner = function (userHand, dealerHand) {
	if (userHand.score < dealerHand.score) {
		return "You lose!";
	} else if (userHand.score === dealerHand.score) {
		return "You tied!";
	} else {
		return "You win!";
	}
};

var playGame = function () {
	var userHand = playAsUser();
	var dealerHand = playAsDealer();
	
	console.log(declareWinner(userHand, dealerHand));
};

playGame();