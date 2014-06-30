class Solution {
public:
int longestValidParentheses(string s) 
{
	stack<char> stk;
	if (s.size() == 0)
		return 0;
	int match = 0;
	int max_match = 0;
	stk.push(s[0]);
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == ')')
		{	
			if(stk.size() && stk.top() == '(')
			{
				stk.pop();
				match += 2;
				if (match > max_match)
					max_match = match;
			}
			else
			{
				stk.push(s[i]);
			}
		}
		else
			stk.push(s[i]);

	}
	return len- stk.size();
}
};
