class Solution {
public:
bool isValid(string s)
{
	stack<char> stk;
	if (s.size() == 0)
		return true;
	if (s[0] == ')'|| s[0] == '}' || s[0] == ']')
		return false;
	stk.push(s[0]);
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == ')')
		{	
			if(stk.size() && stk.top() == '(')
				stk.pop();
			else
				return false;
		}
		else if(s[i] == ']')
		{
			if(stk.size() &&stk.top() == '[')
				stk.pop();
			else
				return false;
		
		}
		else if(s[i] == '}')
		{
			if(stk.size() && stk.top() == '{')
				stk.pop();
			else
				return false;
		}
		else
			stk.push(s[i]);

	}
	if (stk.size())
		return false;
	else
		return true;
}
};
