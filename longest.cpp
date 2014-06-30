class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  	int count[256];
  	int longest = 0;
	int start = 0;
	for(int i = 0; i < 256; i++)
		count[i] = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(count[s[i]]!=0)
		{
			if ( (i - start) > longest)
				longest = (i - start);
			for(int j = 0; j < 256; j++)
				count[j] = 0;
			start = i;
		}
		count[s[i]] = 1;
	}     
	if ((s.size() - start) > longest)
		return s.size() - start;
	return longest;
    }
};
