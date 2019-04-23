#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	bool isMathch(string s, string p)
	{
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
				}
				else {
					dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
			}
		}
		return dp[m][n];
	}
};


int main()
{
	Solution s;
	string s1 = { "mississippi" };
	string s2 = { "mis*is*p*." };
	cout<<s.isMathch(s1, s2);
	return 0;
}


















