class Solution {
public:
void match(string s, unordered_set<string> &dict,int visited[],int start)
{
    	visited[start] == 1;
	if ( s[start] == '\n')
	{
		wbreak = true;
		return;
	}
	for(int i = start; s[i] != '\0'; i++)
	{
    	if ( visited[i] == 0) 
		if(  dict.find(s.substr(start,i - start + 1)) != dict.end() )
			match(s,dict,visited,i+1);
	}
	return;
}
bool wordBreak(string s, unordered_set<string> &dict)
{
    	int*  visited  = new bool[s.size()+1]();
        wbreak = false;
        match(s,dict,visited,0);
       return wbreak;
}

private:
	bool wbreak;
};
