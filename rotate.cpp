class Solution {
public:
void rotate(vector<vector<int> > &matrix)
{
	int n = matrix.size();
	for ( int i = 0; i < (n + 1) / 2 ; i++)
		for ( int j = 0; j < n ; j++)
			swap(matrix.at(i).at(j),matrix.at(n-1-i).at(j));

	for ( int i = 0; i < n ; i++)
		for ( int j = 0; j < i ; j++)
			swap(matrix.at(i).at(j),matrix.at(j).at(i));
	return;
}
};
