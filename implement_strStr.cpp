class Solution {
public:
char *strStr(char *haystack, char *needle) 
{
	char *s1 = haystack;        
	char *s2 = needle;        
	int size1,size2;
	int i;
	for ( i = 0; s1[i]!='\0';i++);
	size1 = i;
	for ( i = 0; s2[i]!='\0';i++);
	size2 = i;
	if ( size2 == 0 ) 
		return haystack;
	if (size2 > size1)
		return NULL;
	for ( i = 0;  i < size1 - size2 + 1;i++)
	{
		int j = 0;
		while ( s2[j] !='\0'  && s1[j+i] == s2[j])
			j++;
		if ( s2[j] == '\0')
		{
			return haystack + i;
		}
	}
	return NULL;
}
};
