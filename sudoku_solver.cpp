#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//class Solution {
//public:
bool solve( vector<vector<char> > &board, vector< unordered_set<int> > &row, vector< unordered_set<int> > &col,  vector< unordered_set<int> > &region,int num)
{
	if (num > 80 )
		return true;
	int num1 = num + 1;

	while ( num1 < 81 && board[num1/9][num1%9] != '.')
		num1++;

	for ( int i= 1; i <= 9; i++)
	{
		if (row[num/9].count(i) && col[num%9].count(i) && region[3*(num/27) + (num%9)/3].count(i))
		{
			board[num/9][num%9] = '0' + i;
			row[num/9].erase(i);
			col[num%9].erase(i);
			region[3*(num/27) + (num%9)/3].erase(i);
			bool find = solve(board,row,col,region,num1);
			if (find)
				return true;
			region[3*(num/27) + (num%9)/3].insert(i);
			row[num/9].insert(i);
			col[num%9].insert(i);
			board[num/9][num%9] = '.';
		}
					
	}
	return false;
}
void solveSudoku(vector<vector<char> > &board) 
{       
	vector< unordered_set<int> > row(9);
	vector< unordered_set<int> > col(9);
	vector< unordered_set<int> > region(9);
	for( int i = 0; i < 9; i++)
		for( int j = 1; j <= 9; j++)
		{
			row[i].insert(j);
			col[i].insert(j);
			region[i].insert(j);
		}

	for( int i = 0; i < 9; i++)
		for( int j = 0; j < 9; j++)
			if (board[i][j] != '.')
			{
				if( row[i].count(board[i][j] -  '0'))
					row[i].erase(board[i][j] - '0');
				if( col[j].count(board[i][j]-'0'))
					col[j].erase(board[i][j]-'0');
				if( region[3*(i/3) + j/3].count(board[i][j]-'0'))
					region[3*(i/3) + j/3].erase(board[i][j]-'0');
			}
	int start = 0;
	for(start = 0; start < 81; start++)
		if (board[start/9][start%9] == '.')
			break;
	solve(board,row,col,region,start);
	return;
}
//};
int main()
{
	vector<vector<char> > board(9,vector<char>(9,'.'));
	solveSudoku(board);
	for( int i = 0; i < 9; i++)
	{
		for( int j = 0; j < 9; j++)
			cout << board[i][j] << "  ";
		cout << endl;
	}
}
