class Solution {
public:
int minDistance(string word1, string word2)
{
	int match[word1.size() + 1][word2.size() + 1];
	match[0][0] = 0;
	for( int i = 0 ; i < word1.size() + 1; i ++ )
		match[i][0] = i;	
	for( int i = 0 ; i < word2.size() + 1; i ++ )
		match[0][i] = i;	
	for( int i = 1 ; i < word1.size() + 1; i ++ )
		for( int j = 1 ; j < word2.size() + 1; j ++ )
		{
			if (word1[i -1] == word2[j -1])
				match[i][j] = match[i-1][j-1];
			else
				match[i][j] = min (min(match[i-1][j],match[i][j-1]),match[i-1][j-1]) +  1;
		}	
	return    match[word1.size()][word2.size()];
}
};
