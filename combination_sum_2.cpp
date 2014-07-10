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

	if ( sum > target  )
		return;
	int level1 = level + 1;

	while( level1  < nums.size() && nums[level1] == nums[level1 - 1] )
		level1++;

	dfs(level1,sum,nums,vec,target);

	vec.push_back(nums[level]);	

	dfs(level + 1,sum + nums[level],nums,vec,target);
	vec.pop_back();

	return;
}
vector<vector<int> > combinationSum2(vector<int> &num, int target) 
{
	vector<int> vec;
	sort(num.begin(),num.end());
	dfs(0,0,num,vec,target);
	return result;
}
private:
	vector<vector<int>>  result;
};
