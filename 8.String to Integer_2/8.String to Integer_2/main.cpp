#include<string>
#include<iostream>
using namespace std;


class Solution
{
public:
	int myAtoi(string str)
	{
		int ret = 0, tag = 1, base = INT_MAX / 10;
		int i;
		i = str.find_first_not_of(' ');
		if (str[i] == '-')
			tag = -1;
		while (isdigit(str[i]))
		{
			if (ret > base || (ret == base&&str[i] - '0' > 7))
				return tag > 0 ? INT_MAX : INT_MIN;
			ret = static_cast<int>(ret * 10 + (str[i++] - '0'));
		}
		return tag*ret;
	}
};

int main()
{
	Solution s;
	int h;
	string s1 = { "   2147483648wes" };
	h = s.myAtoi(s1);
	return h;
}