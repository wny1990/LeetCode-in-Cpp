class Solution {
public:
int minDistance(string word1, string word2)
{
	int dist[word1.size() + 1][word2.size() + 1];
	for( int i = 0 ; i < word1.size() + 1; i ++ )
		dist[i][0] = i;	
	for( int i = 0 ; i < word2.size() + 1; i ++ )
		dist[0][i] = i;	
	for( int i = 1 ; i < word1.size() + 1; i ++ )
		for( int j = 1 ; j < word2.size() + 1; j ++ )
		{
			if (word1[i -1] == word2[j -1])
				dist[i][j] = dist[i-1][j-1];
			else
				dist[i][j] = min (min(dist[i-1][j],dist[i][j-1]),dist[i-1][j-1]) +  1;
		}	
	return    dist[word1.size()][word2.size()];
}
};
