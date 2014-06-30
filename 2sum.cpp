#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) 
{

	vector<int> two_num,numbers1;
	vector<int>::iterator ii,jj,kk;
	numbers1 = numbers;
        sort(numbers1.begin(),numbers1.end());
	ii = numbers1.begin();
	jj = numbers1.end() - 1;
	while(1)
	{
		if(*ii + *jj < target)
			ii++;
		else if(*ii + *jj > target)
			jj--;
		else
		{
			for(kk = numbers.begin(); kk!= numbers.end(); kk++)
				if (*kk == *ii || *kk == *jj )
					two_num.push_back(1+ kk-numbers.begin());
			return two_num;
		}
	
	}
	return two_num;
	
}
int main()
{
	vector<int> numbers;
	vector<int> two;
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(11);
	numbers.push_back(5);
	two = twoSum(numbers,9);
	vector<int>::iterator ii;
	for(ii = two.begin(); ii!= two.end(); ii++)
		cout << *ii << endl;
	return 0;
}
