class Solution {
public:
bool valid(int row_num, int i, vector<int> &cols)
{
	for(auto it = 0; it < cols.size(); it++)
		if (cols[it] == i || abs(i-cols[it]) == abs(it - row_num))
			return false;
	return true;
}
void find(int row_num,vector<int> &cols,int n)
{
	for (int i = 0; i < n; i++)
		if (valid(row_num,i,cols))
		{
			cols.push_back(i);
			if (row_num < n - 1) find(row_num + 1,cols,n);
			else if (row_num == n - 1)
			{
				vector<string> sol_vec;
				for(auto it = cols.begin(); it != cols.end(); it++)
				{	
					string row_str;
					for ( int j = 0; j < n; j ++ )
					{
						if (*it == j)
							row_str.push_back('Q');
						else
							row_str.push_back('.');
					}
					sol_vec.push_back(row_str);
				}
				result.push_back(sol_vec);
			}
			cols.pop_back();
		}
	return;
}

vector<vector<string> > solveNQueens(int n) 
{
	vector<int> cols;
	find(0,cols,n);
	return result;
}
private:
	vector<vector<string> > result;
};
