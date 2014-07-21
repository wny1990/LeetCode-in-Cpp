class Solution {
public:
string convert(string s, int nRows) 
{
	string result;
	int n = s.size();
	if (nRows == 1)
		return s;
	for( int i = 0; i < nRows; i++)        
	{
		int size = nRows + nRows - 2;
		int k = 0;
		while( size*k  < n)
		{
			if ( size*k + i < n)
				result.push_back(s[size*k + i]);
			if ( size*(k +1) - i < n && size - i > 0 && i && size != 2*i )
				result.push_back(s[size*(k+1) - i]);
			k++;
		}
	}
	return result;
}
};
