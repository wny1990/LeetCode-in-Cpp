#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int lengthOfLastWord(const char *s)
{
	int i,start = -1,endp;   
	bool space = true;    
	if (s[0] == '\0' ) return 0;
	for(i = 0; s[i]!='\0';i++)
	{
		if (space == true && s[i] != ' ')
			start = i;
		
		if (space == false && s[i] == ' ')
			endp = i;
		if (s[i] == ' ')
			space = true;
		else
			space = false;
	}
	if (s[i-1] != ' ') endp = i;
	if (start == -1 ) return 0;
	else return (endp- start);
}

int main()
{
	char* in;
	int out;
	in = " dasdsadoddd 1s990";
//	in = "a ";
	out = lengthOfLastWord(in);
	cout << out <<endl;
	return 0;
}
