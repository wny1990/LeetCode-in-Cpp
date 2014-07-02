class Solution {
public:
int numDistinct(string S, string T)

{
	if (S.size() ==0 || T.size() == 0)
		return 0;
	if (S.size() < T.size())
		return 0;
	vector<vector<int> > match(S.size(),vector<int>(T.size(),0));
	
	for( int i = 0 ; i < S.size(); i ++ )
		for( int j = 0 ; j <= i && j < T.size(); j ++ )
		{
			if (S[i] == T[j])
			{
				int up(0);
				int left_up(1);
				if ( i > 0 && j> 0 ) left_up = match[i-1][j-1];
				if ( i > 0) up = match[i-1][j];
				match[i][j] = up + left_up;
			}
			else
			{
				if ( i > 0)
					match[i][j] = match[i-1][j];
				else
					match[i][j] = 0;
			}
		}	
	return    match[S.size()-1][T.size()-1];
}
};
