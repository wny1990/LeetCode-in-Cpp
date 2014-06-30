class Solution {
public:
string convert(int num)
{
	switch(num)
	{
		case 0:	return "zero";
		case 1: return "I";
		case 2: return "II";
		case 3: return "III";
		case 4: return "IV";
		case 5: return "V";
		case 6: return "VI";
		case 7: return "VII";
		case 8: return "VIII";
		case 9: return "IX"
		default: return "error";
	}

	return "error";

}
string intToRoman(int num) 
{
	stack<string> stk;
	string result;
 	if (num / 1000 !=0)
	{
		for (int i = 0 ; i < num/1000; i++)
		result.append("M");
		num = num % 1000;
	}

 	if (num / 100 !=0)
	{
		for (int i = 0 ; i < num/100; i++)
		result.append("C");
		num = num % 100;
	}

	while ( num )
	{
		int digit = num %  10;
		stk.push(convert(digit));
		num = num /10;
	}      
	while(stk.size())
	{
		result.append(stk.top());
		stk.pop();
	}
	return result;
}
};
