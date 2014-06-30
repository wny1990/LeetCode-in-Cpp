
class Solution {
public:
void probe(string &s, vector<vector<bool> > &inDic, int size,int start,string str)
{
// if we have finished the partition, add the vector to result.
	if ( start == size)
	{
		result.push_back(str);
		return;
	}

	for( int i = start; i < size; i++)
		if ( inDic[start][i] )
		{
			string str1 = str;
			if (str1.size()) str.push_back(' ');
			str1.append( (s.substr(start, i-start+1)) );
			probe(s,inDic,size,i+1,str1);
		}
	return;
}

vector<string> wordBreak(string s, unordered_set<string> &dict)
{
	int n = s.size();
	if (n == 0) return result;
// initialize the bool matrix
       	vector<vector<bool> > inDic(n,vector<bool>(n,false));
// calculate the bool matrix
	for ( int i = 0; i < n; i++ )
		for ( int j = i; j < n; j++ )
		{
			if ( dict.find(s.substr(i,j-i+1) )!= dict.end())
				inDic[i][j] = true;
		}
	
	string str;
// do dfs on the partition recursively
	probe(s,inDic,n,0,str);

	return result;
}
private:
	vector<string> result;
};
