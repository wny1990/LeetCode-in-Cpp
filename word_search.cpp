class Solution {
public:
bool probe(vector<vector<char> > &board,vector<vector<bool> > &visited,string word,int x,int y,int len)
{

	if (len == word.size() - 1)
		return true;
	visited[y][x] = true;
	bool up = false,left = false,right =false, down = false;
	if ( x - 1 >=0 && word[len + 1] == board[y][x-1] && !visited[y][x-1])
	{
		left = probe(board,visited,word,x-1,y,len+1);
		visited[y][x-1] = false;
		if (left) return true;
	}
	if ( x + 1 < board.at(0).size() && word[len + 1] == board[y][x+1] && !visited[y][x+1] )
	{
		right = probe(board,visited,word,x+1,y,len+1);
		visited[y][x+1] = false;
		if (right) return true;

	}
	if ( y + 1 < board.size() && word[len + 1] == board[y+1][x] && !visited[y+1][x] )
	{
		down = probe(board,visited,word,x,y+1,len+1);
		visited[y+1][x] = false;
		if (down) return true;
	}
	if ( y - 1 >= 0 && word[len + 1] == board[y-1][x] && !visited[y-1][x] )
	{
		up = probe(board,visited,word,x,y-1,len+1);
		visited[y-1][x] = false;
		if (up) return true;
	}
	return false;
}
bool exist(vector<vector<char> > &board, string word) 
{
 	int n = board.size();
	if ( n == 0 )     
		return false;
	int m = board.at(0).size();
	for( int i = 0 ; i < n; i++ )
		for( int j = 0 ; j < m; j++ )
		{
			if (word[0] != board[i][j])
				continue;
			vector<vector<bool> > visited(n,vector<bool>(m,false));
			if( probe(board,visited,word,j,i,0))
				return true;
		}
	return false;
}
};
