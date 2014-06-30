vector<int> getRow(int numRows) 
{
	vector<int> oldrow;       
	oldrow.push_back(1);
	if (numRows == 0)
		return oldrow;
	for( int num = 1; num <= numRows + 1; num++)
	{
		vector<int> newrow;       
		for( int i = 1; i<= num; i++)
			if (i==1 || i==num) newrow.push_back(1);
			else
				newrow.push_back(oldrow.at(i-1) + oldrow.at(i-2));
		oldrow = newrow;
	}
	return oldrow;
}
