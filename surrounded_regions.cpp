class Solution {
public:
void probe(vector<vector<char>> &board,vector<vector<bool> > &alive,int y0,int x0)
{
	stack<pair<int,int>> stk;
	stk.push( {y0,x0});
	while( stk.size())
	{
		int x = stk.top().second;
		int y = stk.top().first;
		stk.pop();
		alive[y][x] = true;
		if ( x - 1 >=0 && board[y][x-1] == 'O' && !alive[y][x-1])
			stk.push( {y,x-1});

		if ( x + 1 < board.at(0).size() &&  board[y][x+1] == 'O'  && !alive[y][x+1] )
			stk.push( {y,x+1});

		if ( y + 1 < board.size() && board[y+1][x] == 'O' && !alive[y+1][x] )
			stk.push( {y+1,x});

		if ( y - 1 >= 0 && board[y-1][x] == 'O' && !alive[y-1][x] )
			stk.push( {y-1,x});
	}
	return;
}
void solve(vector<vector<char>> &board)
{
 	int n = board.size();
	if ( n == 0 )     
		return;
	int m = board.at(0).size();
	vector<vector<bool>> alive(n,vector<bool>(m,false));

	for( int i = 0 ; i < n; i++ )
			if ( board[i][0] == 'O' && !alive[i][0])
			{
				probe(board,alive,i,0);
			}

	for( int i = 0 ; i < n; i++ )
			if ( board[i][m-1] == 'O' && !alive[i][m-1])
			{
				probe(board,alive,i,m-1);
			}

	for( int i = 0 ; i < m; i++ )
			if ( board[0][i] == 'O'&& !alive[0][i])
			{
				probe(board,alive,0,i);
			}

	for( int i = 0 ; i < m; i++ )
			if ( board[n-1][i] == 'O' && !alive[n-1][i])
			{
				probe(board,alive,n-1,i);
			}



	for( int i = 0 ; i < n; i++ )
		for( int j = 0 ; j < m; j++ )
		{
			if ( board[i][j] == 'O' && !alive[i][j])
				board[i][j] = 'X';
		}

	return;
}
};
