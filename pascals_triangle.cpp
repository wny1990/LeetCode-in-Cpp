vector<vector<int> > generate(int numRows) 
{
	vector<int> oldrow;       
	vector<vector<int> > result;
	oldrow.push_back(1);
	if (numRows == 0)
		return result;
	result.push_back(oldrow);
	if (numRows == 1)
		return result;
	for( int num = 2; num <= numRows; num++)
	{
		vector<int> newrow;       
		for( int i = 1; i<= num; i++)
			if (i==1 || i==num) newrow.push_back(1);
			else
				newrow.push_back(oldrow.at(i-1) + oldrow.at(i-2));
		oldrow = newrow;
		result.push_back(oldrow);
	}
	return result;
}
