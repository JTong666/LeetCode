#include<algorithm>
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int>as;
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			auto i = find(it + 1, nums.end(), target - *it);
			if (i == nums.end())
				;
			else
			{
				as.push_back(it - nums.begin());
				as.push_back(i - nums.begin());
			}
		}
		return as;
	}
};

int main()
{
	vector<int> num = {15,11,7,2}, as;
	Solution s1;
	as = s1.twoSum(num, 9);
	cout << *(as.begin()) << endl << *(as.begin() + 1);
	return 0;
}