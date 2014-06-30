    int maxSubArray(int A[], int n) {
      int sum[n];
      if (n == 1) return A[0];
      sum[0] = A[0];
      for(int i = 1; i < n; i++)
	sum[i] = sum [i-1] + A[i];
      int max = INT_MIN;
      int lowest = 0;
      for(int i = 0; i < n; i++)
      {
	    if (sum[i] - lowest > max ) max = sum[i] - lowest;
	    if (sum[i] < lowest) lowest = sum[i];
      }
      return max;
    }
