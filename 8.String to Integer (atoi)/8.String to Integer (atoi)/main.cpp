#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Solution 
{
public:
	int myAtoi(string str)
	{
		int symbol = 1,ch, i=0;
		vector<int> vec;
		for (char &c : str)
		{
			if (c != ' ')
			{
				if (c == '-')
				{
					symbol = -1;
					i++;
				}
				else if (c <= '9'&&c >= '0')
				{
					ch = c - '0';
					vec.push_back(ch);
					i++;
				}
				else
					if (i == 0)
						return 0;
			}
		}
		if (*vec.begin() == 0)
			vec.erase(vec.begin());
		long long int t=0;
		for (auto &i : vec)
		{
			t = 10 * t + i;
		}
		if (symbol == 1)
			if (t > INT_MAX)
				return INT_MAX;
		else
			if (t > INT_MAX)
				return INT_MIN;
		return symbol*t;
	}
};


int main()
{
	Solution s;
	int number;
	string s1 = { "    4678" };
	number = s.myAtoi(s1);
	cout << number;
	return 0;
}