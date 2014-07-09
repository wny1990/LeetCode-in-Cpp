class Solution{
public:
string longestCommonPrefix(vector<string> &strs)
{
	int min = INT_MAX;
	vector<string>::iterator ii;
	for(ii = strs.begin(); ii != strs.end(); ii++ )
		if((*ii).size() < min)
			min = (*ii).size(); 
	string result = "";
	if(min == 0|| min == INT_MAX )
		return result;
	for(int i = 0; i < min ; i++)
	{
		int same = true;
		char c0 = (strs.at(0)).at(i);
		for(int j = 1; j < strs.size() ; j++)
			if ( (strs.at(j)).at(i)	!= c0)
				same = false;
		if (same == false) 
				return (strs.at(0)).substr(0,i);
	}
	return (strs.at(0)).substr(0,min);
}   

};
