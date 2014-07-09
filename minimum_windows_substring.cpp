class Solution {
public:
string minWindow(string S, string T)
{
	int min = INT_MAX;
	vector<int> t_vec(256,0);
	vector<int> s_vec(256,0);
	for(int i = 0; i < T.size();i++)
		t_vec[T[i]]++;
	int c_count(0),j(0);
	int left(-1),right(-1);
	while( j < S.size() && t_vec[S[j]] == 0)
		j++; 
	for( int i = 0; i < S.size(); i++)
	{
		if ( t_vec[S[i]] )	
		{
	 		if ( s_vec[S[i]] < t_vec[S[i]])
				c_count++;
			s_vec[S[i]]++;
		}
		while (c_count == T.size() )	
		{
			if ((i - j) < min)
			{
				min =  i-j;
				left = j;
				right = i;
			}
			if ( t_vec[S[j]] && s_vec[S[j]] <= t_vec[S[j]] )	
				c_count--;
			s_vec[S[j++]]--;
		}
	} 
	if (left == -1 && right == -1)
		return "";
	else
		return S.substr(left,right-left+1);
    }
};
