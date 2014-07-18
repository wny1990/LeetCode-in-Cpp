class Solution {
public:
bool nine(vector<vector<char> > &board, int a, int b)
{
 	int i,j; 
	unordered_set<int> num;
	for( i = a; i < a + 3 ; i++)       
	{
		for( j = b; j < b + 3 ; j++)       
		{
			if (board.at(i).at(j) == '.')
				continue;
			if (num.find(board.at(i).at(j))!=num.end())
				return false;
			num.insert(board.at(i).at(j));
		}
	}
	return true;
}
bool isValidSudoku(vector<vector<char> > &board) 
{
	int i,j;
	for( i = 0; i < 9 ; i++)       
	{
		unordered_set<int> num;
		for( j = 0; j < 9 ; j++)       
		{
			if (board.at(i).at(j) == '.')
				continue;
			if (num.find(board.at(i).at(j))!=num.end())
				return false;
			num.insert(board.at(i).at(j));
		}
	}

	for( i = 0; i < 9 ; i++)       
	{
		unordered_set<int> num;
		for( j = 0; j < 9 ; j++)       
		{
			if (board.at(j).at(i) == '.')
				continue;
			if (num.find(board.at(j).at(i))!=num.end())
				return false;
			num.insert(board.at(j).at(i));
		}
	}

	return( nine(board,0,0) && nine(board,0,3) && nine(board,0,6) && nine(board,3,0) && nine(board,3,3) && nine(board,3,6) && nine(board,6,0) && nine(board,6,3) && nine(board,6,6));
}

};
