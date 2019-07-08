#include<vector>
#include<algorithm>

using namespace std;


/*class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> v;
		if (nums.size() < 4)
			return v;
		int sum = 0;
		size_t len = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1;
			int r = nums.size() - 1;
			int mid = l + 1;
			while (l < r)
			{
				while (mid < r)
				{
					sum = nums[i] + nums[l] + nums[mid] + nums[r];
					if (sum > target)
						r--;
					else if (sum < target)
						mid++;
					else
					{
						v.push_back(vector<int> {nums[i], nums[l], nums[mid], nums[r]});
						break;
					}
				}
				if (sum > target)
					break;
				else if (sum == target)
				{
					     //在考虑等于标签之后返回的值出现了问题  需要在多线程下考虑两种情况  所以终止这种方法
				}
				else 
				{
					l++;
					mid = l + 1;
				}

			}
		}
		return v;
	}
};*/


class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		int sum = 0;
		int number = 0;
		vector<vector<int>> v;
		vector<int> tab;
		if (nums.size() < 4)
			return v;
		size_t len = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < nums.size() - 2; j++)
			{
				if (j > i+1 && nums[j] == nums[j - 1])
					continue;
				int l = j + 1;
				int r = nums.size() - 1;
				while (l < r)
				{
					sum = nums[i] + nums[j] + nums[l] + nums[r];
					if (sum > target)
						r--;
					else if (sum < target)
						l++;
					else
					{
						v.push_back(vector<int> {nums[i], nums[j], nums[l], nums[r]});
						do {
							l++;
						} while (nums[l] == nums[l - 1] && l < r);
						do {
							r--;
						} while (nums[r] == nums[r + 1] && l < r);
					}
				}
			}
		}
		return v;
	}
};











int main()
{
	Solution s;
	vector<int> s1{-1, -5, -5, -3, 2, 5, 0, 4};
	auto t = s.fourSum(s1, -7);
	return 0;
}