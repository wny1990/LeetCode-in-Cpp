class Solution {
public:
int dfs( int i, vector<int> &ratings, vector<int> &degree)
{
	int left(0),right(0);
	if ( i != 0 && ratings[i-1] < ratings[i])
		left  = dfs(i-1,ratings,degree) + 1; 
	if ( i != ratings.size() - 1 && ratings[i+1] < ratings[i])
		right  = dfs(i+1,ratings,degree) + 1;
	degree[i] = max(left,right);
	return degree[i];
}
int candy(vector<int> &ratings) 
{
	int n = ratings.size();
	vector<int> degree(n,0);
	for( int i = 0; i < n; i++)
	if ( (i == 0 || ratings[i-1] <= ratings[i])  && (i == n-1 || ratings[i+1] <= ratings[i]) )       
		degree[i] = dfs(i,ratings,degree);
	int sum = 0;
	for ( int i = 0; i < n; i++)
		sum+=degree[i] + 1;
	return sum;
}
};
