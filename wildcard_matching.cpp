class Solution {
public:

bool match(const char *s, int i, const char *p,int j )
{
	if (i >= len1 || j >= len2 )
		return false;
	char p1 = p[j];
	if( p1  == '\0')
	{
		if (s[i] == '\0')
			return true;
		else
			return false;
	}
	if (p1 == '?')
		return match(s,i+1,p,j+1);
	if (p[j] == '*')	
		return ( match(s,i,p,j+1) || match(s,i,p,j+1) || match(s,i+1,p,j+1) );
	else 
	{
		if (s[i] == p[j])
			return  match(s,i+1,p,j+1) ;
	 	return false;
	}
	return false;
}
bool isMatch(const char *s, const char *p) 
{
	for( len1 = 0; s[len1]!='\0';len1++);
	for( len2 = 0; p[len2]!='\0';len2++);
	return match(s,0,p,0);       
}
private:
	int len1,len2;
};
