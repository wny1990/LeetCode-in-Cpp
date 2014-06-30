class Solution {
public:
int minPathSum(vector<vector<int> > &grid)
{
	vector<vector<int> > cost;
	cost = grid;
	for(int i = 0; i < cost.size(); i++)
		for(int j = 0; j < (cost.at(i)).size(); j ++)
		{
			int up = INT_MAX;
			int left = INT_MAX;
			if( i == 0 & j == 0 )
				continue;
			if( i != 0 ) 
				up = cost.at(i-1).at(j);
			if( j != 0 ) 
				left = cost.at(i).at(j-1);
			if (left < up ) 
				cost.at(i).at(j) = left + grid.at(i).at(j);
			else
				cost.at(i).at(j) = up + grid.at(i).at(j);
		}
	int s1 = cost.size();
	int s2 = cost.at(0).size();
	return cost.at(s1-1).at(s2-1);
}
};
