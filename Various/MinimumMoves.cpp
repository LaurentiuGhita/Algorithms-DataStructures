#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

enum class MoveType {
	None,
	Ox,
	Oy
};

struct Node {
	Node() : x_(0), y_(0), visited_(false), is_wall_(true), processed_finished_(false), previousMove_(MoveType::None), move_count_(0) {}
	Node(int x, int y, bool is_wall, MoveType previousMove) :
		x_(x), y_(y), visited_(false), is_wall_(is_wall), processed_finished_(false), previousMove_(previousMove), move_count_(0) {}

	int x_;
	int y_;
	bool visited_;
	bool is_wall_;
	bool processed_finished_;
	MoveType previousMove_;
	int move_count_;
};

void printMap(const vector<vector<Node>>& map) {
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			if (map[i][j].is_wall_ == true)
				std::cout << "X";
			else
				std::cout << ".";
		}
		std::cout << "\n";
	}
}

vector<vector<Node>> getMap(const std::vector<string>& grid) {
	int lines = grid.size();
	vector<vector<Node>> matrix(lines, std::vector<Node>(lines));

	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {
			if (grid[i][j] != 'X')
				matrix[i][j] = Node(i, j, false, MoveType::None);
			else
				matrix[i][j] = Node(i, j, true, MoveType::None);

		}
	}
	return matrix;
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {

	vector<vector<Node>> map = getMap(grid);
	std::queue<Node*> processingQueue;

	(&map[startX][startY])->visited_ = true;
	(&map[startX][startY])->move_count_ = 1;
	processingQueue.push(&map[startX][startY]);

	while (processingQueue.empty() == false) {
		Node* current = processingQueue.front();
		processingQueue.pop();

		int x = current->x_;
		int y = current->y_;
		MoveType prevMove = current->previousMove_;

		if (map[x][y].processed_finished_ == false) {
			
			int moveX = x - 1;
			if (moveX >= 0 && moveX < map.size()) {
				for (int k = moveX; k >= 0; --k) {
					MoveType currentMove = MoveType::Oy;
					int incrementMove = 0;
					if (prevMove == MoveType::Ox)
						incrementMove = 1;

					if (map[k][y].is_wall_)
						break;

					if (map[k][y].visited_ == true)
						continue;

					int newCount = current->move_count_ + incrementMove;
					
					if (k == goalX && y == goalY)
						return newCount;

					if (map[k][y].visited_ == false) {
						map[k][y].visited_ = true;
						map[k][y].move_count_ = newCount;
						map[k][y].previousMove_ = currentMove;
						processingQueue.push(&map[k][y]);
					}
				}
			}

			moveX = x + 1;
			if (moveX >= 0 && moveX < map.size()) {
				for (int k = moveX; k < map.size(); ++k) {
					MoveType currentMove = MoveType::Oy;
					int incrementMove = 0;
					if (prevMove == MoveType::Ox)
						incrementMove = 1;

					if (map[k][y].is_wall_)
						break;

					if (map[k][y].visited_ == true)
						continue;

					int newCount = current->move_count_ + incrementMove;
					if (k == goalX && y == goalY)
						return newCount;

					if (map[k][y].visited_ == false) {
						map[k][y].visited_ = true;
						map[k][y].move_count_ = newCount;
						map[k][y].previousMove_ = currentMove;
						processingQueue.push(&map[k][y]);
					}
				}
			}

			int moveY = y + 1;
			if (moveY >= 0 && moveY < map.size()) {
				for(int k = moveY; k < map.size(); ++k) {
					MoveType currentMove = MoveType::Ox;
					int incrementMove = 0;
					if (prevMove == MoveType::Oy)
						incrementMove = 1;

					if (map[x][k].is_wall_)
						break;

					if (map[x][k].visited_ == true)
						continue;

					int newCount = current->move_count_ + incrementMove;
					if (x == goalX && k == goalY)
						return newCount;

					if (map[x][k].visited_ == false) {
						map[x][k].visited_ = true;
						map[x][k].move_count_ = newCount;
						map[x][k].previousMove_ = currentMove;
						processingQueue.push(&map[x][k]);
					}
				}
			}

			moveY = y - 1;
			if (moveY >= 0 && moveY < map.size()) {
				for (int k = moveY; k >= 0; --k) {
					MoveType currentMove = MoveType::Ox;
					int incrementMove = 0;
					if (prevMove == MoveType::Oy)
						incrementMove = 1;

					if (map[x][k].is_wall_)
						break;

					if (map[x][k].visited_ == true)
						continue;

					int newCount = current->move_count_ + incrementMove;
					if (x == goalX && k == goalY)
						return newCount;

					if (map[x][k].visited_ == false) {
						map[x][k].visited_ = true;
						map[x][k].move_count_ = newCount;
						map[x][k].previousMove_ = currentMove;
						processingQueue.push(&map[x][k]);
					}
				}
			}
			map[x][y].processed_finished_ = true;
		}
	}

	return 0;
}

void readMap(const std::string& sFile, vector<string>& grid, int& startX, int& startY, int& goalX, int& goalY) {
	ifstream fin(sFile.c_str());
	if (fin) {
		std::string s;
		int lineCount;
		fin >> lineCount;

		getline(fin, s); // ignore line

		for (int i = 0; i < lineCount; ++i) {
			getline(fin, s);
			grid.push_back(s);
		}

		fin >> startX >> startY >> goalX >> goalY;
	}
}

int main() {
	vector<string> grid;
	int x, y, ex, ey;
	readMap("C:\\Users\\homeadmin\\Documents\\input1.txt", grid, x, y, ex, ey);
	int minLen = minimumMoves(grid, x, y, ex, ey);
	std::cout << minLen << "\n";;
}

