/*

https://leetcode.com/problems/n-queens/

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example
	Input : N = 4
	Output:
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _

	        [1, 3, 0, 2] [2, 0, 3, 1]

Constraint:
	1<=n<=10

*/



class Solution {
public:

	// fn to check if Qi can be placed in the jth column of row i
	bool canIPlace(int n, vector<string>& board, int i, int j) {

		for (int k = i - 1; k >= 0; k--) {
			if (board[k][j] == 'Q') {
				// there is already a queen in the jth column
				// so Qi cannot be placed in the jth column.
				return false;
			}
		}

		for (int k = i - 1, step = 1; k >= 0 and j + step < n; k--, step++) {
			if (board[k][j + step] == 'Q') {
				// there is already a queen in the right diag of the
				// jth column so Qi cannot be placed in the jth column
				return false;
			}
		}

		for (int k = i - 1, step = 1; k >= 0 and j - step >= 0; k--, step++) {
			if (board[k][j - step] == 'Q') {
				// there is already a queen in the left diag of the
				// jth column so Qi cannot be placed in the jth column
				return false;
			}
		}

		return true; // you can place Qi in the jth column of row i

	}

	void f(int n,
	       vector<string>& board,
	       vector<vector<string>>& allBoards,
	       int i) {

		// base case
		if (i == n) {
			allBoards.push_back(board);
			return;
		}

		// recursive case

		// f(i) : take decisions for queens i to n-1

		// decide for the ith queen

		for (int j = 0; j < n; j++) {
			// can I place Qi in the jth column of row i
			if (canIPlace(n, board, i, j)) {
				board[i][j] = 'Q';
				f(n, board, allBoards, i + 1);
				board[i][j] = '.';
			}
		}

	}

	vector<vector<string>> solveNQueens(int n) {
		vector<string> board;
		for (int i = 0; i < n; i++) {
			string row(n, '.');
			board.push_back(row);
		}
		vector<vector<string>> allBoards;
		f(n, board, allBoards, 0);
		return allBoards;
	}
};