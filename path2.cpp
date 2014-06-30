class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
        int n = obstacleGrid.size();
	if ( n == 0 ) return 0;
        int m = obstacleGrid.at(0).size();
	vector<vector<int> > num(n,vector<int>(m,0));
	if ( obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
		return 0;
	num[0][0] = 1;
	for ( int i = 0; i < n ; i++ )
		for ( int j = 0; j < m ; j++ )
		{
			if ( (i==0 && j==0) || obstacleGrid[i][j])
				continue;
			if ( i > 0 && obstacleGrid[i-1][j] == 0 )
				num[i][j]+= num[i-1][j];
			if ( j > 0 && obstacleGrid[i][j-1] == 0 )
				num[i][j]+= num[i][j-1];
		}

	return num[n-1][m-1];	
}
};
