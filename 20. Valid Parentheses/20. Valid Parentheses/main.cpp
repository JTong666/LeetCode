#include<string>
#include<map>
using namespace std;



class Solution
{
public:
	bool isValid(string s)
	{
		map<char, char> str;
		str.insert(make_pair(')', '(')); str.insert(make_pair(' ]', '[')); str.insert(make_pair('}', '{'));
		string ch;
		for (auto &t:s)
		{
			if (t == '(' || t == '[' || t == '{')
				ch.push_back(t);
			else
				if (ch.size() == 0)
					return false;
				else
				{
					if (str.find(t)->second == ch.back())
						ch.pop_back();
					else
						return false;
				}
		}
		if (ch.size() == 0)
			return true;
		else
			return false;
	}
};