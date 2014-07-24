#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//class Solution {
//public:
int longestValidParentheses(string s)
{
	int n = s.size();
	if ( n == 0 ) return 0;
	stack<int> stk;
	vector<bool> match(n,false);
	for ( int i = 0; i < n; i ++ )
	{
		if ( s[i] == ')' &&  stk.size() && s[stk.top()]== '(')
		{
			match[stk.top()] = true;
			match[i] = true;
			stk.pop();	
		}
		else if (s[i] == '(')
			stk.push(i);
	}
	int longest = 0;		
	int width = 0;		
	for ( int i = 0; i < n; i ++ )
	{
		if (match[i])
			width++;
		else
			width = 0;
		if (width > longest)
			longest = width;
	}
return longest;
}
//};
int main()
{
	cout << longestValidParentheses(")(((((()())()()))()(()))(" ) << endl;


}
