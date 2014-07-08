class Solution {
public:
string minWindow(string S, string T)
{
	vector<int> count(256,0);
	int n = S.size();
	if (n == 0 )
		return 0;
	vector<int> t_vec(256,0);
	vector<int> s_vec(256,0);
	string result;
	int min = INT_MAX;
	for(int i = 0; i < T.size();i++)
	{
		t_vec[T[i]]++;
	}
	int c_count = 0;
	int j = 0;
	while( j < n && t_vec[S[j]] == 0)
		j++; 
	for( int i = j; i < n; i++)
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
				result = S.substr(j,i-j+1);
			}
			
			if ( t_vec[S[j]] && s_vec[S[j]] <= t_vec[S[j]] )	
				c_count--;
			s_vec[S[j]]--;
			j++;
		}
	} 
	return result;
    }
};
