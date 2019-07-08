#include<vector>
using namespace std;

class Solutiopn {
public:
	vector<vector<int>> combinationSum(vector<int>& candiates, int target)
	{
		vector<vector<int>> nums;
		vector<int> num;
		backtrack(nums, num,candiates, target, 0);
		return nums;
	}
private:
	void backtrack(vector<vector<int>>& nums, vector<int>& num, vector<int>& candiates, int target, int i)
	{
		if (target < 0)
			return;
		else if (target == 0)
			nums.push_back(num);
		else
		{
			for (int j = i; j < candiates.size(); j++)
			{
				num.push_back(candiates[j]);
				backtrack(nums, num, candiates, target - candiates[j], j);
				num.pop_back();
			}
		}
	}
};



int main()
{
	Solutiopn s;
	vector<int> p = { 2,3,5 };
	auto a = s.combinationSum(p, 8);
 	return 0;
}