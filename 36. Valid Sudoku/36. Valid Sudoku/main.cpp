#include<vector>
#include<map>
using namespace std;


class Solution {
public:
	bool isValidSudoKu(vector<vector<char>>& board)
	{
		map<char, int> row[9], col[9], block[9];
		char c;
		for(int i = 0;i<9;i++)
			for (int j = 0; j < 9; j++)
			{
				c = board[i][j];
				if (c != '.' && (0 < row[i][c]++) || (0 < col[j][c]++) || (0 < block[int(i / 3) * 3 + j / 3][c]++))
					return false;
			}
		return true;
	}
};