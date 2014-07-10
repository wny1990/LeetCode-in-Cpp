class Solution {
public:
int longestConsecutive(vector<int> &num) 
{
	unordered_map<int,int> mymap;
	unordered_map<int,int> degree;
	for( int i = 0; i < num.size(); i++ )
	{
		if (mymap.count(num[i]) )
			continue;
		mymap[num[i]] = num[i];
		degree[num[i]] = 1;
		if (mymap.count(num[i] + 1) )
		{
			int k = num[i] + 1;
			while( mymap[k] != k)
				k = mymap[k];
			mymap[num[i]] = k;
			degree[k]++;
		}
		if (mymap.count(num[i] - 1 ))
		{
			int k = num[i] - 1;
			while( mymap[k] != k)
				k = mymap[k];
			int k1 = num[i];
			while( mymap[k1] != k1)
				k1 = mymap[k1];
			mymap[k] = k1;
			degree[k1]+= degree[k];
		}
	}
	int max = 0;	
	for( int i = 0; i < num.size(); i++ )
	{
		if ( degree[num[i]] > max)
			max = degree[num[i]];
			
	}
	return max;
}
};
