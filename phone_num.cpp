class Solution {
public:
void probe( string digits, string str, int pos )
{
   	 int i;

	if (digits.size() == pos)
	{
		result.push_back(str);
		return;
	}
	for(i = 0; i < 4; i++)
	{
		if (i == 3 && (digits.at(pos)- '0') != 7 && (digits.at(pos)-'0') != 9)
			continue;
		string neo_str;
		neo_str = str;
		neo_str.push_back(convert[digits.at(pos)-'0'][i]);
		probe(digits, neo_str,pos + 1);
	}
	return;

}

vector<string> letterCombinations(string digits) 
{
	string  str;
	convert[0] = "err";
	convert[1] = "err";
	convert[2] = "abc";
	convert[3] = "def";
	convert[4] = "ghi";
	convert[5] = "jkl";
	convert[6] = "mno";
	convert[7] = "pqrs";
	convert[8] = "tuv";
	convert[9] = "wxyz";
	probe(digits,str,0); 
	return result;
}

private:
	vector<string>  result;    
	string convert[10];
};

