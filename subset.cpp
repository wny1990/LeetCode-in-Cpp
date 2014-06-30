class Solution {
public:
void probe(vector<int> &S, vector<int> v0,int p)
{
	
	vector<int> v1 = v0;
	v1.push_back(S.at(p));
	if (p == len -1)
	{
		result.push_back(v0);
		result.push_back(v1);
	}
	else
	{
		probe(S,v0,p+1);
		probe(S,v1,p+1);
	}
}


vector<vector<int> > subsets(vector<int> &S)
{
	len = S.size();
	if (len == 0) return result;
	sort(S.begin(),S.end());
	vector<int> v0;
	probe(S,v0, 0);
	return result;
        
}
private:
	vector<vector<int> > result;
	int len;

};
