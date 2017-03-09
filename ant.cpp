#include "ant.h"
#include "menu.h"

Ant::Ant(int row, int column) {
	setThisChar(ANT);
	setRowPos(row);
	setColPos(column);
}

void Ant::move(Critter*** board) {
	setTurnsSurvived(getTurnsSurvived() + 1);
	setMovedThisTurn(true);
	int dirNum = (rand() % 4);

	//Check a random adjacent cell. If it is empty, place this object in that position
	switch (dirNum) {
	case RIGHT:
		if (getColPos() + 1 != 20) {
			if (board[getRowPos()][getColPos() + 1] == NULL) {
				board[getRowPos()][getColPos() + 1] = this;
				board[getRowPos()][getColPos()] = NULL;
				setColPos(getColPos() + 1);
			}
		}
		break;
	case LEFT:
		if (getColPos() - 1 != -1) {
			if (board[getRowPos()][getColPos() - 1] == NULL) {
				board[getRowPos()][getColPos() - 1] = this;
				board[getRowPos()][getColPos()] = NULL;
				setColPos(getColPos() - 1);
			}
		}
		break;
	case DOWN:
		if (getRowPos() + 1 != 20) {
			if (board[getRowPos() + 1][getColPos()] == NULL) {
				board[getRowPos() + 1][getColPos()] = this;
				board[getRowPos()][getColPos()] = NULL;
				setRowPos(getRowPos() + 1);
			}
		}
		break;
	case UP:
		if (getRowPos() - 1 != -1) {
			if (board[getRowPos() - 1][getColPos()] == NULL) {
				board[getRowPos() - 1][getColPos()] = this;
				board[getRowPos()][getColPos()] = NULL;
				setRowPos(getRowPos() - 1);
			}
		}
		break;
	default:
		cout << "Ant.move() error in Ant class" << endl;
	}
}

void Ant::breed(Critter*** board) {
	if (getTurnsSurvived() >= 3) {
		//Generate an array of 0, 1, 2, 3 in a random order
		int temp[4] = { -1, -1, -1, -1, };
		int count = 0;

		while (count < 4) {
			int num = rand() % 4;
			bool flag = false;
			for (int i = 0; i < 4; i++) {
				if (num == temp[i])
					flag = true;
			}
			if (!flag) {
				temp[count] = num;
				count++;
			}
		}

		//Check each adjacent cell in a random order if the cell is empty. If it is empty, create
		//a new Ant object in it's location and set turnsSurvived to zero to reset the counter.
		bool breedFlag = false;
		for (int i = 0; i < 4; i++) {
			if (!breedFlag) {
				if (temp[i] == RIGHT) {
					if (getColPos() + 1 != 20)
						if (board[getRowPos()][getColPos() + 1] == NULL) {
							board[getRowPos()][getColPos() + 1] = new Ant(getRowPos(), getColPos() + 1);
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
				if (temp[i] == LEFT) {
					if (getColPos() - 1 != -1)
						if (board[getRowPos()][getColPos() - 1] == NULL) {
							board[getRowPos()][getColPos() - 1] = new Ant(getRowPos(), getColPos() - 1);
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
				if (temp[i] == DOWN) {
					if (getRowPos() + 1 != 20)
						if (board[getRowPos() + 1][getColPos()] == NULL) {
							board[getRowPos() + 1][getColPos()] = new Ant(getRowPos() + 1, getColPos());
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
				if (temp[i] == UP) {
					if (getRowPos() - 1 != -1)
						if (board[getRowPos() - 1][getColPos()] == NULL) {
							board[getRowPos() - 1][getColPos()] = new Ant(getRowPos() - 1, getColPos());
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
			}
		}
	}
}
			

