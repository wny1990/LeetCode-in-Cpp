#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;
string simplifyPath(string path)
{
	stack<string> path_stack;
	string result;
	if( path[path.size() - 1] != '/')
		path.push_back('/');
	int i = 0;

	while( path[i] == '/')
		i ++;
	
	if (path[i]=='\0') path_stack.push("/");

	while(path[i]!='\0')
	{
		int j = i + 1;
		while( path[j]!='\0' && path[j]!='/')
			j++;
		string s = path.substr(i,j - i);
		if (s ==".." && path_stack.size())
			path_stack.pop();
		else if (s!="." && s!="..")
			path_stack.push("/"+s);
		j++;	
		while(path[j] == '/')
		    j++;
		 i = j;
	  
	}
	stack<string> r_path;
	while( path_stack.size())
	{
		r_path.push(path_stack.top());
		path_stack.pop();
	}

	
	while( r_path.size())
	{
		result.append(r_path.top());
		r_path.pop();
	}
	return result;
}
main()
{
string in,out;
in = "/wny/./dasdsa/dd";
out = simplifyPath(in);
cout << out <<endl;
}
