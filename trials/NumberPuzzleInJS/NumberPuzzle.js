var Board = function (numRows) {
	this.rows = numRows;
	this.cols = numRows;
	this.maxSlots = this.rows * this.cols;	// 16
	this.maxTiles = this.maxSlots - 1;		// 15
	
	this.finalPosition = [];
	this.generateFinalPosition = function () {
		for (var i = 0; i < this.maxTiles; i++) {
			this.finalPosition[i] = i + 1;
		}
		console.log(this.finalPosition);
	};
	
	this.generateTileLocation = function () {
		this.numberInSlotArray = [];
		this.emptySlot = Math.floor(Math.random() * this.maxSlots);
		
		for (var i = 0; i < this.maxSlots; i++) {
			if (i === this.emptySlot) {
				this.numberInSlotArray[i] = undefined;
				continue;
			}
			
			var number;
			do {
					number = Math.floor(Math.random() * this.maxTiles) + 1;
			} while (this.numberInSlotArray.indexOf(number) !== -1);
			
			this.numberInSlotArray[i] = number;
			this.displayTiles(this.numberInSlotArray);
		}
		
		var isFinal = this.isCurrentStateFinalState();
		if (isFinal) {
			this.generateTileLocation();
		}
	};

	this.isCurrentStateFinalState = function () {
		var isFinal = true;
		for (var i = 0; i < this.maxTiles; i++) {
			if (this.numberInSlotArray[i] !== this.finalPosition[i]) {
				isFinal = false;
			}
		}
		
		return isFinal;
	};

	this.makeARandomMove = function () {
		var left = this.emptySlot - 1;
		var right = this.emptySlot + 1;
		var top = this.emptySlot - this.cols;
		var bottom = this.emptySlot + this.cols;
		
		var candidateSlots = [];
		if (left >= 0 && (Math.floor(left/this.cols) === Math.floor(this.emptySlot/this.cols))) {
			candidateSlots.push(left);
		}
		if (top >= 0 && ((top%this.cols) === (this.emptySlot%this.cols))) {
			candidateSlots.push(top);
		}
		if (right < this.maxSlots && (Math.floor(right/this.cols) === Math.floor(this.emptySlot/this.cols))) {
			candidateSlots.push(right);
		}
		if (bottom < this.maxSlots && ((bottom%this.cols) === (this.emptySlot%this.cols))) {
			candidateSlots.push(bottom);
		}
		
		var newEmptySlot = candidateSlots[Math.floor(Math.random() * candidateSlots.length)];
		console.log ("Swapping " + this.emptySlot + " with " + newEmptySlot);
		this.numberInSlotArray[this.emptySlot] = this.numberInSlotArray[newEmptySlot];
		this.numberInSlotArray[newEmptySlot] = undefined;
		this.emptySlot = newEmptySlot;
		
		this.showGrid(this.numberInSlotArray);
		this.displayTiles(this.numberInSlotArray);

		if (this.count < 5000 && !this.isCurrentStateFinalState()) {
			this.count ++;
			setTimeout(this.makeARandomMove(), 50);
		}
	}

	this.displayTiles = function (array) {
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
	
	this.showGrid = function (array) {
		for (var i = 0; i < this.rows; i++) {
			for (var j = 0; j < this.cols; j++) {
				var id = "r"+(i+1)+"c"+(j+1);
				var div = document.getElementById(id);
				var value = array[i * this.rows + j];
				if (value !== undefined) {
					div.innerHTML = value;
				} else {
					div.innerHTML = "_";
				}
			}
		}
	};
	
	debugger;
	this.generateFinalPosition();
	this.generateTileLocation();
	this.displayTiles(this.numberInSlotArray);
	this.displayTiles(this.finalPosition);
	
	this.count = 0;
	if (!this.isCurrentStateFinalState()) {
		this.makeARandomMove();
	}
};

var onLoaded = function () {
	var board = new Board (3);
};