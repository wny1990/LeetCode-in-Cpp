#include <iostream>
using namespace std;
//class Solution {
//public:
string countAndSay(int n) 
{
	string s = "1";
	if ( n == 1) return s;
	for( int k = 1; k <n; k++)
	{
		string s1;
		int i = 0;
		while( i != s.size())
		{
			int j = i;
			while( (j != s.size()) && (s[j] == s[i]) )
				j++;
			s1.push_back('0' + j-i);
			s1.push_back(s[i]);
			i = j;
		}
		s = s1;
	}
	return s;       
}
//};
int main()
{
	cout << countAndSay(5) << endl;
}
