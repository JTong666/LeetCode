#include<stdio.h>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	vector<string> letterCombinations(string digits)
	{
		Len = digits.size();
		vector<string> v;
		search(digits, 0, "", v);
		return v;
	}
private:
	int Len;
	string digit_map[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	void search(const string& digits, int pos, string path, vector<string>& v)
	{
		if (pos == Len)
			return;
		string s = digit_map[digits[pos] - '2'];
		for (int i = 0; s[i]; i++)
		{
			if (pos == Len - 1)
				v.push_back(path + s[i]);
			else
				search(digits, pos + 1, path + s[i], v);
		}
	}
};


int main()
{
	Solution s;
	string s1 = { "2348" };
	auto t = s.letterCombinations(s1);
	return 0;
}