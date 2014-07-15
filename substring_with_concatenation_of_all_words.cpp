//class Solution {
//public:
//Well....... this code is not good enough. It needs improvment.
vector<int> findSubstring(string S, vector<string> &L) 
{
	vector<int> result;
	if (L.empty() || S.empty())
		return result;
	unordered_map<string,int> smap;
	unordered_map<string,int> dmap;
	int len = S.size();
	int len1 = L[0].size();

	for( int i = 0; i < L.size(); i++ )
		if (!smap.count(L[i]))
		{
			smap[L[i]]=i;
			dmap[L[i]] = 1;
		}
		else
			dmap[L[i]]++;
				

	vector<int> match(len,-1);     
	vector<int> dup(len,0);     

 	for( int i = 0; i < len - len1 + 1;  i ++)
	{
		string s1 = S.substr(i,len1);
		if ( smap.count(s1) )
		{
			match[i] = smap[s1];
			dup[i] = dmap[s1];
		}
	}
	for( int i = 0; i < len1;  i++)
	{
		int start = i;
		while (start < len - len1 + 1 && match[start] == -1)
			start+= len1;
		vector<int> repeat(L.size(),0);
		int sum = 0;
		for(int j = start; j < len- len1 + 1; j+= len1)
		{
			if (match[j] == -1 || repeat[match[j]] >= dup[j] )
			{
				if (match[j] == -1 )
					start = j + len1;
				else
				{
					j = start;
					start = start + len1 ;
				}
				sum = 0;
				repeat = vector<int>(L.size(),0);
				continue;
			}
			if(repeat[match[j]] < dup[j])
				sum++;
			repeat[match[j]]++;
			while (sum == L.size() )
			{
				result.push_back(start);
				repeat[match[start]]--;
				if ( repeat[match[start]] < dup[start] )
					sum--;
				start += len1;
			}
		}
	}
	return result;
}
};
