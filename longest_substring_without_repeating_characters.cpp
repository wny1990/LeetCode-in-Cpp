class Solution {
public:
int lengthOfLongestSubstring(string s) 
{
	int n = s.size();
	if (n == 0 )
		return 0;
	int longest;
	vector<bool> flag(n,true);
	for( int i =0; i < n - 1; i++)
		if( s[i] == s[i+1])
			flag[i] = false;
		else
			longest = 2;

	for( int len = 3; len < n ; len++)
	{
		bool update = false;
		for( int i =0; i < n - len; i++)
		{
			if (!flag[i]) break;
			if (s[i] !=  s[i+len-1] && flag[i+1])
			{
				update = true;
				flag[i] = true;
				longest = len;
			}
			else
				flag[i] = false;
		} 
		if (!update)
			break;
	}
	return longest;
    }
};
