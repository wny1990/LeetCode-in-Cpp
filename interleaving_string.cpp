class Solution {
public:
bool isInterleave(string s1, string s2, string s3) 
{
	if ( !s1.size() && !s2.size() && !s3.size())
		return true;
	if ( (s1.size() + s2.size()) != s3.size())
		return false;
	vector<vector<bool> > match(s1.size() + 1,vector<bool>(s2.size() + 1,false));
	match[0][0] =true;

	for( int i = 1; i <= s1.size(); i++)
		if ( (s3[i-1] == s1[i-1]) && match[i-1][0])
			match[i][0] = true;

	for( int j = 1; j <= s2.size(); j++)
		if (s3[j-1] == s2[j-1] && match[0][j-1])
			match[0][j] = true;

	for( int i = 1; i <= s1.size();  i++)
		for( int j = 1; j <= s2.size();  j++)
		{
			if ( s3[i+j-1] == s1[i-1] && match[i-1][j])
				match[i][j] = true;
			if ( s3[i+j-1] == s2[j-1] && match[i][j-1])
				match[i][j] = true;
		}

	return match[s1.size()][s2.size()];
}
};
