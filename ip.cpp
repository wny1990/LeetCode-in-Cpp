class Solution {
public:
void probe(string &s, vector<vector<bool> > &isValid, int start,string str,int depth)
{
// if we have finished the partition, add the vector to result.
	if ( start == s.size() && depth ==4)
	{
		result.push_back(str);
		return;
	}

	if (depth == 4 || start == s.size()) 
		return;

	for( int i = start; i < s.size() && i < start + 3; i++)
		if ( isValid[start][i] )
		{
			string str1 = str;
			if (str1.size()) str1.push_back('.');
			str1.append((s.substr(start, i-start+1)) );
			probe(s,isValid,i+1,str1,depth+1);
		}
	return;
}

bool valid( string s )
{
	int sum = 0;
	for ( int i =0; i < s.size(); i++)
	{
		sum = sum *10;
		sum+= (s[i]-'0');
		if ( sum == 0 ) 
			return false;
	}
	if (sum >255)
		return false;
	return true;
}

vector<string> restoreIpAddresses(string s)
{
	int n = s.size();
	if (n < 4  || n> 12) return result;
// initialize the bool matrix
       	vector<vector<bool> > isValid(n,vector<bool>(n,false));
// calculate the bool matrix
	for ( int i = 0; i < n; i++ )
		for ( int j = i; j < n; j++ )
		{
			if ( i == j)
				isValid[i][j] = true;
			else if ( i - j > 2 )
				isValid[i][j] = false;
			else	isValid[i][j] =  valid(s.substr(i,j-i+1));
		}

	string str;

// do dfs on the partition recursively
	probe(s,isValid,0,str,0);

	return result;
}
private:
	vector<string> result;
};
