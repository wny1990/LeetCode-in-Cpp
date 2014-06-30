class Solution {
public:
int minimumTotal(vector<vector<int> > &triangle) 
{
	int size = triangle.size();       
	if (size == 0) return 0;
	vector<int> sum;
	
	for( int i = 0 ; i <= size; i++)
		sum.push_back(0);
	for( int i = size - 1 ; i >= 0; i--)
	{
		vector<int> row;
		row = triangle.at(i);
		for(int j = 0; j <= i; j++)
			if ( sum.at(j+1)  <   sum.at(j) ) 
				sum.at(j) = sum.at(j+1) + row.at(j);
			else
				sum.at(j) += row.at(j);
	} 
	
	return sum.at(0);
		
	return 0;
}
};
