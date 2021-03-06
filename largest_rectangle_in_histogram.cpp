class Solution {
public:
void init_st(vector<int > &nums, vector<vector<int> > &st)
{
	int n = nums.size();
	int m = (log(nums.size())/log(2)) + 1;
	st = vector<vector<int> >  (n,vector<int>(m,0));
	int offset;
	for ( int size = 0; size < m; size++)
	{
		if (size == 0 )
			offset = 1;
		else
			offset = 2*offset;
		for ( int i = 0; i + offset -1 < n; i++)
		{
			if (size == 0)
				st[i][size] = i;
			else
			{
				if ( nums[st[i][size-1]] >= nums[ st[i+offset/2][size-1]])
					st[i][size] =  st[i+offset/2][size-1];
				else
					st[i][size] = st[i][size-1];
			}
		}		
	}
	return;
}
int query_min( vector<vector<int> > &st, vector<int> nums,int s, int e)
{
	if (s == e)
		return s;
	int k = log(e - s + 1)/log(2);
	if (nums[st[s][k]] > nums[st[e-pow(2,k)+1][k]] )
		return st[e-pow(2,k)+1][k];
	else
		return st[s][k];
}
int trace(vector<vector<int> > &st ,vector<int> &height , int s , int e)
{
	if (s == e)
		return height[s];
	int left = INT_MIN;
	int right = INT_MIN;
	int index = query_min(st,height,s,e);
	if (index - 1>= s)
		left = trace(st,height,s,index-1);
	if (index + 1 <= e)
		right = trace(st,height,index+1,e);
	return max(max(left,right),(e-s+1)*height[index]);
}
int largestRectangleArea(vector<int> &height) 
{
	if ( height.empty())
		return 0;
	vector< vector<int> >  st;
	init_st(height,st);
	return trace(st,height,0,height.size() -1 );
}


};
