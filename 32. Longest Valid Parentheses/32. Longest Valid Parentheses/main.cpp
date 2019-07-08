#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


/*class Solution {
public:
	int longestValidParentheses(string s) {
		int longsize = 0;
		int maxsize = 0;
		stack<char> s1;
		for (auto it = s.begin(); it!=s.end(); it++)
		{
			switch (*it)
			{
			case ')': {
				if (!s1.empty())
				{
					s1.pop();
					if(!s1.empty()&&it==s.end()-1)
						longsize = 2;
					else
						longsize += 2;
					maxsize = longsize>maxsize ? longsize : maxsize;
					break;
				}
				else
				{
					longsize = 0;
					break;
				}
			}
			case '(':
			{
				s1.push(*it);
				break;
			}
			}
		}
		return maxsize;
	}
};*/


class Solution
{
public:
	/*int longestValidParentheses(string s)
	{
		int leftnum = 1;
		int number[20];
		int max = 0;
		stack<char> s1;
		memset(number, 0, sizeof(number));
		for (auto it = s.begin(); it != s.end(); it++)
		{
			switch (*it)
			{
			case '(':
			{
				leftnum++;
				s1.push(*it);
				number[leftnum]++;
				break;
			}
			case ')':
			{
				if (!s1.empty())
				{
					number[leftnum]++;
					leftnum--;
					s1.pop();

				}
				break;
			}
			default:
				break;
			}
		}
		for (int i = 20 - 1; i >= 0; i--)
		{
			if (number[i] != 0 && number[i - 1] != 0 && number[i - 1] != 1 && number[i] != 1&&number[i-1]%2==0&&number[i]%2==0)
				number[i - 1] = number[i - 1] + number[i];
		}

		for (int i = 0; i < 20; i++)
			if (number[i] > max)
				max = number[i];
		if (max % 2 == 1)
			max = max - 1;
		return max;

	}*/
	int longestValidParentheses(string s) {
		int cnt = 0; // count of "("
		vector<int> dp(s.size() + 1, 0);

		for (size_t i = 1; i <= s.size(); i++) {
			if (s[i - 1] == '(') {
				cnt++;
			}
			else {
				if (cnt > 0) {  // there exists an unclosed "(" to match ")"
					cnt--;
					dp[i] = 2;
					if (s[i - 2] == ')')  // add the length of previous closed ")" neighbor
						dp[i] += dp[i - 1];
					dp[i] += dp[i - dp[i]]; // add the length of previous valid parentheses
				}
			}
		}

		return *max_element(dp.begin(), dp.end());
	}
};


int main()
{
	string s = { "()(()" };
	Solution t;
	auto longsize1 = t.longestValidParentheses(s);
	return 0;
}