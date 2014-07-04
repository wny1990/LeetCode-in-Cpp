class Solution {
public:
vector<string> anagrams(vector<string> &strs) 
{
	set< vector<int> > myset;
	vector<bool> flag(strs.size(),false);
	for ( auto it = strs.begin(); it !=strs.end(); it++)
	{
		vector<int> str_vec(26,0);
		for ( int i = 0; i < it->size(); i++)
			str_vec[ (*it).at(i)- 'a']++;
		if ( myset.find(str_vec) == myset.end())
			myset.insert(str_vec);
		else
			flag[it - strs.begin()] = true;
	}
	myset.clear();
	for ( auto it = strs.end() - 1; it != strs.begin() -1; it--)
	{
		vector<int> str_vec(26,0);
		for ( int i = 0; i < it->size(); i++)
			str_vec[ (*it).at(i)- 'a']++;
		if ( myset.find(str_vec) == myset.end())
			myset.insert(str_vec);
		else
			flag[it - strs.begin()] = true;
	}

	vector<string> result;
	for ( auto it = strs.begin(); it !=strs.end(); it++)
	{
		if ( flag[it - strs.begin()] == true)
			result.push_back(*it);
	}

        return result;
}
};
