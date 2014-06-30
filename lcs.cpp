class Solution {
public:
int longestConsecutive(vector<int> &num) 
{
	unordered_map<int,int> mymap;
	for(int i = 0; i < num.size(); i++)
	{
		auto it = mymap.find(num[i] - 1);
		if (it != mymap.end())
		{
			int times = (*it).second;
			mymap.erase(it);
			mymap.insert({num[i],times+1});
		}
		else
			mymap.insert({num[i],1});
	}       
	int max = 0;
	for ( auto it = mymap.begin(); it != mymap.end(); it ++ )
		if ((*it).second > max )
			max = (*it).second;
	return max;
}
};
