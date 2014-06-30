class Solution {
public:
vector<string> wordBreak(string s, unordered_set<string> &dict)
{
    	int flag[s.size()];
	vector<vector<string> > sol;
	
	for ( int i = 0; i< s.size() ; i++)
	{
		vector<string> temp;
		sol.push_back(temp);
	}	
	for ( int i = 0; i< s.size() ; i++)
		flag[i] = false;
	
	for ( int i = 0; i< s.size() ; i++)
	{
		if (dict.find(s.substr(0,i+1)) != dict.end())
		{
			flag[i] = true;
			sol.at(i).push_back(s.substr(0,i+1));
		}
	}
	for ( int i = 0; i< s.size() ; i++)
		for ( int j = 0; j < i ; j++)
		{
			if (flag[j] == true )
			{
				if (dict.find(s.substr(j+1,i-j)) != dict.end())
				{
					flag[i] = true;
					for( int t = 0; t < sol.at(j).size(); t++)
						sol.at(i).push_back( sol.at(j).at(t) + " " + s.substr(j+1,i-j));
				}
			}

		}
       return sol.at(s.size()-1);
}

};
