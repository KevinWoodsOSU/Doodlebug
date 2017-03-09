#include "doodle.h"
#include "menu.h"
#include "grid.h"

Doodle::Doodle(int row, int column) {
	setThisChar(DOODLEBUG);
	setRowPos(row);
	setColPos(column);
	setStarveCount(0);
}

void Doodle::setStarveCount(int s) {
	starveCount = s;
}

int Doodle::getStarveCount() {
	return starveCount;
}

void Doodle::move(Critter*** board) {
	setTurnsSurvived(getTurnsSurvived() + 1);
	setMovedThisTurn(true);

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

	//Check each adjacent cell in a random order if an ant exists. If one exists delete the Ant
	//and place this object in it's place then place flag to run through for loop without action.
	bool moveFlag = false;
	for (int i = 0; i < 4; i++) {
		if (!moveFlag) {
			if (temp[i] == RIGHT) {
				if (getColPos() + 1 != 20) {
					if (board[getRowPos()][getColPos() + 1] != NULL) {
						if (board[getRowPos()][getColPos() + 1]->getThisChar() == ANT) {
							delete board[getRowPos()][getColPos() + 1];
							board[getRowPos()][getColPos() + 1] = this;
							board[getRowPos()][getColPos()] = NULL;
							setColPos(getColPos() + 1);
							moveFlag = true;
							setStarveCount(0);
						}
					}
				}
			}
			if (temp[i] == LEFT) {
				if (getColPos() - 1 != -1) {
					if (board[getRowPos()][getColPos() - 1] != NULL) {
						if (board[getRowPos()][getColPos() - 1]->getThisChar() == ANT) {
							delete board[getRowPos()][getColPos() - 1];
							board[getRowPos()][getColPos() - 1] = this;
							board[getRowPos()][getColPos()] = NULL;
							setColPos(getColPos() - 1);
							moveFlag = true;
							setStarveCount(0);
						}
					}
				}
			}
			if (temp[i] == DOWN) {
				if (getRowPos() + 1 != 20) {
					if (board[getRowPos() + 1][getColPos()] != NULL) {
						if (board[getRowPos() + 1][getColPos()]->getThisChar() == ANT) {
							delete board[getRowPos() + 1][getColPos()];
							board[getRowPos() + 1][getColPos()] = this;
							board[getRowPos()][getColPos()] = NULL;
							setRowPos(getRowPos() + 1);
							moveFlag = true;
							setStarveCount(0);
						}
					}
				}
			}
			if (temp[i] == UP) {
				if (getRowPos() - 1 != -1) {
					if (board[getRowPos() - 1][getColPos()] != NULL) {
						if (board[getRowPos() - 1][getColPos()]->getThisChar() == ANT) {
							delete board[getRowPos() - 1][getColPos()];
							board[getRowPos() - 1][getColPos()] = this;
							board[getRowPos()][getColPos()] = NULL;
							setRowPos(getRowPos() - 1);
							moveFlag = true;
							setStarveCount(0);
						}
					}
				}
			}
		}
	}

	//If not flag is present, move Doodlebug to a random location. If it is not empty, do not move.
	if (!moveFlag) {
		setStarveCount(getStarveCount() + 1);
		int dirNum = (rand() % 4);
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

	//If a Doodlebug hasn't eaten an ant in three turns, it is removed.
	if (getStarveCount() >= 3) {
		deleteObject(board, getRowPos(), getColPos());
	}
}

void Doodle::breed(Critter*** board) {
	if (getTurnsSurvived() >= 8) {
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

		bool breedFlag = false;
		for (int i = 0; i < 4; i++) {
			if (!breedFlag) {
				if (temp[i] == RIGHT) {
					if (getColPos() + 1 != 20)
						if (board[getRowPos()][getColPos() + 1] == NULL) {
							board[getRowPos()][getColPos() + 1] = new Doodle(getRowPos(), getColPos() + 1);
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
				if (temp[i] == LEFT) {
					if (getColPos() - 1 != -1)
						if (board[getRowPos()][getColPos() - 1] == NULL) {
							board[getRowPos()][getColPos() - 1] = new Doodle(getRowPos(), getColPos() - 1);
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
				if (temp[i] == DOWN) {
					if (getRowPos() + 1 != 20)
						if (board[getRowPos() + 1][getColPos()] == NULL) {
							board[getRowPos() + 1][getColPos()] = new Doodle(getRowPos() + 1, getColPos());
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
				if (temp[i] == UP) {
					if (getRowPos() - 1 != -1)
						if (board[getRowPos() - 1][getColPos()] == NULL) {
							board[getRowPos() - 1][getColPos()] = new Doodle(getRowPos() - 1, getColPos());
							setTurnsSurvived(0);
							breedFlag = true;
						}
				}
			}
		}
	}
}


			
