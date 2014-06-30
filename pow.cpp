class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
	if (x == 1) return 1;
		if (x == -1) return 1-2*(n%2);
        double result = x;
        for(long i = 1; i < abs(n); i ++ )
        {
		   result *= x;
		   if (result == 0) return 0;
	} 
      	 if(n < 0) result = 1 / result;
        return result;
    }
};
