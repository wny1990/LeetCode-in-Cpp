#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
bool isMatch(const char *s, const char *p) 
{
	int len1,len2;
	int non_star = 0;
	for( len1 = 0; s[len1]!='\0';len1++);
	for( len2 = 0; p[len2]!='\0';len2++)
		if (p[len2] != '*')
			non_star++;
	if (non_star > len1 )
		return false;
	if (len1 == 0 )
		if (non_star == 0)
			return true;
		else
			return false;
	vector<bool > match0(len2 + 1,false);
	vector<bool > match(len2 + 1,false);
	match0[0] = true;
	for( int j = 1; j <= len2 ; j++)
		if (match0[j-1] == true && p[j-1] == '*' )
			match0[j] = true;
	for( int i =1; i <= len1 ; i++)
	{
		bool valid = false;
		for( int j = 1; j <= len2 ; j++)
		{
			if (match0[j-1] && ( p[j-1] == '?' || p[j-1] == '*' || s[i-1] == p[j-1]) )
			{
				match[j] = true;
				valid = true;
			}
			else if ( ( match0[j] || (j-1 >= 0 &&  match[j-1]) ) &&  p[j-1] == '*'  )
			{
				match[j] = true;
				valid = true;
			}
			else match[j] = false;
		}
		if (!valid) return false;
		match0 = match;
	}
	return match[len2];
}
//};
int main()
{

	cout << isMatch("c","*a") << endl;
}
