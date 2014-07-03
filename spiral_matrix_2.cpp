class Solution {
public:
vector<vector<int> > generateMatrix(int n)
{
	vector<vector<int> > matrix;
	if ( n == 0) return matrix;
	if ( n == 1) {
		vector<int> row;
		matrix.push_back(row);
		matrix.at(0).push_back(1);
		return matrix;
	}
	for( int i = 0 ; i < n; i++)
	{
		vector<int> row;
		row.assign(n,0);
		matrix.push_back(row);	
	}
	string status = "right";
	int count = 0;
	int px = 0;
	int py = 0;
 	int p1x = 0,p1y = 1;
 	int p2x = n - 1,p2y = 0;
 	int p3x= n - 1,p3y = n - 1;
 	int p4x = 0, p4y = n -1;
	while( count < n*n)
	{
		matrix.at(py).at(px) = count + 1;
		count ++ ;
		if (px == p1x && py ==p1y && status == "up" )
		{
			px++;
			status = "right";
			p1x++;
			p1y++;	
		}
		else if (px == p2x && py ==p2y && status == "right")
		{
			py++;
			status = "down";
			p2x--;
			p2y++;
		}
		else if (px == p3x && py ==p3y && status == "down")
		
		{
			px--;
			status = "left";
			p3x--;
			p3y--;
		}
	
		else if (px == p4x && py ==p4y && status == "left")
		{
			py--;
			status = "up";
			p4x++;
			p4y--;
		}

		else if ( status == "left")
			px--;
		else if ( status == "right")
			px++;
		else if ( status == "up")
			py--;
		else if ( status == "down")
			py++;
	}
    
	return matrix;
}
};
