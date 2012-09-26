var Board = function (numRows) {
	this.rows = numRows;
	this.cols = numRows;
	this.maxSlots = this.rows * this.cols;	// 16
	this.maxTiles = this.maxSlots - 1;		// 15
	
	this.finalPosition = [];
	this.generateFinalPosition = function () {
		var maxNumber = this.rows * this.cols;
		for (var i = 0; i < this.maxTiles; i++) {
			this.finalPosition[i] = i;
		}
		console.log(this.finalPosition);
	};
	
	this.slotInWhichTileIsPlaced = [];	// Slot in which tile 'i' is placed.
	this.tileInEachSlot = [];	// Tile in slot 'i'.
	this.generateTileLocation = function () {
		this.slotInWhichTileIsPlaced = [];
		this.tileInEachSlot = [];
		while (this.slotInWhichTileIsPlaced.length < this.maxTiles) {
			var position = Math.floor(Math.random() * this.maxTiles);
			if (this.slotInWhichTileIsPlaced.indexOf(position) === -1) {
				this.slotInWhichTileIsPlaced.push(position);
				console.log(this.slotInWhichTileIsPlaced);
			} else {
				// console.log("Rejected: " + position);
			}
		}
		
		var inFinalState = this.isCurrentStateFinal();
		if (inFinalState) {
			// We've generated the final state as the starting state. Start over.
			this.generateTileLocation();
		} else {
			for (var i = 0; i < this.maxTiles; i++) {
				this.tileInEachSlot.push(this.slotInWhichTileIsPlaced.indexOf(i) + 1);
			}
			console.log(this.tileInEachSlot);
		}
	};

	this.isCurrentStateFinal = function () {
		var isDifferent = false;
		for (var i = 0; i < this.maxTiles; i++) {
			if (this.slotInWhichTileIsPlaced[i] !== this.finalPosition[i]) {
				isDifferent = true;
			}
		}
		
		return !isDifferent;
	};

	this.displayTileLocation = function (array) {
		var s = "";
		for (var i = 0; i < this.rows; i++) {
			for (var j = 0; j < this.cols; j++) {
				var value = array[i * this.rows + j];
				if (value !== undefined) {
					s += value;
				} else {
					s += "_";
				}
				s += "\t";
			}
			s += "\n";
		}
		
		console.log(s);
	};
	
	this.generateFinalPosition();
	this.generateTileLocation();
	this.displayTileLocation(this.tileInEachSlot);
	this.displayTileLocation(this.finalPosition);
};

var board = new Board (3);