class Solution {
public:
bool searchMatrix(vector<vector<int> > &matrix, int target) 
{
	if (matrix.size() == 0)
		return false;
	int m = matrix.size();
	int n = matrix.at(0).size();
        int left = 0;
        int right = m*n - 1;
	while (left <= right)
	{
		int pivot = (right + left)/2;
		int value = matrix.at(pivot/n).at(pivot%n);
		if (value == target ) return true;
		if ( value > target)
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	return false;
}
};
