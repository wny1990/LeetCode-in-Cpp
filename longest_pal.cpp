class Solution {
public:
string longestPalindrome(string s) 
{
	int n = s.size();
	string result;
	if ( n == 0 ) return result;
	bool isPal[1000][1000];
	int start,length;
	for ( int len = 1; len <= n; len++ )
		for ( int i = 0; i + len - 1 < n; i++ )
		{
			if ( len == 1)
				isPal[i][i] = true;
			else if ( len == 2 )
				isPal[i][i+len-1] = ( s[i] == s[i+1]);
			else if ( s[i] == s[i+len-1])
				isPal[i][i+len-1] = isPal[i+1][i+len-2];
			else
				isPal[i][i+len-1] = false;
			if (isPal[i][i+len-1] == true) 
			{
				start = i;
				length = len;
			}
		}
	return s.substr(start,length);

    }
};
