class Solution {
public:
vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
{
	int n = candidates.size();
	vector<vector<bool>> flag(n,vector<bool>(target + 1, false));       
	for ( int i = 0; i < n; i++)
		for ( int j = 0; j < n; i++)
		{
			if (j % candidates[i] == 0)
				flag[i,j] = true;
			if ( i > 0 && flag[i-1,j] = true)
				
				
		}
	
}
};
