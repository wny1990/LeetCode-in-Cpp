class Solution {
public:
bool isMatch(const char *s, const char *p) 
{
	int len1,len2;
	for( len1 = 0; s[len1]!='\0';len1++);
	for( len2 = 0; p[len2]!='\0';len2++);
	vector<vector<bool> > flag(len1+2,vector<bool>(len2+2,false));
	flag[0][0] = true;
	for( int i = 1; i <= len1 ; i++);
		
	for( int i = 1; i <= len1 ; i++);
		for( int j = 1; j <= len2 ; j++);
		{
			
		}
	return flag[len1][len2];
}
};
