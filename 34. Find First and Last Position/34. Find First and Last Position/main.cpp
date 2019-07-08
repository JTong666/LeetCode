#include<iostream>
#include<vector>
using namespace std;


class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		if (nums.size() == 0)
			return{ -1 , -1 };
		int it1 = search(nums, target);
		int it2 = search(nums, target+1) - 1;
		if (it1 <= nums.size() - 1 && nums[it1] == target)
			return{ it1, it2 };
		else
			return{ -1, -1 };
	}
private:
	int search(vector<int>&nums, int target)
	{
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return l;
	}
};