#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int firstMissingPositive(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (i + 1 == nums[i])
				continue;
			int x = nums[i];
			while (x >= 1 && x <= nums.size() && x != nums[x - 1])
				swap(x, nums[x - 1]);
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (i + 1 != nums[i])
				return i + 1;
		}
		return nums.size() + 1;
	}
};


int main()
{
	Solution s;
	vector<int> p = { 3, 4, -1,1 };
	auto a = s.firstMissingPositive(p);
	return 0;
}