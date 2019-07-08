#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		int l = 0;
		int r = nums.size() - 1;
		if (nums.size() == 0)
			return 0;

		while (l <= r)
		{
			if (l == r)
			{
				if (nums[l] == target)
					return l;
				else if (nums[l] < target)
					return l + 1;
				else
					if (l == 0)
						return 0;
					else
						return l;
			}
			int mid = static_cast<int> ((r + l) / 2);
			if (nums[mid] > target)
				r = mid - 1;
			else if (nums[mid] < target)
				l = mid + 1;
			else
				return mid;
		}
		return l;
	}
};


int main()
{
	Solution s;
	vector<int> p = { 3,5,7,9,10 };
	int a = s.searchInsert(p, 8);
    return 0;
}