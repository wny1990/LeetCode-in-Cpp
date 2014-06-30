class Solution {
public:
int diff(string a, string  b)
{
	int diff = 0;
	for (int i = 0; i < a.size();i++)
		if (a[i]!=b[i])
			diff++;
	return diff;

}
int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	int len[dict.size()];       
	vector<string> dictv;

	for (auto i = dict.begin(); i != dict.size();i++)
		dictv.push_back(*i);

	for (int i = 0; i < dict.size();i++)
		len[i] = -1;

	for (auto it = dictv.begin(); it != dictv.end();it++)
	{
		int sdiff = diff(start,*it);
		if (sdiff == 1)
			len[it-dictv.begin()] = sdiff;
	}
	for ( int count =0; count < start.size();count++)
	for (auto i = dictv.begin(); i != dictv.end();i++)
	{
		if (len[i - dictv.begin()] == -1) continue;
		for (auto j = dictv.begin(); j != dictv.end();j++)
		{
			if (i == j) continue;
			int sdiff = diff(*i,*j);
			if (sdiff == 1 && len[j-dictv.begin()] == -1 )	
				len[j-dictv.begin()] = len[i-dictv.begin()] + 1;
		}
	}
	int min = INT_MAX;
	for (auto i = dictv.begin(); i != dictv.end();i++)
	{
		if (len[i - dictv.begin()] == -1) continue;
		int sdiff = diff(*i,end);
		if (sdiff < min) 
			min = sdiff;
	}
	return min;
}
};
