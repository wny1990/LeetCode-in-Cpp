class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
        int n = obstacleGrid.size();
	if ( n == 0 ) return 0;
        int m = obstacleGrid.at(0).size();
	vector<int> num0(m,0);
	vector<int> num(m,0);
	num[0] = 1;
	for ( int i = 0; i < n ; i++ )
	{
		num = vector<int>(m,0);
		for ( int j = 0; j < m ; j++ )
		{
			if ( i==0 && j==0 )
			{
				num[j] = 1; 
			}
			if ( obstacleGrid[i][j] == 1 )
			{
				num[j] = 0; continue;
			}
			if ( i > 0 && obstacleGrid[i-1][j] == 0 )
				num[j]+= num0[j];
			if ( j > 0 && obstacleGrid[i][j-1] == 0 )
				num[j]+= num[j-1];
		}
		num0 = num;
	}
	return num[m-1];	
}
};
