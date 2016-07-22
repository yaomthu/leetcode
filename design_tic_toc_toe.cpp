/**
 * Design Tic-Tac-Toe  QuestionEditorial Solution  My Submissions
Total Accepted: 2534
Total Submissions: 5887
Difficulty: Medium
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?
 */

#include <iostream>
#include <vector>
using namespace std;

namespace design_tic_toc_toe {
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        for (int i = 0; i < n; i++)
            board.push_back(vector<char>(n, 'E'));
        this->n = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        char mark = player == 1? 'X' : 'O';
        board[row][col] = mark;
        int j = 0;
        for (; j < n; j++)
            if (board[row][j] != mark)
                break;
        if (j == n)
            return player;
        int i = 0;
        for (; i < n; i++)
            if (board[i][col] != mark)
                break;
        if (i == n)
            return player;
        if (row == col) {
            int i = 0;
            for (; i < n; i++)
                if (board[i][i] != mark)
                    break;
            if (i == n)
                return player;
        }
        if (row + col == n-1) {
            int i = 0;
            for (; i < n; i++)
                if (board[i][n-i-1] != mark)
                    break;
            if (i == n)
                return player;
        }
        return 0;
    }
private:
    vector<vector<char> > board;
    int n;
};
}
