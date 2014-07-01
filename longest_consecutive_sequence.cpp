class Solution {
public:
void merge();
void 
int longestConsecutive(vector<int> &num) 
{
	unordered_map<int,int> mymap;
	int pool = 0;
	vector<int> count(num.size(),0);
	for( int i = 0; i < num.size(); i++ )
	{
		if (mymap.find(num[i]) != mymap.end())
			continue;
		int left = -1, right = -1;
		if (mymap.find(num[i] - 1) != mymap.end())
	        	left = (mymap.find(num[i] - 1))->second;
		if (mymap.find(num[i] + 1) != mymap.end())
	        	right = (mymap.find(num[i] + 1))->second;
		if (left == -1 && right == -1)
		{
			mymap.insert({num[i],pool});
			count[pool++]++;
		}
		if (left != -1 && right == -1)
		{
			mymap.insert({num[i],left});
			count[left]++;
		}
		if (left == -1 && right != -1)
		{
			mymap.insert({num[i],right});
			count[right]++;
		}
		if (left != -1 && right != -1)
		{
			mymap.insert({num[i],right});
			count[right]++;
		}


	}
}
};
