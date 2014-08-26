class Solution {
public:
    int unique(int m, int n) {
     if(m ==1 || n == 1)  return 1;
     int sum =  m + n - 2;
     int i;
     int min ;
     if (m>n) min = n-1; else min = m-1;
    long long result = 1;
    for(int i = sum; i > sum - min; i--)
        result = result * i;
    for(int i = 1; i<= min; i++)
        result = result / i;
        return result;
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
	int total = unique(m,n);
	vector<int,int> obs;
	for(int i = 0 ; i <m 
   }
};
