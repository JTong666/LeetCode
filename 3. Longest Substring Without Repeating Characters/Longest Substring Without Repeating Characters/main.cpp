#include<string>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		string copy;
		int max = 0;
		for (char c : s)
		{
			string::size_type size = copy.find_first_of(c);
			if (size != string::npos)
				copy.erase(0, size + 1);
			copy.push_back(c);
			if (copy.size() > max)
				max = copy.size();
		}
		return max;
	}
};


int main()
{
	Solution s;
	string s1("abcabcbb");
	cout<<s.lengthOfLongestSubstring(s1);
	return 0;
}