class Solution {
public:
string intToRoman(int num) 
{
	stack<string> stk;
	string result;
 	if (num / 1000 !=0)
	{
		for (int i = 0 ; i < num/1000; i++)
			result.push_back('M');
		num = num % 1000;
	}

 	if (num / 100 !=0)
	{
		int k = num/100;
		if( k == 9 )
			result.append("CM");
		else if( k == 4)
			result.append("CD");
		else	
		{	
			if( k >= 5 )
			{
				result.push_back('D');
				k = k  - 5;
			}
			for (int i = 0 ; i < k; i++)
				result.push_back('C');
		}
		num = num % 100;
	}

 	if (num / 10 !=0)
	{
		int k = num/10;
		if( k == 9 )
			result.append("XC");
		else if( k == 4)
			result.append("XL");
		else	
		{	
			if( k >= 5 )
			{
				result.push_back('L');
				k = k  - 5;
			}
			for (int i = 0 ; i < k; i++)
				result.push_back('X');
		}
		num = num % 10;
	}

	if (num)
	{
		if( num == 9 )
			result.append("IX");
		else if( num == 4)
			result.append("IV");
		else	
		{	
			if( num >= 5 )
			{
				result.push_back('V');
				num = num  - 5;
			}
			for (int i = 0 ; i < num; i++)
				result.push_back('I');
		}
	}
	return result;
}
};
