class Solution {
public:
bool wordBreak(string s, unordered_set<string> &dict)
{
    	int flag[s.size()];
	for ( int i = 0; i< s.size() ; i++)
		flag[i] = false;
	
	for ( int i = 0; i< s.size() ; i++)
		if (dict.find(s.substr(0,i+1)) != dict.end())
				flag[i] = true;

	for ( int i = 0; i< s.size() ; i++)
		for ( int j = 0; j < i ; j++)
		{
			if (flag[j] == true )
			{
				if (dict.find(s.substr(j+1,i-j)) != dict.end())
					flag[i] = true;
			}

		}
       return flag[s.size() -1];
}

};
