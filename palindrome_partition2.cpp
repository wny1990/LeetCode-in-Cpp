class Solution {
public:
int minCut(string s)
{
	if (s.size() == 0 || s.size() == 1) return 0;

       	vector<vector<bool> > isPal;
	int n = s.size();
// initialize the bool matrix
	for ( int i = 0; i < n; i++ )
	{
		vector<bool> row(s.size(),false);
		isPal.push_back(row);
	}
// calculate the bool matrix
/*
	for ( int i = 0; i < n; i++ )
		for ( int j = i; j < n; j++ )
		{
			if ( i == j)
				isPal.at(i).at(j) = true;
			else
				isPal.at(i).at(j) = palindrome(s.substr(i,j-i+1));
		}
*/
	for ( int len = 1; len <= n; len++ )
		for ( int i = 0; i + len - 1 < n; i++ )
		{
			if ( len == 1)
				isPal[i][i] = true;
			else if ( len == 2 )
				isPal[i][i+len-1] = (s[i] == s[i+1]);
			else if ( s[i] == s[i+len-1])
				isPal[i][i+len-1] = isPal[i+1][i+len-2];
			else
				isPal[i][i+len-1] = false;
		}

	int min_cut[n];

	for ( int i = 0; i < n; i++)
		min_cut[i] = i;

	for ( int i = 1; i < n; i++)
	{
		if ( isPal[0][i])
		{
			min_cut[i] = 0;
			continue;
		}
		for ( int j = 0; j < i; j++)
		{
			if ( isPal.at(j + 1).at(i) && min_cut[j] + 1 < min_cut[i])
			{
				min_cut[i] = min_cut[j] + 1;
				if (min_cut[i] == 1) break;
			}
		}

	}
	return min_cut[n-1];
}
};
