#include<iostream>
#include<string>

class space {
private:
	char state = ' ';
	bool blank = true;
	bool red = false;
	bool yellow = false;
public:
	space() {};
	bool operator==(space other);

	void setBlank() {
		state = ' ';
		blank = true;
		red = false;
		yellow = false;
	}

	bool getBlank() { return blank; }

	void setRed() {
		state = 15;
		blank = false;
		red = true;
		yellow = false;
	}

	bool getRed() { return red; }

	void setYellow() {
		state = 254;
		blank = false;
		red = false;
		yellow = true;
	}

	bool getYellow() { return yellow; }

	void setState(char c) {
		state = c;
	}

	char getState() { return state; }

};

bool space::operator==(space other) {
	/*if (this->getBlank() && other.getBlank()) {
		return true;
	}
	else if (this->getRed() && other.getRed()) {
		return true;
	}
	else if (this->getYellow() && other.getYellow()) {
		return true;
	}
	else {
		return false;
	}*/
	if (this->getState() == other.getState()) {
		return true;
	}
	else {
		return false;
	}
}

space board[6][7];

//////////////////////////////////
//		DO IN ASSEMBLY??		//
//////////////////////////////////
///display the board on the consol
void displayBoard() {
	std::cout << " 1   2   3   4   5   6   7\n";		//keeps track of columns
														//displays board to screen
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++)										//creates each box in thirds using ASCII characters
			std::cout << char(218) << char(196) << char(191) << " ";	//top 1/3
		std::cout << std::endl;											//
		for (int j = 0; j < 7; j++)										//
			std::cout << char(179) << board[i][j].getState() << char(179) << " ";	//middle 2/3
		std::cout << std::endl;											//
		for (int j = 0; j < 7; j++)										//
			std::cout << char(192) << char(196) << char(217) << " ";	//bottom 3/3
		std::cout << std::endl;
	}
}

//////////////////////////////////
//		DO IN ASSEMBLY			//
//////////////////////////////////
///initalize the game board to all blank spaces
void emptyBoard() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j].setBlank();
		}
	}
}

//////////////////////////////////
//		DO IN ASSEMBLY			//
//////////////////////////////////
///placing a piece on the board
int placeTile(int col, char player) {
	int i;
	if (col >= 0 && col < 7) {
		if (board[0][col].getState() == ' ') {
			for (i = 0; board[i][col].getState() == ' '; i++)
				if (i == 5) {
					board[i][col].setState(player);
					return i;
				}
			i--;
			board[i][col].setState(player);
			return i;
		}
		else
			return -1;
	}
	else
		return -1;
}

///check to see if someone has one yet by checking
///horizontally, vertically, and both wasy diagonally across the whole board
bool check(int col, int row) {
	//CHECK HORIZONTAL
	int inarow = 1;
	int curCol = col;
	int curRow = row;

	//IT ALWAYS GOES INTO THE FIRST IF STATEMENT. NEED TO MAKE SURE THAT WE SET THE PROPERTIES OF THE SPACES CORRECTLY
	//check left direction
	while (curCol > 0) {
		curCol--;	//move current column to new space (it is guaranteed to exist)
		if (board[curCol][curRow] == board[curCol + 1][curRow]) {	// if spaces have same state
			inarow++;				// increment inarow
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;					//break from loop, check other direction
		}
	}
	curCol = col;
	curRow = row;
	
	// check right direction
	while (curCol < 6) {
		curCol++;
		if (board[curCol][curRow] == board[curCol - 1][curRow]) {
			inarow++;
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;
		}
	}

	//CHECK VERTICAL
	inarow = 1;
	curCol = col;
	curRow = row;

	// check up
	while (curRow > 0) {
		curRow--;
		if (board[curCol][curRow] == board[curCol][curRow + 1]) {
			inarow++;
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;
		}
	}
	curCol = col;
	curRow = row;

	// check down
	while (curRow < 5) {
		curRow++;
		if (board[curCol][curRow] == board[curCol][curRow - 1]) {
			inarow++;
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;
		}
	}

	//CHECK DIAGONAL (/)
	inarow = 1;
	curCol = col;
	curRow = row;

	// check up-right
	while (curCol < 6 && curRow > 0) {
		curCol++;
		curRow--;
		if (board[curCol][curRow] == board[curCol - 1][curRow + 1]) {
			inarow++;
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;
		}
	}
	curCol = col;
	curRow = row;

	// check down-left
	while (curCol > 0 && curRow < 5) {
		curCol--;
		curRow++;
		if (board[curCol][curRow] == board[curCol + 1][curRow - 1]) {
			inarow++;
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;
		}
	}

	//CHECK DIAGONAL (\)
	inarow = 1;
	curCol = col;
	curRow = row;

	//check up-left
	while (curCol > 0 && curRow > 0) {
		curCol--;
		curRow--;
		if (board[curCol][curRow] == board[curCol + 1][curRow + 1]) {
			inarow++;
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;
		}
	}
	curCol = col;
	curRow = row;

	//check down-right
	while (curCol < 6 && curRow < 5) {
		curCol++;
		curRow++;
		if (board[curCol][curRow] == board[curCol - 1][curRow - 1]) {
			inarow++;
			if (inarow == 4) {
				return true;
			}
		}
		else {
			break;
		}
	}
	
	return false;
}

int main() {
	char again = 121;
	std::string pl1, pl2;
	std::cout << "\nPlayer 1: What would you like to be known as? \n";
	std::cin >> pl1;
	std::cout << "\nPlayer 2: What would you like to be known as? \n";
	std::cin >> pl2;
	

	do {
		system("cls");
		emptyBoard();
		displayBoard();		//displays a blank board
		int rowChoice, curCol = 0, placed = 0;
		bool win = false;
		char player = 15;

		do {
			if (curCol != -1) {
				if (player == 15) {
					std::cout << pl1 << ", where would you like to drop your tile?";
					player = 254;
				}
				else {
					std::cout << pl2 << ", where would you like to drop your tile?";
					player = 15;
				}
			}
			while (true) {
				if (placed == 42)
					break;
				std::cin >> rowChoice;
				rowChoice--;
				if (rowChoice < 7 && rowChoice >= 0)
					break;
				else
					std::cout << "\nPlease enter a value between 1 and 7 : ";
				if (std::cin.fail())
				{
					std::cin.clear();
					char c;
					std::cin >> c;
				}
			}
			if (placed == 42)
				break;
			curCol = placeTile(rowChoice, player);
			if (curCol == -1)
				std::cout << "Column is full\nPlease choose a differnt column: ";
			else {
				if (placed >= 6)
					//win = check(curCol, rowChoice);
					win = check(rowChoice, curCol);	//This makes the indexes work (0-6 for col, 0-5 for row). Maybe this wasn't intended though and needs to be fixed.
				placed++;
				system("cls");
				displayBoard();
			}
		} while (!win);

		system("cls");
		displayBoard();
		if (placed == 42) {
			std::cout << "IT'S A DRAW" << std::endl;
			system("pause");
		}
		if (player == 15)
			std::cout << pl2 << " won! " << std::endl;
		else
			std::cout << pl1 << " won! " << std::endl;
		system("pause");

		std::cout << "Would you like to play again? (Y or N) ";
		std::cin >> again;
	} while (tolower(again) == 'y');

	system("cls");
	std::cout << "Thank you for playing Connect 4! Come and play again soon (:" << std::endl;
	system("pause");

	return 0;
}