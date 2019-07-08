#include<vector>
using namespace std;


class Solution {
public:
	int removeElement(vector<int>& nums, int val)
	{
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			if (nums[0] == val)
			{
				nums.pop_back();
				return 0;
			}
			else
				return 1;
		auto it1 = nums.begin();
		auto it2 = nums.begin();
		while (it2!=nums.end())
		{
			if (*it1 == val)
			{
				if (*it2 != val)
				{
					int a = *it2;
					*it2 = *it1;
					*it1 = a;
					it1++;
					it2++;
				}
				else
				{
					it2++;
				}
			}
			else
			{
				it1++;
				it2++;
			}
		}
		int  i = 0;
		for (auto it = nums.begin(); it != it1; it++)
			i++;
		nums.erase(it1, nums.end());
		return i;
	}
};


int main()
{
	Solution s;
	vector<int> p = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int a = s.removeElement(p, 2);
	return 0;
}