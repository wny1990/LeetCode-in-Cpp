class Solution {
public:
bool palindrome( string s)
{
	int i = 0;
	int j = s.size() - 1;
	while ( i < j)
	{
		if ( s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
void probe(string &s, vector<vector<bool> > &isPal, int size,int start,vector<string> str_vec)
{
// if we have finished the partition, add the vector to result.
	if ( start == size)
	{
		result.push_back(str_vec);
		return;
	}

	for( int i = start; i < size; i++)
		if ( isPal.at(start).at(i) )
		{
			vector<string> str_vec1 = str_vec;
			str_vec1.push_back(s.substr(start, i-start+1));
			probe(s,isPal,size,i+1,str_vec1);
		}
	return;
}
vector<vector<string>> partition(string s) 
{
	if (s.size() == 0) return result;

       	vector<vector<bool> > isPal;
	vector<string> str_vec;
	int n = s.size();
// initialize the bool matrix
	for ( int i = 0; i < n; i++ )
	{
		vector<bool> row(s.size(),false);
		isPal.push_back(row);
	}
// calculate the bool matrix

// n^3 solution
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
// n^2 solution
	for ( int len = 1; len <= n; len++ )
		for ( int i = 0; i + len - 1 < n; i++ )
		{
			if ( len == 1)
				isPal.at(i).at(i) = true;
			else if ( len == 2 )
				isPal.at(i).at(i+len-1) = palindrome(s.substr(i,len));
			else if ( s[i] == s[i+len-1])
				isPal.at(i).at(i+len-1) = isPal.at(i+1).at(i+len-2);
			else
				isPal.at(i).at(i+len-1) = false;
		}
// do dfs on the partition recursively
	probe(s,isPal,n,0,str_vec);

	return result;
}
private:
	vector<vector<string>> result;
};
