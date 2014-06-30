#include <iostream>
using namespace std;
int get_digit(int x, int d)
{
	if (d == 1) return x % 10;
	for(int i = 1; i < d; i ++)
		x = x/ 10;
	return x % 10;
}
bool isPalindrome(int x) 
{
	if(x < 0) return false;
	if( x < 10 ) return true;
	int width = 0;
	while ( x )
	{
		x = x /10;
		width ++;
	} 
	//cout << "width" << width <<endl;      
	int i = width;
	int j = 1;
	cout << get_digit(x,2) << endl;
	cout << get_digit(x,1) << endl;
	while ( i > j)
	{
		if (get_digit(x,i) != get_digit(x,j))
			return false;
		i --;
		j ++;
	}
	
	return true;
}
int main()
{
	cout << isPalindrome(10) << endl;
}
