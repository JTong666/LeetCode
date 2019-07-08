#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
 	{
		int sum = 0;
		int distance = INT_MAX;
		int closestnumber = 0;
		sort(nums.begin(), nums.end());
		if (nums.size() == 3)
			return nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				sum = nums[i] + nums[l] + nums[r];
				if (sum - target > 0)
				{
					r--;
					if (abs(sum - target) < distance)
					{
						distance = abs(sum - target);
						closestnumber = sum;
					}
				}
				else if (sum - target < 0)
				{
					l++;
					if (abs(sum - target) < distance)
					{
						distance = abs(sum - target);
						closestnumber = sum;
					}
				}
				else
					return target;
			}
		}
		return closestnumber;
	}
};


int main()
{
	Solution s;
	vector<int> nums = { 1, 1, -1, -1, 3 };
	int j = s.threeSumClosest(nums, 1);
	return 0;
}