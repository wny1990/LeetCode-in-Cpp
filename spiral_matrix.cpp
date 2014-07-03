class Solution {
public:
vector<int> spiralOrder(vector<vector<int> > &matrix) 
{
	vector<int> result;
	int m = matrix.size();
	if (!m) return result;
	int n = matrix.at(0).size();
	if (!n) return result;
	if ( m == 1) return matrix.at(0);
	if ( n == 1) {
		for (int i =0; i < m; i++)
			result.push_back(matrix.at(i).at(0));
		return result;
	}
	string status = "right";
	int count = 0;
	int px = 0;
	int py = 0;
 	int p1x = 0,p1y = 1;
 	int p2x = n - 1,p2y = 0;
 	int p3x= n - 1,p3y = m - 1;
 	int p4x = 0, p4y = m -1;
	while( count < m*n)
	{
		result.push_back(matrix.at(py).at(px));
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
    
	return result;
}
};
