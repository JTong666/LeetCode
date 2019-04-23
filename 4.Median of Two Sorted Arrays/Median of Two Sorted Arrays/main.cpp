#include<vector>
#include<iostream>
using namespace std;



class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> nums3;
		double mid;
		int time = 0, i = 0, j;
		i = (nums1.size() + nums2.size()) / 2;
		if ((nums1.size() + nums2.size()) % 2 == 0)
		{
			j = i + 1;
			i = i - 1;
			j = j - 1;
		}
		else
			j = i;
		auto it1 = nums1.begin();
		auto it2 = nums2.begin();
		while (true)
		{
			if (it1 != nums1.end() && it2 != nums2.end())
			{
				if (*it1 >= *it2)
				{
					nums3.push_back(*it2);
					it2++;
					time++;
				}
				else
				{
					nums3.push_back(*it1);
					it1++;
					time++;
				}
			}
			else if (it1 == nums1.end() && it2 != nums2.end())
			{
				nums3.push_back(*it2);
				it2++;
				time++;
			}
			else if (it2 == nums2.end() && it1 != nums1.end())
			{
				nums3.push_back(*it1);
				it1++;
				time++;
			}
			else if (it2 == nums2.end() && it1 == nums1.end())
				break;
		}
		mid = (nums3[i] + nums3[j]) / 2.0;
		return mid;
	}
};

int main()
{
	Solution s;
	double sum;
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {3, 4};
	sum = s.findMedianSortedArrays(nums1, nums2);
	cout << sum;
	return 0;
}
