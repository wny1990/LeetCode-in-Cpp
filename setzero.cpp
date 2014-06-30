class Solution {
public:
void setZeroes(vector<vector<int> > &matrix) 
{
	int m;
	int n;
	m = matrix.size();
	n = matrix.at(0).size();
	bool row0 = false;
	bool col0 = false;
	for( int i = 0; i < n; i ++ )
		if (matrix.at(0).at(i) == 0)
			row0 = true;

	for( int i = 0; i < m; i ++ )
		if (matrix.at(i).at(0) == 0)
			col0 = true;

	if ( m > 1 && n > 1)
	{
	for( int i = 1; i < n; i++)
		for( int j = 0; j < m; j++)
			if(matrix.at(j).at(i) == 0)
				matrix.at(0).at(i) = 0;
	for( int i = 1; i < m; i++)
		for( int j = 0; j < n; j++)
			if(matrix.at(i).at(j) == 0)
				matrix.at(i).at(0) = 0;
	
	for( int i = 1; i < m; i++)
	{
		if(matrix.at(i).at(0) == 0)
			for( int j = 0; j < n; j++)
				matrix.at(i).at(j) = 0;
	}
	
	for( int i = 1; i < n; i++)
	{
		if(matrix.at(0).at(i) == 0)
			for( int j = 0; j < m; j++)
				matrix.at(j).at(i) = 0;
	}
	}
	if(row0)
	{
			for( int j = 0; j < n; j++)
				matrix.at(0).at(j) = 0;
	}

	if(col0)
	{
			for( int j = 0; j < m; j++)
				matrix.at(j).at(0) = 0;
	}

	return;
}
};
