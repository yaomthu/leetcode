/**
 * Game of life
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
Solution: 充分利用每个元素是int，使用二进制的倒数第一位表示当前状态，倒数第二位表示下个状态。
time complexity: O(n*m)
space complexity: O(1)

In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Solution: 使用hashset live来记录当前矩阵里元素为1的位置信息Cell，便利live里的所有元素，使用hashmap record来记录所有
邻居节点的邻居数，根据live和record信息来生成newLive信息

 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
namespace game_of_life {
class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size(), n = board[0].size();
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int lives = 0;
                for (int k=0; k<8; k++) {
                    if (i+dx[k]>=0 && i+dx[k]<m && j+dy[k]>=0 && j+dy[k]<n && (board[i+dx[k]][j+dy[k]] & 1))
                        lives++;
                }
                if (board[i][j] == 0) {
                    if (lives == 3)
                        board[i][j] = 2;
                } else {
                    if (lives < 2 || lives > 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 3;
                }
            }
        }
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                board[i][j] >>= 1;
    }
};

struct Cell {
  int x;
  int y;
  Cell(int x_, int y_): x(x_), y(y_) {}
};

class hashfunc {
 public:
  size_t operator() (const Cell& cell) const {
    return (size_t)cell.x*cell.y;
  }
  bool operator() (const Cell& cella, const Cell& cellb) const {
    return cella.x == cellb.x && cella.y == cellb.y;
  }
};

/*class followUp {
public:
  void gameOfLife(vector<vector<int> >& board) {
    if (board.empty() || board[0].empty())
      return;
    unordered_set<Cell, hashfunc> live;
    int m = board.size();
    int n = board[0].size();
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
        if (board[i][j] == 1)
          live.insert(Cell(i, j));
      }
    }
    unordered_map<Cell, int, hashfunc> record;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (auto cell : live) {
      for (int i=0; i<8; i++) {
        if (cell.x+dx[i] >= 0 && cell.x+dx[i] < m && cell.y+dy[i] >= 0 && cell.y+dy[i] < n)
          record[Cell(cell.x+dx[i], cell.y+dy[i])]++;
      }
    }
    unordered_set<Cell, hashfunc> newLive;
    for (unordered_map<Cell, int, hashfunc>::iterator iter = record.begin(); iter != record.end(); iter++) {
      if (iter->second == 3 || (iter->second == 2 && live.find(iter->first) != live.end()))
        newLive.insert(iter->first);
    }
    for (int i=0; i < m; i++)
      for (int j=0; j<n; j++)
          board[i][j] = 0;
    for (auto cell : newLive) {
      board[cell.x][cell.y] = 1;
    }
  }
};*/
}
int main_game_of_life() {
  vector<vector<int> > board;
  int data1[] = {1,1,1};
  board.push_back(vector<int>(data1, data1+3));
  board.push_back(vector<int>(data1, data1+3));
  board.push_back(vector<int>(data1, data1+3));
  (new game_of_life::Solution())->gameOfLife(board);
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}
