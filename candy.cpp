class Solution {
public:
void dfs
int candy(vector<int> &ratings) 
{
	int n = ratings.size();
	vector<int> degree(n,0);
	for( int i = 0; i < n; i++)
	if ( (i == 0 || ratings[i-1] <= ratings[i])  && (i == n-1 || ratings[i+1] <= ratings[i]) )       
		dfs(i,ratings);
	int sum = 0;
	for ( int i = 0; i < n; i++)
		sum+=degree[i];
	return sum;
}
};
