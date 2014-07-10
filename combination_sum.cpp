class Solution {
public:
void dfs( int level, int sum, vector<int> &nums, vector<int> vec, int target)
{
	if (sum == target )
	{
		result.push_back(vec);
		return;
	}
	if ( level >= nums.size() )
		return;
	int times = (target - sum)/nums[level];
	
	dfs(level + 1,sum,nums,vec,target);

	for ( int i = 1; i <= times; i++)
	{
		vec.push_back(nums[level]);	
		dfs(level + 1,sum + i*nums[level],nums,vec,target);
	}

	return;
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
{
	sort(candidates.begin(),candidates.end());
	dfs(0,0,candidates,vector<int>(),target);
	return result;
}
private:
	vector<vector<int>>  result;
};
