#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height)
	{
		int water = 0;
		int i = 0, j = height.size() - 1;
		while (i<j)
		{
			int h = min(height[i], height[j]);
			int sum = h*(j - i) ;
			if (sum > water)
				water = sum;
			while (height[i] <= h&&i<j)
				i++;
			while (height[j] <= h&&i < j)
				j--;
		}
		return water;
	}
};

