#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string str;
		int number = num;
		while (number > 0)
		{
			if (number / 1000)
			{
				int numM = number / 1000;
				number = number % 1000;
				while (numM)
				{
					str.push_back('M');
					numM--;
				}
			}
			if (number / 100)
			{
				int numD = number / 100;
				if (numD == 4)
				{
					str.push_back('C');
					str.push_back('D');
					number = number % 400;
				}
				else if (numD == 9)
				{
					str.push_back('C');
					str.push_back('M');
					number = number % 900;
				}
				else
				{
					if (numD >= 5)
					{
						str.push_back('D');
						int numd = numD - 5;
						while (numd > 0)
						{
							str.push_back('C');
							numd--;
						}
						number = number % 100;
					}
					else
					{
						while (numD > 0) {
							str.push_back('C');
							numD--;
						}
						number = number % 100;
					}
				}

			}
			if (number / 10)
			{
				int numD = number / 10;
				if (numD == 4)
				{
					str.push_back('X');
					str.push_back('L');
					number = number % 40;
				}
				else if (numD == 9)
				{
					str.push_back('X');
					str.push_back('C');
					number = number % 90;
				}
				else
				{
					if (numD >= 5)
					{
						str.push_back('L');
						int numd = numD - 5;
						while (numd > 0)
						{
							str.push_back('X');
							numd--;
						}
						number = number % 10;
					}
					else
					{
						while (numD > 0) {
							str.push_back('X');
							numD--;
						}
						number = number % 10;
					}
				}
			}
			if (number)
			{
				if (number == 4)
				{
					str.push_back('I');
					str.push_back('V');
					break;
				}
				else if (number == 9)
				{
					str.push_back('I');
					str.push_back('X');
					break;
				}
				else
				{
					if (number >= 5)
					{
						str.push_back('V');
						while (number - 5 > 0)
						{
							str.push_back('I');
							number--;
						}
						break;
					}
					else
					{
						while (number > 0)
						{
							str.push_back('I');
							number--;
						}
						break;
					}
				}
			}

		}
		return str;
	}
};


int main()
{
	Solution s;
	string sh;
	sh = s.intToRoman(1994);
	return 0;
}





/*class Solu {
public:
	vector<vector<int>> threesum(vector<int>& nums)
	{
		vector<vector<int>> re;
		vector<int> p;
		p = nums;
		sort(p.begin(), p.end());
		vector<int>::iterator it = find_if(p.begin(), p.end(), [](const int a) {return a >= 0;});
		auto begin = p.begin();
		auto end = p.end() - 1;
		while (begin>end)
		{
			int time = 1;
			int sum = 0;
			sum = *begin + *end;
			if (sum > 0)
			{
				auto result = find(begin + 1, it, (-1*sum));
				if (result != it + 1)
				{
					vector<int> m;
					m.push_back(*begin);
					m.push_back(*end);
					m.push_back(*result);
					re.push_back(m);
				}
				else
				{
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}
				}
			}
			else if (sum < 0)
			{
				auto result = find(it, end, (-1 * sum));
				if (result != end)
				{
					vector<int> m;
					m.push_back(*begin);
					m.push_back(*end);
					m.push_back(*result);
					re.push_back(m);
				}
				else
				{
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}
				}
			}
			else
			{
				if (*it == 0)
				{
					vector<int> m;
					m.push_back(*begin);
					m.push_back(*end);
					m.push_back(*it);
					re.push_back(m);
				}
				else
				{
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}

				}
			}
		}
		return re;
	}
};*/