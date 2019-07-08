#include<algorithm>
#include<vector>
using namespace std;

/*class Solution {
public:
	vector<vector<int>> threesum(vector<int>& nums)
	{
		vector<vector<int>> re;
		vector<int> p;
		p = nums;
		if(p.size()<3)
		return re;
		sort(p.begin(), p.end());
		auto it = find_if(p.begin(), p.end(), [](const int a) {return a >= 0; });
		auto begin = p.begin();
		auto end = p.end() - 1;
		int time = 1;
		while (begin<end)
		{
			int sum = 0;
			sum = *begin + *end;
			if (sum > 0)
			{
				auto result = find(begin + 1, it, (-1 * sum));
				if (result != it+1 )
				{
					vector<int> m;
					m.push_back(*begin);
					m.push_back(*result);
					m.push_back(*end);
					re.push_back(m);
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}

				}
				else
				{
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}
				}
			}
			else if (sum < 0)
			{
				auto result = find(it, end,-sum);
				if (result != end)
				{
					vector<int> m;
					m.push_back(*begin);
					m.push_back(*result);
					m.push_back(*end);
					re.push_back(m);
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}
				}
				else
				{
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}
				}
			}
			else
			{
				if (*it == 0)
				{
					vector<int> m;
					m.push_back(*begin);
					m.push_back(*it);
					m.push_back(*end);
					re.push_back(m);
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}
				}
				else
				{
					if (time == 1)
					{
						begin++;
						time = 0;
					}
					else
					{
						end--;
						time = 1;
					}

				}
			}
		}
		re.erase(unique(re.begin(), re.end()), re.end());
		return re;
	}
};*/


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> re;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				int s = nums[i] + nums[l] + nums[r];
				if (s > 0)
					r--;
				else if (s < 0)
					l++;
				else
				{
					re.push_back(vector<int>{ nums[i], nums[l], nums[r]});
					while (nums[l] == nums[l + 1]&&(l<nums.size()-2))
						l++;
					while (nums[r] == nums[r - 1]&&(r>1))
						r--;
					l++;
					r--;
				}
			}
		}
		return re;
	}
};










int main()
{
	Solution s;
	vector<vector<int>>res;
	vector<int> sum = {};
	res = s.threeSum(sum);
	return 0;
}