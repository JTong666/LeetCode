#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	/*bool isShorter(pair<int, char>& p1, pair<int, char>& p2)
	{
		return p1.first < p2.first;
	}*/
	string convert(string s, int numRows)
	{
		int max = numRows;
		string news;
		vector<pair<int, char>> p;
		if (numRows == 1)
			return s;
		int down = 1, up = 0;
		for (char c : s)
		{
			if (down == 1)
			{
				pair<int, char> m = make_pair(numRows, c);
				p.push_back(m);
				numRows--;
				if (numRows == 1)
				{
					down = 0;
					up = 1;
				}
			}
			else if (up == 1)
			{
				pair<int, char> m = make_pair(numRows, c);
				p.push_back(m);
				numRows++;
				if (numRows == max)
				{
					down = 1;
					up = 0;
				}
			}
		}
		/*sort(p.begin(), p.end(), isShorter);
		for (auto &it : p)
		{
			news.push_back(it.second);
		}*/
		for (int i = max; i > 0; i--)
		{
			for (auto &it : p)
			{
				if (it.first == i)
					news.push_back(it.second);
			}
		}
		return news;
	}
};

int main()
{

}