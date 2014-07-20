#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
bool isMatch(const char *s, const char *p) 
{
	int len1,len2;
	for( len1 = 0; s[len1]!='\0';len1++);
	for( len2 = 0; p[len2]!='\0';len2++);
	vector<bool > match(len2,false);
	match0[0] = true;
	for( int j = 1; j <= len2 ; j++)
	{
		bool valid = false;
		for( int i = 1; i <= len1 ; i++)
		{
			if (match0[j-1] && ( p[j] == '?' || p[j] == '*' || s[i] == p[j]) )
			{
				match[j] = true;
				valid = true;
			}
			if ( (match[j-1] || match0[j] )&&  p[j] == '*'  )
			{
				match[j] = true;
				valid = true;
			}
		}
			if (!valid) return false;
			match0 = match;
	}
	return match[len2];
}
//};
int main()
{

	cout << isMatch("abcff","a?c*") << endl;
}
