#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board)
	{
		for(int i=0;i<9;i++)
			for (int j = 0; j < 9; j++)
			{
				char c = board[i][j];
				if (c != '.')
				{
					row[i][c]++;
					col[j][c]++;
					block[int(i / 3) * 3 + j / 3][c]++;
				}
			}
		DFS(board, 0, 0);
	}
private:
	bool flag = false;
	map<char, int> row[9], col[9], block[9];
	void DFS(vector<vector<char>>& board, int i, int j)
	{
		if (flag)
			return;
		if (i >= 9)
		{
			flag = true;
			return;
		}
		if (board[i][j] != '.')
		{
			if (j < 8)
				DFS(board, i, j + 1);
			else
				DFS(board, i + 1, 0);
			if (flag)
				return;
		}
		else
		{
			for (int k = 1; k <= 9; k++)
			{
				if (row[i][k + '0']==0 && col[j][k + '0']==0 && block[(i / 3) * 3 + j / 3][k + '0']==0)
				{
					board[i][j] = k + '0';
					row[i][k + '0']++;
					col[j][k + '0']++;
					block[(i / 3) * 3 + j / 3][k + '0']++;
					if (j < 8)
						DFS(board, i, j + 1);
					else
						DFS(board, i + 1, 0);
					row[i][k + '0']--;
					col[j][k + '0']--;
					block[(i / 3) * 3 + j / 3][k + '0']--;
					if (flag)
						return;
				}

			}
			board[i][j] = '.';
		}
	}
};


