class Solution {
public:
vector<int> grayCode(int n) 
{
	vector<int> result;       
	if (n == 0)
		return result;

	result.push_back(0);
	if (n == 1)
		return result;
	result.push_back(1);

	if (n == 2)
		return result;
	for( int i = 3; i <= n; i++ )
	{
		vector<int> temp; 
		for ( int j = 0; j < pow(2,i-1); j++)
		{
			int num = result.at(j);
			num += pow(2,i-1);
			temp.push_back(num);
		}	      
		for ( int j = pow(2,i-1) - 1; j >= 0 ;j--)
		{
			result.push_back(temp.at(j));
		}

	}
	return result;
}
};
