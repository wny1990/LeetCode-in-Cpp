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
				result++;
			}
			cols.pop_back();
		}
	return;
}

int totalNQueens(int n)

{
	vector<int> cols;
	result = 0;
	find(0,cols,n);
	return result;
}
private:
	int result;
};
