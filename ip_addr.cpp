class Solution {
public:
void probe(vector<int> v0,int p)
{
	
	vector<int> v1 = v0;
	v1.push_back(p);

	if (v1.size() == len && p == range)
		result.push_back(v1);

	if (v0.size() == len && p == range)
		result.push_back(v0);

	if ( (p+1) <= range )
	{
		probe(v0,p+1);
		probe(v1,p+1);
	}
	return;
}

vector<string> restoreIpAddresses(string s)
{
	len = k;
	range = n;
	if (len == 0) return result;
	vector<int> v0;
	probe(v0, 1);
	return result;
        
}
private:
	vector<vector<int> > result;
	int len,range;

};
