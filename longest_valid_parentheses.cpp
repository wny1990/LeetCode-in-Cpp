#include<iostream>
using namespace std;
//class Solution {
//public:
int longestValidParentheses(string s)
{
	int n = s.size();
	if ( n == 0 ) return 0;
	int  unmatched;
	int max = -1;
	int i = 0;
	while ( i < n )
	{
		int j;
		for ( j = i; j < n; j++ )
		{
			if (j==i)
			{
				if ( s[i] == '(')
					unmatched = 1;
				else
					unmatched = -1;
			}	
			else 
			{
				if( s[j] == '(' )
			 		unmatched = unmatched + 1;
				else
			 		unmatched = unmatched - 1;
			}		
			if (unmatched < 0 )
				break;
			if ( unmatched== 0 && j-i > max)
			{	cout << i << "  " << j << endl;
				max = j- i;
			}
		}
		if (j == n && unmatched > 0)
			i+=unmatched;
		else	
			i = j + 1;
	}
	return max + 1;

    }
//};
int main()
{
	cout << longestValidParentheses(")(((((()())()()))()(()))(" ) << endl;


}
