class Solution {
public:
int longestValidParentheses(string s)
{
	int n = s.size();
	if ( n == 0 ) return 0;
	int  unmatched[n];
//	vector<vector<short> > unmatched;
/*	
	for ( int i = 0; i < n; i++ )
	{
		vector<short> row(n,0);
		unmatched.push_back(row);
	}
*/
	int max = 0;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i; j < n; j++ )
		{
			if (j==i)
			{
				if ( s[i] == '(')
					unmatched[j] = 1;
				else
					unmatched[j] = -1;
			}	
			else if ( unmatched[j-1] >= 0 )
			//	unmatched[i][j] = unmatched[i][j-1] + (s[j] == '(') ? 1:(-1);
				if( s[j] == '(' )
			 		unmatched[j] = unmatched[j-1] + 1;
				else
			 		unmatched[j] = unmatched[j-1] - 1;
					
			else
				unmatched[j] = -1;
			if ( unmatched[j] == 0 && j-i > max)
				max = j- i;
		}
	}
	return max + 1;

    }
};
