    int reverse(int x) {
     	vector<int> digits;
	int num = x;
	while(num)
	{
		digits.push_back(num%10);
		num = num / 10;
	}
	bool pre_zero = true;
	int sum = 0;
	vector<int>::iterator ii;
	for(ii = digits.begin(); ii!=digits.end();ii++)
	{
		if(pre_zero && *ii == 0)
		{
		   continue;
		}
		else
		{
		   pre_zero = false;;
		   sum = sum * 10;
		   sum += *ii;
		}
	}
	return sum;
    }
