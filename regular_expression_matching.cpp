class Solution {
public:

bool match(const char *s, int i, const char *p,int j, vector<vector<bool> > &flag)
{
	int len1 = flag.size();
	int len2 = flag.at(0).size();
	if (i >= len1 || j >= len2 )
		return false;
	if (flag[i][j])
		return false;
	flag[i][j] = true;
	char p1 = p[j];
	if( p1  == '\0')
	{
		if (s[i] == '\0')
			return true;
		else
			return false;
	}
	if (p1 == '.')
	{
		if(p[j+1] == '*')
			return ( match(s,i+1,p,j+2,flag) ||  match(s,i,p,j+2,flag)||  match(s,i+1,p,j,flag) );
		return match(s,i+1,p,j+1,flag);
	}
	// p[j] == some character
	if (p[j+1] != '*')	
	{
		if (s[i] != p[j])
			return false;
		return match(s,i+1,p,j+1,flag);
	}
	else if ( p[j+1] == '*')
	{
		if (s[i] == p[j])
			return ( match(s,i+1,p,j+2,flag) ||  match(s,i,p,j+2,flag)||  match(s,i+1,p,j,flag) );
	 	return match(s,i,p,j+2,flag);
	}
	return false;
}
bool isMatch(const char *s, const char *p) 
{
	int len1,len2;
	for( len1 = 0; s[len1]!='\0';len1++);
	for( len2 = 0; p[len2]!='\0';len2++);
	vector<vector<bool> > flag(len1+1,vector<bool>(len2+1,false));
	return match(s,0,p,0,flag);       
}

};
