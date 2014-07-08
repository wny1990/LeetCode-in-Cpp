class Solution {
public:
int lengthOfLongestSubstring(string s) 
{
	vector<int> count(256,0);
	int longest = 0;
	int n = s.size();
	if (n == 0 )
		return 0;
	int j = 0;
	for( int i = j; i < n; i++)
	{
		count[s[i]]++;
		if (count[s[i]] > 1)
		{
			while( s[i] != s[j] )
			{
				count[s[j]]--;
				j++;
			}
			count[s[j]]--;
			j++;
		}
		if ((i - j) > longest)
			longest =  i-j;
	} 
	return longest + 1;
    }
};
