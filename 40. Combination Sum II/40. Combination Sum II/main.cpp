#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		map<int, bool> mp;
		vector<vector<int>> nums;
		vector<int> num;
		//sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); i++)
		{
			pair<int, bool> p = make_pair(i, false);
			mp.insert(p);
		}
		backstarck(nums, num, mp,candidates,target, 0);
		return nums;
	}
private:
	void backstarck(vector<vector<int>>& nums, vector<int> num, map<int, bool>& mp,vector<int>& candidates, int target, int i)
	{
		if (target < 0)
			return;
		else if (target == 0)
		{
			int flag = 0;
			sort(num.begin(), num.end());
			for (auto& it : nums)
				if (it == num)
				{
					flag = 1;
					break;
				}
			if (flag == 0)
				nums.push_back(num);
		}
		else
		{
			for (int j = i; j < candidates.size(); j++)
			{
				if (mp[j])
					continue;
				num.push_back(candidates[j]);
				mp[j] = true;
				backstarck(nums, num, mp, candidates, target - candidates[j], j);
				num.pop_back();
				mp[j] = false;
			}
		}
	}
};



int main()
{
	Solution s;
	vector<int> p = { 10, 1, 2, 7, 6, 1, 5 };
	auto a = s.combinationSum2(p, 8);
	return 0;
}