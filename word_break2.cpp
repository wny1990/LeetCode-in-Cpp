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
			if (str1.size()) str1.push_back(' ');
			str1.append((s.substr(start, i-start+1)) );
			probe(s,inDic,size,i+1,str1);
		}
	return;
}

bool valid_end(  vector<vector<bool> > &inDic, int n)
{
	for( int i = 0; i < n; i++)
		if ( inDic[i][n-1] == true)
			return true;
	return false;

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

/*	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		int size = (*it).size();
		for( int i = 0; i + size - 1 < n; i ++)
			if (s.substr(i,size) == *it )
				inDic[i][i+size-1] = true;
	}	
*/
	string str;

	if ( inDic.at(0) == vector<bool>(n,false))
		return result;
	if ( !valid_end(inDic,n))
		return result;
// do dfs on the partition recursively
	probe(s,inDic,n,0,str);

	return result;
}
private:
	vector<string> result;
};
