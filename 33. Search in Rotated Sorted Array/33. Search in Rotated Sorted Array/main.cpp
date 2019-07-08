#include<vector>
using namespace std;

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int lo = 0, hi = int(nums.size()) - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
				lo = mid + 1;
			else
				hi = mid;
		}
		return lo == hi && nums[lo] == target ? lo : -1;
	}
};


int main()
{
	Solution s;
	vector<int> nums = { 7,8,1,2,3,4,5,6 };
	auto sum = s.search(nums, 2);
	return 0;
}